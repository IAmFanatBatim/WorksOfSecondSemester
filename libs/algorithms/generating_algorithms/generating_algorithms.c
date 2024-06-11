#include "generating_algorithms.h"

#include <stdio.h>

void generateRandomArray(int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        array[i] = rand() % size - size/2;
    }
}

void generateOrderedArray(int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        array[i] = i;
    }
}

void generateOrderedBackwards(int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        array[i] = size - i - 1;
    }
}

void generateOrderedWithNegative(int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        array[i] = i - size/2;
    }
}

void generateOrderedBackwardsWithNegative(int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        array[i] = size/2 - i;
    }
}
