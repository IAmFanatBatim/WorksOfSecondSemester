#ifndef INC_VECTOR_C
#define INC_VECTOR_C

#include "vector.h"
#include "C:\Users\sovac\Desktop\ОП, преимущественно лабы\second_semester\libs\algorithms\array\array.c"
#include "C:\Users\sovac\Desktop\ОП, преимущественно лабы\second_semester\libs\algorithms\math_basics\math_basics.c"
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
    if (v->data == NULL && newCapacity != 0) {
        fprintf(stderr, "bad alloc");
        exit(1);
    } else {
        v->capacity = newCapacity;
        v->size = min2(v->size, newCapacity);
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

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    if (i >= v->size) {
        fprintf(stderr, "IndexError: a[%llu] is not exists", i);
        exit(1);
    } else {
        return v->data[i];
    }
}

void pushBack(vector *v, int x) {
    if (v->capacity <= v->size) {
        size_t new_capacity = (v->capacity == 0) ? 1 : v->capacity*2;
        reserve(v, new_capacity);
    }
    append_(v->data, &(v->size), x);
}

void popBack(vector *v) {
    if (v->size == 0) {
        fprintf(stderr, "IndexError: vector is empty, last element is missing");
        exit(1);
    } else {
        deleteByPosSaveOrder_(v->data, &(v->size), v->size - 1);
    }
}

int* atVector(vector *v, size_t index) {
    if (index >= v->size) {
        fprintf(stderr, "IndexError: a[%llu] is not exists", index);
        exit(1);
    } else {
        return (v->data)+index;
    }
}

int* back(vector *v) {
    return atVector(v, max2((int)(v->size)-1, 0));
}

int* front(vector *v) {
    return atVector(v,0);
}

#endif