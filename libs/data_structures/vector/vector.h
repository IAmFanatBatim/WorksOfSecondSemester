#ifndef VECTOR_LIBRARY_H
#define VECTOR_LIBRARY_H

#include <stdint.h>
#include <stdbool.h>

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

//Возвращает 1, если в векторе по адресу v хранятся какие-либо элементы, и 0 в противном случае
bool isEmpty(vector *v);

//Возвращает 1, если вектор по адресу v хранит количество элементов, совпадающее с его вместимостью, и 0 в противном случае
bool isFull(vector *v);

//возвращает i-ый элемент вектора v.
int getVectorValue(vector *v, size_t i);

//добавляет элемент x в конец вектора v
void pushBack(vector *v, int x);

//удаляет последний элемент из вектора v
void popBack(vector *v);

//возвращает указатель на index-ый элемент вектора v
//выводится ошибка, если index лежит вне пределов используемых элементов вектора
int* atVector(vector *v, size_t index);

//возвращает указатель на последний элемент вектора v
int* back(vector *v);

//возвращает указатель на нулевой элемент вектора v
int* front(vector *v);

#endif