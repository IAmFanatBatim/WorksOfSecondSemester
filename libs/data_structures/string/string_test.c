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

int main () {
    char *s1 = "Hello!";
    char *s2 = "\tHello!\b";
    char s3[14] = "Hello!";
    char *s4 = "";
    printf("%llu %llu %llu %llu \n", strlen_(s1), strlen_(s2), strlen_(s3), strlen_(s4));
    printf("World Hel\blo!");
    return 0;
}