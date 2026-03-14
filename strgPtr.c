#include "strgPtr.h"
/* DO NOT use <string.h> or <ctype.h> */

int strgLen(const char *s) {
    (void)s;
    /* TODO */
    size_t count=0;
    if(s == NULL)
    {
        return -1;
    }
    for(int i=0; s[i]!=NULL;i++)
    {
        count++;
    }
    return count;
}

void strgCopy(const char *source, char *destination, size_t size) {
    (void)source;
    (void)destination;
    (void)size;
    /* TODO */
    if(source == NULL || destination== NULL)
    {
        return;
    }
    if(size ==0)
    {
        return;
    }
    if(size ==1 )
    {
        destination[0] = '\0';
        return;
    }
    int i=0;
    for(i; i<size-1;i++)
    {
        if(source[i] == NULL)
        {
            destination[i]= '\0';
            return;
        }
        
        destination[i] = source[i];
        
    }
    destination[i] = '\0';
    return;
}

void strgChangeCase(char *s) {
    (void)s;
    /* TODO */
    if(s==NULL) return;
    int pos=0;
    for(int i=0; s[i] != '\0'; i++)
    {
        if( s[i] >='a' && s[i]<='z')
        {
            if( i==0 && (s[i+1] >='0' && s[i+1]<='9'))
            {
                continue;
            }
            else if(i == strgLen(s)-1 && (s[i+1] >='0' && s[i+1]<='9')){
                continue;
            }
            else if( (s[i+1] >='0' && s[i+1]<='9') || (s[i-1] >='0' && s[i-1]<='9'))
            {
                continue;
            }
            else{
                s[i] -=32; 
            }
        }
        else if(s[i] >='A' && s[i]<='Z')
        {
            if( i==0 && (s[i+1] >='0' && s[i+1]<='9'))
            {
                continue;
            }
            else if(i == strgLen(s)-1 && (s[i+1] >='0' && s[i+1]<='9')){
                continue;
            }
            else if( (s[i+1] >='0' && s[i+1]<='9') || (s[i-1] >='0' && s[i-1]<='9'))
            {
                continue;
            }
            else{
                s[i] +=32; 
            }
        }
    }

}

int strgDiff(const char *s1, const char *s2) {
    (void)s1;
    (void)s2;
    /* TODO */
    if(s1 == NULL || s2==NULL ) return -2;
    int i=0;
    for(i; s1[i] != '\0' || s2[i] != '\0';i++)
    {
        if(s1[i] != s2[i])
        {
            return i;
        }
    }
    return -1;
    
}
void strgInterleave(const char *s1, const char *s2, char *d, size_t size) {
    (void)s1;
    (void)s2;
    (void)d;
    (void)size;
    /* TODO */
    if(s1 == NULL || s2 == NULL || d == NULL || size == NULL) return;
    size_t i=0;
    size_t is1 = 0;
    size_t is2 =0; 
    while (i<size -1 && (s1[is1] != '\0' || s2[is2] != '\0' )){
        if(i<size-1 && (s1[is1] != '\0')){
            d[i++] = s1[is1++];
        }
        if(i<size-1 && s2[is2] != '\0'){
            d[i++] = s2[is2++];
        }
    }
    d[i]='\0';
}

void strgReverseLetters(char *s) {
    if (s == NULL) {
        return;
    }
    int left = 0;
    int right = strgLen(s) - 1;
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}
