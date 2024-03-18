#ifndef INC_MATH_BASICS_C
#define INC_MATH_BASICS_C
#include "math_basics.h"

int compare_ints(const void* a, const void* b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int min2(const int x, const int y) {
    return (x < y) ? x : y;
}

int max2(const int x, const int y) {
    return (x > y) ? x : y;
}

int min3(const int x, const int y, const int z) {
    return min2(min2(x, y), z);
}

int max3(const int x, const int y, const int z) {
    return max2(max2(x, y), z);
}

#endif