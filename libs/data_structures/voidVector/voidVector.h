#ifndef VOIDVECTOR_LIBRARY_H
#define VOIDVECTOR_LIBRARY_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    void *data; //указатель на нулевой элемент вектора
    size_t size; //размер вектора
    size_t capacity; //вместимость вектора
    size_t baseTypeSize; //размер базового типа
    // например, если вектор хранит int - то поле baseTypeSize = sizeof(int)
    // если вектор хранит float - то поле baseTypeSize = sizeof(float)
} vectorVoid;

#endif