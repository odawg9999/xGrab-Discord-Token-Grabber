#include "CFuncs.h"

void memset(void* str, char ch, size_t n) {
    char* s = (char*)str;
    for (size_t i = 0; i < n; i++) {
        s[i] = ch;
    }
}

void memcpy(void* dest, void* src, size_t n)
{
    char* csrc = (char*)src;
    char* cdest = (char*)dest;
    for (size_t i = 0; i < n; i++) {
        cdest[i] = csrc[i];
    }
}
