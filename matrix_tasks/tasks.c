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