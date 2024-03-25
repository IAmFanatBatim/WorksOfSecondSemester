#include "matrix.h"
#include <malloc.h>
#include <stdio.h>
#include <assert.h>
#include "C:\Users\Анна\Desktop\сонины программы\second_semester\WorksOfSecondSemester\libs\algorithms\array\array.c"


matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int*) * nRows);
    for (int i = 0; i < nRows; i++) {
        values[i] = (int *) malloc(sizeof(int) * nCols);
    }
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

void inputMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++) {
        for (int j = 0; j < m->nCols; j++) {
            scanf("%d", &(m->values[i][j]));
        }
    }
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        inputMatrix(ms + i);
    }
}

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

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        outputMatrix(ms[i]);
        printf("\n");
    }
}

void swapRows(matrix *m, int i1, int i2) {
    assert(i1 < m->nRows && i2 < m->nRows);
    swapVoid(&m->values[i1], &m->values[i2], sizeof(int*));
}

void swapColumns(matrix *m, int j1, int j2) {
    assert(j1 < m->nCols && j2 < m->nCols);
    for (int i = 0; i < m->nRows; i++) {
        swapVoid(&m->values[i][j1], &m->values[i][j2], sizeof(int));
    }
}

void insertionSortRowsMatrixByRowCriteria(matrix *m, int (*criteria)(int*, int)) {
    int criteria_value[m->nRows];
    for (int i = 0; i < m->nRows; i++) {
        criteria_value[i] = criteria(m->values[i], m->nCols);
    }
    for (int start_index = 1; start_index < m->nCols; start_index++) {
        int cur_value = criteria_value[start_index];
        int *cur_row_pointer = m->values[start_index];
        int cur_index = start_index;
        while (cur_index> 0 && criteria_value[cur_index - 1] > cur_value) {
            criteria_value[cur_index] = criteria_value[cur_index - 1];
            m->values[cur_index] = m->values[cur_index - 1];
            cur_index--;
        }
        criteria_value[cur_index] = cur_value;
        m->values[cur_index] = cur_row_pointer;
        //swapRows(m, start_index, cur_index);
    }
}

void selectionSortColsMatrixByColCriteria(matrix *m, int (*criteria)(int*, int)) {
    int criteria_value[m->nCols];
    for (int i = 0; i < m->nCols; i++) {
        int col_elements[m->nRows];
        for (int j = 0; j < m->nRows; j++) {
            col_elements[j] = m->values[j][i];
        }
        criteria_value[i] = criteria(col_elements, m->nRows);
    }
    for (int start_index = 0; start_index < m->nRows-1; start_index++) {
        int minPos = start_index;
        for (int cur_index = start_index + 1; cur_index < m->nRows; cur_index++)
            if (criteria_value[cur_index] < criteria_value[minPos])
                minPos = cur_index;
        swapVoid(&criteria_value[start_index], &criteria_value[minPos], sizeof(int));
        swapColumns(m, start_index, minPos);
    }
}

bool isSquareMatrix(matrix *m) {
    return m->nRows == m->nCols;
}

bool areTwoMatricesEqual(matrix *m1, matrix *m2) {
    bool result = m1->nRows == m2->nRows && m1->nCols == m2->nCols;
    int row_index = 0;
    while (result && row_index < m1->nRows) {
        result = memcmp(m1->values[row_index], m2->values[row_index], sizeof(int)*m1->nCols) == 0;
        row_index++;
    }
    return result;
}

bool isEMatrix(matrix *m) {
    bool result = isSquareMatrix(m);
    for (int row_index = 0; row_index < m->nRows && result; row_index++) {
        for (int col_index = 0; col_index < row_index && result; col_index++) {
            if (row_index == col_index) {
                result = m->values[row_index][col_index] == 1;
            } else {
                result = m->values[row_index][col_index] == 0;
            }
        }
    }
    return result;
}

bool isSymmetricMatrix(matrix *m) {
    bool result = isSquareMatrix(m);
    for (int row_index = 0; row_index < m->nRows && result; row_index++) {
        for (int col_index = 0; col_index < row_index && result; col_index++) {
            result = m->values[row_index][col_index] == m->values[col_index][row_index];
        }
    }
    return result;
}

void transposeSquareMatrix(matrix *m) {
    for (int row_index = 0; row_index < m->nRows; row_index++) {
        for (int col_index = 0; col_index < row_index; col_index++) {
            swapVoid(&m->values[row_index][col_index], &m->values[col_index][row_index], sizeof(int));
        }
    }
}

void transposeMatrix(matrix *m) {
    matrix m_transposed = getMemMatrix(m->nCols, m->nRows);
    for (int row_index = 0; row_index < m->nRows; row_index++) {
        for (int col_index = 0; col_index < m->nCols; col_index++) {
            m_transposed.values[col_index][row_index] = m->values[row_index][col_index];
        }
    }
    *m = m_transposed;
}