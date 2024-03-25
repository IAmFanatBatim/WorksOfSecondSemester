#ifndef INC_MATRIX_H
#define INC_MATRIX_H

#include <stdbool.h>

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

//обменивает строки с порядковыми номерами i1 и i2 в матрице m
void swapRows(matrix *m, int i1, int i2);

//обменивает колонки с порядковыми номерами j1 и j2 в матрице m
void swapColumns(matrix *m, int j1, int j2);

//выполняет сортировку вставками строк матрицы m по неубыванию значения функции criteria, применяемой для строк
void insertionSortRowsMatrixByRowCriteria(matrix *m, int (*criteria)(int*, int));

//выполняет сортировку выбором столбцов матрицы m по неубыванию значения функции criteria, применяемой для столбцов
void selectionSortColsMatrixByColCriteria(matrix *m, int (*criteria)(int*, int));

//возвращает 1 если матрица m является квадратной, и 0 в противном случае
bool isSquareMatrix(matrix *m);

//возвращает 1, если матрицы m1 и m2 равны, и 0 в противном случае
bool areTwoMatricesEqual(matrix *m1, matrix *m2);

//возвращает 1 если матрица m является единичной, и 0 в противном случае.
bool isEMatrix(matrix *m);

//возвращает 1, если матрица m является симметричной, и 0 в противном случае
bool isSymmetricMatrix(matrix *m);

//транспонирует квадратную матрицу m
void transposeSquareMatrix(matrix *m);

//транспонирует произвольную матрицу m
void transposeMatrix(matrix *m);

//выводит на экран позицию pos
void outputPosition(position pos);

//возвращает позицию минимального элемента матрицы m
position getMinValuePos(matrix m);

//возвращает позицию максимального элемента матрицы m
position getMaxValuePos(matrix m);

#endif
