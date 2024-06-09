#ifndef GENERATING_ALGORITHMS_LIBRARY_H
#define GENERATING_ALGORITHMS_LIBRARY_H
#include <stdint.h>

void generateRandomArray(int *array, size_t size);

void generateOrderedArray(int *array, size_t size);

void generateOrderedBackwards(int *array, size_t size);

void generateOrderedArrayWithNegative(int *array, size_t size);

void generateOrderedBackwardsWithNegative(int *array, size_t size);

#endif //GENERATING_ALGORITHMS_LIBRARY_H
