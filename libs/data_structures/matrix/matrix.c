#include "matrix.h"
#include <malloc.h>
#include <stdio.h>

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int*) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix){values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix*) malloc (sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++) {
        ms[i] = getMemMatrix(nRows, nCols);
    }
    return ms;
}

void freeMemMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++) {
        free(m->values[i]);
    }
    free(m->values);
    m->values = NULL;
    m->nRows = 0;
    m->nCols = 0;
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        freeMemMatrix(&(ms[i]));
    }
    ms = NULL;
}

//осуществляет ввод матрицы и записывает данные по адресу m
void inputMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++) {
        for (int j = 0; j < m->nCols; j++) {
            scanf("%d", &(m->values[i][j]));
        }
    }
}

//осуществляет ввод массива из nMatrices матриц, хранящегося по адресу ms
void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        inputMatrix(ms + i);
    }
}

// выводит на экран матрицу m
void outputMatrix(matrix m) {
    if (m.nRows != 0 && m.nCols != 0) {
        for (int i = 0; i < m.nRows; i++) {
            printf("|");
            for (int j = 0; j < m.nCols; j++) {
                printf("%d ", m.values[i][j]);
            }
            printf("\b|\n");
        }
    }
}

// выводит на экран массив из nMatrices матриц, хранящийся по адресу ms
void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        outputMatrix(ms[i]);
        printf("\n");
    }
}