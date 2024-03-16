#ifndef VECTOR_LIBRARY_H
#define VECTOR_LIBRARY_H

#include <stdint.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

//Создаёт и возвращает пустой вектор, в котором зарезервирована память для n элементов
 vector createVector(size_t n);

//изменяет количество памяти, отведенной для хранения вектора, так, чтобы он вмещал в себя newCapacity элементов
void reserve(vector *v, size_t newCapacity);

//Уменьшает размер вектора по адресу v до нуля, как бы списывая все хранящиеся элементы в "мусор"
void clear(vector *v);

//Уравнивает вместимость вектора по адресу v с количеством элементов в нем.
 void shrinkToFit(vector *v);

//Освобождает память, выделенную вектору по адресу v
void deleteVector(vector *v);

#endif