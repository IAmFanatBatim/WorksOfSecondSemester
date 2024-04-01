#ifndef INC_VECTORVOID_C
#define INC_VECTORVOID_C

#include "vectorVoid.h"
#include "C:\Users\sovac\Desktop\ОП, преимущественно лабы\second_semester\libs\algorithms\math_basics\math_basics.c"
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
    if (index >= v->size) {
        fprintf(stderr, "IndexError: v[%llu] is not exists", index);
        exit(1);
    } else {
        void *source = v->data + index * v->baseTypeSize;
        memcpy(destination, source, v->baseTypeSize);
    }
}

void setVectorValueV(vectorVoid *v, size_t index, void *source) {
    if (index >= v->size) {
        fprintf(stderr, "IndexError: v[%llu] is not exists", index);
        exit(1);
    } else {
        void *destination = v->data + index * v->baseTypeSize;
        memcpy(destination, source, v->baseTypeSize);
    }
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
    v->size += 1;
    setVectorValueV(v, v->size-1, source);
}

#endif