#ifndef INC_MATRIX_H
#define INC_MATRIX_H

typedef struct {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} matrix;

typedef struct {
    int rowIndex;
    int colIndex;
} position;

//размещает в динамической памяти и возвращает матрицу размером nRows на nCols
matrix getMemMatrix(int nRows, int nCols);

//размещает в динамической памяти массив из nMatrices матриц размером nRows на nCols, возвращая первый элемент
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

//освобождает память, выделенную под хранение матрицы m
void freeMemMatrix(matrix *m);

//освобождает память, выделенную под хранение массива ms из nMatrices матриц
void freeMemMatrices(matrix *ms, int nMatrices);

//осуществляет ввод матрицы и записывает данные по адресу m
void inputMatrix(matrix *m);

//осуществляет ввод массива из nMatrices матриц, хранящегося по адресу ms
void inputMatrices(matrix *ms, int nMatrices);

// выводит на экран матрицу m
void outputMatrix(matrix m);

// выводит на экран массив из nMatrices матриц, хранящийся по адресу ms
void outputMatrices(matrix *ms, int nMatrices);

#endif
