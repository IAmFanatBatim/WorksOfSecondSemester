#include <stdio.h>
#include "C:\Users\Анна\Desktop\сонины программы\second_semester\WorksOfSecondSemester\libs\data_structures\matrix\matrix.c"

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
