#include <stdio.h>
#include "C:\Users\sovac\Desktop\ОП, преимущественно лабы\second_semester\libs\data_structures\matrix\matrix.c"

//1. Меняет местами строки квадратной матрицы, в которых находятся максимальный и минимальный элементы
void swapRowsWithMaxAndMinElement (matrix *m) {
    position max_pos = getMaxValuePos(*m);
    position min_pos = getMinValuePos(*m);
    swapRows(m, max_pos.rowIndex, min_pos.rowIndex);
};

//2. Упорядочивает строки матрицы по неубыванию наибольших элементов строк
void sortRowsByMaxElement(matrix *m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

//3. Упорядочивает столбцы матрицы по неубыванию минимальных элементов столбцов
void sortColsByMinElement(matrix *m) {
    selectionSortColsMatrixByColCriteria(m, getMin);
}

//4. Заменяет квадратную матрицу m ее квадратом, если она симметрична
void getSquareOfMatrixIfSymmetric(matrix *m) {
    if(isSymmetricMatrix(m)) {
        matrix square = mulMatrices(*m, *m);
        freeMemMatrix(m);
        *m = square;
    }
}

//5. Транспонирует матрицу, если среди сумм элементов строк матрицы нет равных
void transposeIfMatrixHasNotEqualSumOfRows(matrix *m) {
    int sum_of_rows[m->nRows];
    for (int row_ind = 0; row_ind < m->nRows; row_ind++) {
        sum_of_rows[row_ind] = getSum(m->values[row_ind], m->nCols);
    }
    if (isUnique(sum_of_rows, m->nRows)) {
        transposeMatrix(m);
    }
}

//6. Возвращает 1, если матрицы m 1 и m2 являются  взаимно обратными, и 0 в противном случае
bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix mul = mulMatrices(m1, m2);
    bool result = isEMatrix(&mul);
    freeMemMatrix(&mul);
    return result;
}

//7. Возвращает сумму максимальных элементов всех псевдодиагоналей данной матрицы.
long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int diagonals = m.nRows + m.nCols - 1;
    int diagonals_under_main = m.nCols - 1;
    int max_elements[diagonals];
    for (int i = 0; i < diagonals; i++) {
        max_elements[i] = INT_MIN;
    }
    for (int row_index = 0; row_index < m.nRows; row_index++) {
        for (int col_index = 0; col_index < m.nCols; col_index++) {
            max_elements[row_index - col_index + diagonals_under_main] = max2(
                    max_elements[row_index - col_index + diagonals_under_main],
                    m.values[row_index][col_index]
            );
        }
    }
    return getSum(max_elements, diagonals) - max_elements[diagonals_under_main];
}

//8. Возвращает минимальный элемент матрицы m в области - перевернутой пирамиде,
// которая упирается в верхнюю и боковые границы матрицы и вершина которой - позиция максимального элемента
int getMinInArea(matrix m) {
    position pos_of_max = getMaxValuePos(m);
    int min_of_area = m.values[pos_of_max.rowIndex][pos_of_max.colIndex];
    for (int col_ind = 0; col_ind < m.nCols; col_ind++) {
        for (int row_ind = 0; row_ind <= pos_of_max.rowIndex - abs(pos_of_max.colIndex - col_ind); row_ind++) {
            min_of_area = min2(min_of_area, m.values[row_ind][col_ind]);
        }
    }
    return min_of_area;
}

//9. Сортирует строки матрицы m неубыванию их расстояний до начала координат
// если эти строки представить как координаты точки в пространстве с m->nCols измерениями
void sortByDistances(matrix *m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

//10. Возвращает количество классов эквивалентных строк данной прямоугольной матрицы
int countEqClassesByRowsSum(matrix m) {
    long long sums_of_rows[m.nRows];
    for (int i = 0; i < m.nRows; i++) {
        sums_of_rows[i] = getSum(m.values[i], m.nCols);
    }
    qsort(sums_of_rows, m.nRows, sizeof(long long), cmp_long_long);
    return countNUnique(sums_of_rows, m.nRows);
}

//11. Возвращает количество элементов матрицы, которые больше суммы остальных элементов своего столбца
int getNSpecialElement(matrix m) {
    int counter_of_special = 0;
    for (int col_ind = 0; col_ind < m.nCols; col_ind++) {
        int cur_col_array[m.nRows];
        for (int row_ind = 0; row_ind < m.nRows; row_ind++) {
            cur_col_array[row_ind] = m.values[row_ind][col_ind];
        }
        int max_col_element = getMax(cur_col_array, m.nRows);
        long long col_sum = getSum(cur_col_array, m.nRows);
        if (max_col_element > col_sum - max_col_element) {
            counter_of_special += 1;
        }
    }
    return counter_of_special;
}

//12. Заменить предпоследнюю строку матрицы первым из столбцов, в котором находится минимальный элемент матрицы
void swapPenultimateRow(matrix *m) {
    assert(m->nRows >= 2);
    position left_min = getLeftMin(*m);
    int col_with_min[m->nRows];
    for (int row_ind = 0; row_ind < m->nRows; row_ind++) {
        col_with_min[row_ind] = m->values[row_ind][left_min.colIndex];
    }
    for (int common_ind = 0; common_ind < m->nRows; common_ind++) {
        m->values[m->nRows - 2][common_ind] = col_with_min[common_ind];
    }
}

//13. Возвращает число матриц, строки которых упорядочены по неубыванию элементов
int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int counter_of_non_descending = 0;
    for (int cur_mat_ind = 0; cur_mat_ind < nMatrix; cur_mat_ind++) {
        counter_of_non_descending += hasAllNonDescendingRows(ms[cur_mat_ind]);
    }
    return counter_of_non_descending;
}

