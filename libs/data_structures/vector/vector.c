#include "vector.h"
#include "C:\Users\Анна\Desktop\сонины программы\second_semester\WorksOfSecondSemester\libs\algorithms\array\array.c"
#include <stdio.h>
#include <malloc.h>

vector createVector(size_t n) {
    int *data = (int*) malloc(sizeof(int)*n);
    if (data == NULL && n != 0) {
        fprintf(stderr, "bad alloc");
        exit(1);
    } else {
        return (vector) {data, 0, n};
    }
}

void reserve(vector *v, size_t newCapacity) {
    v->data = (int*) realloc(v->data, sizeof(int)*newCapacity);
    if (v->data == NULL && newCapacity != 0)
    {
        fprintf(stderr, "bad alloc");
        exit(1);
    } else {
        v->capacity = newCapacity;
        v->size = (v->size < newCapacity) ? v->size : newCapacity;
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}


