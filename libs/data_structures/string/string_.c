#ifndef INC_STRING__C
#define INC_STRING__C
#include "string_.h"

size_t strlen_(const char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
}

#endif
