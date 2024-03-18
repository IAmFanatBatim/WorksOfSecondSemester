#ifndef INC_VOIDVECTOR_H
#define INC_VOIDVECTOR_H

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

//Создаёт и возвращает пустой произвольный вектор, в котором зарезервирована память для n элементов размера baseTypeSize
vectorVoid createVectorV(size_t n, size_t baseTypeSize);

//изменяет количество памяти, отведенной для хранения произвольного вектора, так, чтобы он вмещал в себя newCapacity элементов
void reserveV(vectorVoid *v, size_t newCapacity);

//Уменьшает размер произвольного вектора по адресу v до нуля, как бы списывая все хранящиеся элементы в "мусор"
void clearV(vectorVoid *v);

//Уравнивает вместимость произвольного вектора по адресу v с количеством элементов в нем.
void shrinkToFitV(vectorVoid *v);

//Освобождает память, выделенную произвольному вектору по адресу v
void deleteVectorV(vectorVoid *v);

//Возвращает 1, если в произвольном векторе по адресу v хранятся какие-либо элементы, и 0 в противном случае
bool isEmptyV(vectorVoid *v);

//Возвращает 1, если произвольный вектор по адресу v хранит количество элементов, совпадающее с его вместимостью, и 0 в противном случае
bool isFullV(vectorVoid *v);

//записывает по адресу destination index-ый элемент произвольного вектора v
void getVectorValueV(vectorVoid *v, size_t index, void *destination);

//записывает на index-ый элемент произвольного вектора v значение, расположенное по адресу source
void setVectorValueV(vectorVoid *v, size_t index, void *source);

//удаляет последний элемент из произвольного вектора v
void popBackV(vectorVoid *v);

//добавляет элемент x в конец произвольного вектора v
void pushBackV(vectorVoid *v, void *source);

#endif