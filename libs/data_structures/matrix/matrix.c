#include "matrix.h"
#include <malloc.h>
#include <stdio.h>
#include <assert.h>
#include "C:\Users\Анна\Desktop\сонины программы\second_semester\WorksOfSecondSemester\libs\algorithms\array\array.c"
#ifndef INC_MATRIX_С
#define INC_MATRIX_С

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int*) * nRows);
    for (int row_ind = 0; row_ind < nRows; row_ind++) {
        values[row_ind] = (int *) malloc(sizeof(int) * nCols);
    }
    return (matrix){values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix*) malloc (sizeof(matrix) * nMatrices);
    for (int cur_mat_ind = 0; cur_mat_ind < nMatrices; cur_mat_ind++) {
        ms[cur_mat_ind] = getMemMatrix(nRows, nCols);
    }
    return ms;
}

void freeMemMatrix(matrix *m) {
    for (int row_ind = 0; row_ind < m->nRows; row_ind++) {
        free(m->values[row_ind]);
    }
    free(m->values);
    m->values = NULL;
    m->nRows = 0;
    m->nCols = 0;
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int cur_mat_ind = 0; cur_mat_ind < nMatrices; cur_mat_ind++) {
        freeMemMatrix(&(ms[cur_mat_ind]));
    }
    ms = NULL;
}

void inputMatrix(matrix *m) {
    for (int row_ind = 0; row_ind < m->nRows; row_ind++) {
        for (int col_ind = 0; col_ind < m->nCols; col_ind++) {
            scanf("%d", &(m->values[row_ind][col_ind]));
        }
    }
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int cur_mat_ind = 0; cur_mat_ind < nMatrices; cur_mat_ind++) {
        inputMatrix(ms + cur_mat_ind);
    }
}