//14. Выводит на экран матрицы из массива матриц, в которых число нулевых строк максимлаьно для этого массива
void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int zero_rows_for_every[nMatrix];
    for (int cur_mat_ind = 0; cur_mat_ind < nMatrix; cur_mat_ind++) {
        zero_rows_for_every[cur_mat_ind] = countZeroRows(ms[cur_mat_ind]);
    }
    int max_of_zero_rows = getMax(zero_rows_for_every, nMatrix);
    for (int cur_mat_ind = 0; cur_mat_ind < nMatrix; cur_mat_ind++) {
        if (zero_rows_for_every[cur_mat_ind] == max_of_zero_rows) {
            outputMatrix(ms[cur_mat_ind]);
            printf("\n");
        }
    }
}

//15. Выводит на экран матрицы из массива матриц, в которых число нулевых строк максимально для этого массива
void printMatrixWithMinNorma(matrix *ms, int nMatrix) {
    int norma_for_every[nMatrix];
    for (int cur_mat_ind = 0; cur_mat_ind < nMatrix; cur_mat_ind++) {
        norma_for_every[cur_mat_ind] = getNorma(ms[cur_mat_ind]);
    }
    int min_norma = getMin(norma_for_every, nMatrix);
    for (int cur_mat_ind = 0; cur_mat_ind < nMatrix; cur_mat_ind++) {
        if (norma_for_every[cur_mat_ind] == min_norma) {
            outputMatrix(ms[cur_mat_ind]);
            printf("\n");
        }
    }
}

int getNSpecialElement2(matrix m) {
    int counter_of_special = 0;
    for (int row_ind = 0; row_ind < m.nRows; row_ind++) {
        for (int cur_el_ind = 0; cur_el_ind < m.nCols; cur_el_ind++) {
            int max_of_left_part, min_of_right_part;
            if (cur_el_ind == 0) {
                max_of_left_part = m.values[row_ind][cur_el_ind] - 1;
            } else {
                max_of_left_part = getMax(m.values[row_ind], cur_el_ind);
            }
            if (m.nCols - cur_el_ind - 1 == 0) {
                min_of_right_part =  m.values[row_ind][cur_el_ind] + 1;
            } else {
                min_of_right_part = getMin(m.values[row_ind] + cur_el_ind + 1, m.nCols - cur_el_ind - 1);
            }
            counter_of_special += m.values[row_ind][cur_el_ind] > max_of_left_part && m.values[row_ind][cur_el_ind] < min_of_right_part;
        }
    }
    return counter_of_special;
}

//17. Возвращает индекс строки матрицы m - вектора, имеющего наибольший угол с вектором - массивом b
int getVectorIndexWithMaxAngle(matrix m, int *b) {
    double min_cos = getCosine(m.values[0], b, m.nCols);
    int index_of_min_cos = 0;
    for (int row_ind = 1; row_ind < m.nRows; row_ind++) {
        if (getCosine(m.values[row_ind], b, m.nCols) < min_cos) {
            min_cos = getCosine(m.values[row_ind], b, m.nCols);
            index_of_min_cos = row_ind;
        }
    }
    return index_of_min_cos;
}

//18. Возвращает скалярное произведение строки, в которой находится наибольший элемент матрицы, на столбец с наименьшим элементом в матрице m
long long getSpecialScalarProduct(matrix m) {
    position pos_of_min = getMinValuePos(m);
    position pos_of_max = getMaxValuePos(m);
    return getScalarProductRowAndCol(m, pos_of_max.rowIndex, pos_of_min.colIndex);
}