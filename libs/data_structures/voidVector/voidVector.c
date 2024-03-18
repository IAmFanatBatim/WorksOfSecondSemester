#ifndef INC_VOIDVECTOR_C
#define INC_VOIDVECTOR_C

#include "voidVector.h"
#include "C:\Users\Анна\Desktop\сонины программы\second_semester\WorksOfSecondSemester\libs\algorithms\math_basics\math_basics.c"
#include <malloc.h>
#include <memory.h>
#include <stdio.h>

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
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

bool isEmptyV(vectorVoid *v) {
    return v->size == 0;
}

bool isFullV(vectorVoid *v) {
    return v->size == v->capacity;
}

void getVectorValueV(vectorVoid *v, size_t index, void *destination) {
    void *source = v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void setVectorValueV(vectorVoid *v, size_t index, void *source) {
    void *destination = v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void popBackV(vectorVoid *v)  {
    if (v->size == 0) {
        fprintf(stderr, "IndexError: vector is empty, last element is missing");
        exit(1);
    } else {
        v->size -= 1;
    }
}

void pushBackV(vectorVoid *v, void *source)  {
    if (v->capacity <= v->size) {
        size_t new_capacity = (v->capacity == 0) ? 1 : v->capacity*2;
        reserveV(v, new_capacity);
    }
    setVectorValueV(v, v->size, source);
    v->size += 1;
}

#endif