void outputMatrix(matrix m) {
    if (m.nRows != 0 && m.nCols != 0) {
        for (int row_ind = 0; row_ind < m.nRows; row_ind++) {
            printf("|");
            for (int col_ind = 0; col_ind < m.nCols; col_ind++) {
                printf("%d ", m.values[row_ind][col_ind]);
            }
            printf("\b|\n");
        }
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int cur_mat_ind = 0; cur_mat_ind < nMatrices; cur_mat_ind++) {
        outputMatrix(ms[cur_mat_ind]);
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

/*void swapRowAdColumn(matrix *m, int i, int j) {
    assert(i < m->nRows && j < m->nCols);
    assert(isSquareMatrix(m));
    for (int common_ind = 0; common_ind < m->nRows; common_ind++) {
        swapVoid(&m->values[i][common_ind], &m->values[common_ind][j], sizeof(int));
    }
}*/

void insertionSortRowsMatrixByRowCriteria(matrix *m, int (*criteria)(int*, int)) {
    int criteria_value[m->nRows];
    for (int i = 0; i < m->nRows; i++) {
        criteria_value[i] = criteria(m->values[i], m->nCols);
    }
    for (int start_index = 1; start_index < m->nRows; start_index++) {
        int cur_value = criteria_value[start_index];
        int *cur_row_pointer = m->values[start_index];
        int cur_index = start_index;
        while (cur_index > 0 && criteria_value[cur_index - 1] > cur_value) {
            criteria_value[cur_index] = criteria_value[cur_index - 1];
            m->values[cur_index] = m->values[cur_index - 1];
            cur_index--;
        }
        criteria_value[cur_index] = cur_value;
        m->values[cur_index] = cur_row_pointer;
    }
}

void insertionSortRowsMatrixByRowCriteriaF(matrix *m, float (*criteria)(int *, int)) {
    float criteria_value[m->nRows];
    for (int i = 0; i < m->nRows; i++) {
        criteria_value[i] = criteria(m->values[i], m->nCols);
    }
    for (int start_index = 1; start_index < m->nRows; start_index++) {
        float cur_value = criteria_value[start_index];
        int *cur_row_pointer = m->values[start_index];
        int cur_index = start_index;
        while (cur_index > 0 && criteria_value[cur_index - 1] > cur_value) {
            criteria_value[cur_index] = criteria_value[cur_index - 1];
            m->values[cur_index] = m->values[cur_index - 1];
            cur_index--;
        }
        criteria_value[cur_index] = cur_value;
        m->values[cur_index] = cur_row_pointer;
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

    for (int start_index = 0; start_index < m->nCols-1; start_index++) {
        int minPos = start_index;
        for (int cur_index = start_index + 1; cur_index < m->nCols; cur_index++)
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

void outputPosition(position pos) {
    printf("(%d, %d)", pos.rowIndex, pos.colIndex);
}

position getMinValuePos(matrix m) {
    int min_element = m.values[0][0];
    position min_position = (position) {0, 0};
    for (int row_index = 0; row_index < m.nRows; row_index++) {
        for (int col_index = 0; col_index < m.nCols; col_index++) {
            if (m.values[row_index][col_index] < min_element) {
                min_element = m.values[row_index][col_index];
                min_position.rowIndex = row_index;
                min_position.colIndex = col_index;
            }
        }
    }
    return min_position;
}

position getLeftMin(matrix m) {
    int min_element = m.values[0][0];
    position min_position = (position) {0, 0};
    for (int col_index = 0; col_index < m.nCols; col_index++) {
        for (int row_index = 0; row_index < m.nRows; row_index++) {
            if (m.values[row_index][col_index] < min_element) {
                min_element = m.values[row_index][col_index];
                min_position.rowIndex = row_index;
                min_position.colIndex = col_index;
            }
        }
    }
    return min_position;
}

position getMaxValuePos(matrix m) {
    int max_element = m.values[0][0];
    position max_position = (position) {0, 0};
    for (int row_index = 0; row_index < m.nRows; row_index++) {
        for (int col_index = 0; col_index < m.nCols; col_index++) {
            if (m.values[row_index][col_index] > max_element) {
                max_element = m.values[row_index][col_index];
                max_position.rowIndex = row_index;
                max_position.colIndex = col_index;
            }
        }
    }
    return max_position;
}

//возвращает матрицу размера nRows на nCols, построенную из элементов массива a
matrix createMatrixFromArray(const int *a, size_t nRows, size_t nCols) {
    matrix m = getMemMatrix(nRows, nCols);
    int k = 0;
    for (int row_ind = 0; row_ind < nRows; row_ind++) {
        for (int col_ind = 0; col_ind < nCols; col_ind++) {
            m.values[row_ind][col_ind] = a[k++];
        }
    }
    return m;
}

// возвращает указатель на нулевую матрицу массива из nMatrices матриц, размещенных
//в динамической памяти, построенных из элементов массива a
matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    int l = 0;
    for (size_t cur_mat_ind = 0; cur_mat_ind < nMatrices; cur_mat_ind++)
        for (size_t row_ind = 0; row_ind < nRows; row_ind++)
            for (size_t col_ind = 0; col_ind < nCols; col_ind++)
                ms[cur_mat_ind].values[row_ind][col_ind] = values[l++];
    return ms;
}

matrix mulMatrices(matrix m1, matrix m2) {
    assert(m1.nCols == m2.nRows);
    matrix result = getMemMatrix(m1.nRows, m2.nCols);
    for (int row_ind = 0; row_ind < result.nRows; row_ind++) {
        for (int col_ind = 0; col_ind < result.nCols; col_ind++) {
            result.values[row_ind][col_ind] = 0;
            for (int summand_ind = 0; summand_ind < m1.nRows; summand_ind++) {
                result.values[row_ind][col_ind] += m1.values[row_ind][summand_ind] * m2.values[summand_ind][col_ind];
            }
        }
    }
    return result;
}

bool hasAllNonDescendingRows(matrix m) {
    bool result = 1;
    for (int row_ind = 0; row_ind < m.nRows; row_ind++) {
        if (!isNonDescendingSorted(m.values[row_ind], m.nCols)) {
            result = 0;
            break;
        }
    }
    return result;
}

int countZeroRows(matrix m) {
    int zero_rows_counter = 0;
    for (int row_ind = 0; row_ind < m.nRows; row_ind++) {
        if (countValues(m.values[row_ind], m.nCols, 0) == m.nCols) {
            zero_rows_counter += 1;
        }
    }
    return zero_rows_counter;
}

int getNorma(matrix m) {
    int norma = abs(m.values[0][0]);
    for (int row_index = 0; row_index < m.nRows; row_index++) {
        for (int col_index = 0; col_index < m.nCols; col_index++) {
            if (abs(m.values[row_index][col_index]) > norma) {
                norma = abs(m.values[row_index][col_index]);
            }
        }
    }
    return norma;
}

#endif