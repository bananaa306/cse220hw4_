#include "cse_caesar.h"
#include "strgPtr.h"
/* DO NOT use <string.h> or <ctype.h> */

int encryptCaesar(const char *plaintext, char *ciphertext, int key) {
    const char marker[] = "__EOM__";
    int marker_len = 7;
    if (plaintext == NULL || ciphertext == NULL) {
        return -2;
    }
    if (strgLen(ciphertext) < marker_len) {
        return -1;
    }
    int max_payload = strgLen(ciphertext) - marker_len;
    int encoded = 0;
    while (plaintext[encoded] != '\0' && encoded < max_payload) {
        char c = plaintext[encoded];
        int shift = key + encoded;
        if (c >= 'a' && c <= 'z') {
            int off = (c - 'a' + shift) % 26;
            if (off < 0) {
                off += 26;
            }
            ciphertext[encoded] = (char)('a' + off);
        } else if (c >= 'A' && c <= 'Z') {
            int off = (c - 'A' + shift) % 26;
            if (off < 0) {
                off += 26;
            }
            ciphertext[encoded] = (char)('A' + off);
        } else {
            ciphertext[encoded] = c;
        }
        encoded++;
    }
    for (int i = 0; i < marker_len; i++) {
        ciphertext[encoded + i] = marker[i];
    }
    ciphertext[encoded + marker_len] = '\0';
    return encoded;
}

int decryptCaesar(const char *ciphertext, char *plaintext, int key) {
    const char marker[] = "__EOM__";
    int marker_len = 7;
    if (ciphertext == NULL || plaintext == NULL) {
        return -2;
    }
    int i = 0;
    while (ciphertext[i] != '\0') {
        int is_marker = 1;
        for (int j = 0; j < marker_len; j++) {
            if (ciphertext[i + j] == '\0' || ciphertext[i + j] != marker[j]) {
                is_marker = 0;
                break;
            }
        }
        if (is_marker) {
            plaintext[i] = '\0';
            return i;
        }
        char c = ciphertext[i];
        int shift = key + i;
        if (c >= 'a' && c <= 'z') {
 
            int off = (c - 'a' - shift) % 26;
            if (off < 0) {
                off += 26;
            }
            plaintext[i] = (char)('a' + off);
        } else if (c >= 'A' && c <= 'Z') {
            int off = (c - 'A' - shift) % 26;
            if (off < 0) {
                off += 26;
            }
            plaintext[i] = (char)('A' + off);
        } else {
            plaintext[i] = c;
        }
        i++;
    }
    return -1;
}
