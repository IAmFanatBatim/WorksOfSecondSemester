#include "voidVector.h"
#include "C:\Users\Анна\Desktop\сонины программы\second_semester\WorksOfSecondSemester\libs\algorithms\array\array.c"
#include "C:\Users\Анна\Desktop\сонины программы\second_semester\WorksOfSecondSemester\libs\algorithms\math_basics\math_basics.c"
#include <malloc.h>
#include <stdio.h>

vectorVoid createVector(size_t n, size_t baseTypeSize) {
    int *data = malloc(baseTypeSize*n);
    if (data == NULL && n != 0) {
        fprintf(stderr, "bad alloc");
        exit(1);
    } else {
        return (vectorVoid) {data, 0, n, baseTypeSize};
    }
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    v->data = realloc(v->data, v->baseTypeSize*newCapacity);
    if (v->data == NULL && newCapacity != 0) {
        fprintf(stderr, "bad alloc");
        exit(1);
    } else {
        v->capacity = newCapacity;
        v->size = min2(v->size, newCapacity);
    }
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}
