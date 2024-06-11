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

int getIByte_(int n, int i) {
    int bite_module = (n >> (8*i)) & ((1<<8)-1);
    if (i == 3) {
        bool is_negative = n >> ((sizeof(int) * 8) - 1) & 1;
        if (is_negative) {
            return ~bite_module;
        }
    }
    return bite_module;
}

void getMinMaxByte_(int *array, size_t size, int *min, int *max, int byte_ind) {
    *min = getIByte_(array[0], byte_ind);
    *max = getIByte_(array[0], byte_ind);
    for (int i = 0; i < size; i++) {
        if (getIByte_(array[i], byte_ind) < *min) {
            *min = getIByte_(array[i], byte_ind);
        } else if (getIByte_(array[i], byte_ind) > *max) {
            *max = getIByte_(array[i], byte_ind);
        }
    }
}

void digitSort(int *array, size_t size) {
    int *copy_array = (int*) calloc(size, sizeof(int));
    for (int byte_ind = 0; byte_ind < 4; byte_ind++) {
        int min, max;
        getMinMaxByte_(array, size, &min, &max, byte_ind);
        int k = max - min + 1;
        int *count_array = (int*) calloc(k, sizeof(int));

        for (int i = 0; i < size; i++) {
            int cur_byte = getIByte_(array[i], byte_ind);
            count_array[cur_byte-min]++;
        }

        int *prefix_count_array = (int*) calloc(k, sizeof(int));
        for (int i = 1; i < k; i++) {
            prefix_count_array[i] = prefix_count_array[i-1] + count_array[i-1];
        }

        memcpy(copy_array, array, sizeof(int)*size);
        for (int i = 0; i < size; i++) {
            int cur_byte = getIByte_(copy_array[i], byte_ind);
            array[prefix_count_array[cur_byte  - min]] = copy_array[i];
            prefix_count_array[cur_byte - min]++;
        }

        free(count_array);
        free(prefix_count_array);
    }
    free(copy_array);
}
