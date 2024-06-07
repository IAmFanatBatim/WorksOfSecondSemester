#include "sorting_algorithms.h"
#include "C:\Users\sovac\Desktop\ОП, преимущественно лабы\second_semester\libs\algorithms\array\array.c"

void bubbleSort(int *array, size_t size) {
    bool was_exchange_required = true;
    for (size_t i = 0; i < size && was_exchange_required; i++) {
        was_exchange_required = false;
        for (size_t j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j+1]) {
                was_exchange_required = true;
                swapVoid(&array[j], &array[j+1], sizeof(int));
            }
        }
    }
}

void selectionSort(int *array, size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        size_t min_pos = i;
        for (size_t j = i+1; j < size; j++) {
            if (array[j] < array[min_pos]) {
                min_pos = j;
            }
        }
        swapVoid(&array[i], &array[min_pos], sizeof(int));
    }
}

void insertionSort(int *array, size_t size) {
    for (int i = 0; i < size; i++) {
        int cur_el = array[i];
        size_t cur_ind = i;
        while (cur_ind > 0 && array[cur_ind-1] > cur_el) {
            array[cur_ind] = array[cur_ind-1];
            cur_ind--;
        }
        array[cur_ind] = cur_el;
    }
}

void combSort(int *array, size_t size) {
    int step = size - 1;
    bool was_exchange_required = true;
    while (step > 1 || was_exchange_required) {
        was_exchange_required = false;
        for (size_t i = 0; i < size - step; i++) {
            if (array[i] > array[i+step]) {
                swapVoid(&array[i], &array[i+step], sizeof(int));
                was_exchange_required = true;
            }
        }
        if (step > 1) {
            step /= 1.24733;
        }
    }
}

void shellSort(int *array, size_t size) {
    int step = size/2;
    while (step > 0) {
        for (int i = step; i < size; i++) {
            int cur_el = array[i];
            size_t cur_ind = i;
            while (cur_ind > step-1 && array[cur_ind - step] > cur_el) {
                array[cur_ind] = array[cur_ind - step];
                cur_ind -= step;
            }
            array[cur_ind] = cur_el;
        }
        step /= 2;
    }
}