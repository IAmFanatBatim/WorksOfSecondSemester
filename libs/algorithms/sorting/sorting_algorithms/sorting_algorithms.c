#include "sorting_algorithms.h"
#include "C:\Users\sovac\Desktop\ОП, преимущественно лабы\second_semester\libs\algorithms\array\array.c"

void bubbleSort(int *array, size_t size) {
    bool was_exchange_required = true;
    for (int i = 0; i < size && was_exchange_required; i++) {
        was_exchange_required = false;
        for (size_t j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j+1]) {
                was_exchange_required = true;
                swapVoid(&array[j], &array[j+1], sizeof(int));
            }
        }
    }
}