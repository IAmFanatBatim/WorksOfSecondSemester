#include <stdio.h>
#include <assert.h>
#include "C:\Users\Анна\Desktop\сонины программы\second_semester\WorksOfSecondSemester\matrix_tasks\tasks.c"

void test_swapRowsWithMaxAndMinElement_commonMatrix() {
    matrix mat = createMatrixFromArray(
            (int[]) {
                2, 1, 0,
                3, 9, 6,
                7, 8, 2
            }, 3, 3
    );
    matrix mat_result = createMatrixFromArray(
            (int[]) {
                    3, 9, 6,
                    2, 1, 0,
                    7, 8, 2
            }, 3, 3
    );
    swapRowsWithMaxAndMinElement(&mat);
    assert(areTwoMatricesEqual(&mat, &mat_result));
    freeMemMatrix(&mat);
    freeMemMatrix(&mat_result);
}

void test_swapRowsWithMaxAndMinElement_MaxMinInOneRow() {
    matrix mat = createMatrixFromArray(
            (int[]) {
                    0, 9, 1,
                    2, 8, 6,
                    7, 3, 2
            }, 3, 3
    );
    matrix mat_result = createMatrixFromArray(
            (int[]) {
                    0, 9, 1,
                    2, 8, 6,
                    7, 3, 2
            }, 3, 3
    );
    swapRowsWithMaxAndMinElement(&mat);
    assert(areTwoMatricesEqual(&mat, &mat_result));
    freeMemMatrix(&mat);
    freeMemMatrix(&mat_result);
}

void test_sortRowsByMaxElement_matrixOfUnique() {
    matrix mat = createMatrixFromArray(
            (int[]) {
                    3, 9, 2,
                    5, 8, 4,
                    7, 12, 10,
                    0, 6, 1
            }, 4, 3
    );
    matrix mat_result = createMatrixFromArray(
            (int[]) {
                    0, 6, 1,
                    5, 8, 4,
                    3, 9, 2,
                    7, 12, 10
            }, 4, 3
    );
    sortRowsByMaxElement(&mat);
    assert(areTwoMatricesEqual(&mat, &mat_result));
    freeMemMatrix(&mat);
    freeMemMatrix(&mat_result);
}

void test_sortRowsByMaxElement_maxRepeating() {
    matrix mat = createMatrixFromArray(
            (int[]) {
                    3, 9, 2,
                    5, 8, 4,
                    7, 9, 3,
                    6, 0, 8
            }, 4, 3
    );
    matrix mat_result = createMatrixFromArray(
            (int[]) {
                    5, 8, 4,
                    6, 0, 8,
                    3, 9, 2,
                    7, 9, 3
            }, 4, 3
    );
    sortRowsByMaxElement(&mat);
    assert(areTwoMatricesEqual(&mat, &mat_result));
    freeMemMatrix(&mat);
    freeMemMatrix(&mat_result);
}

void test_sortRowsByMaxElement_noNeedToSort() {
    matrix mat = createMatrixFromArray(
            (int[]) {
                    3, 7, 2,
                    5, 8, 4,
                    7, 9, 3,
                    6, 10, 8
            }, 4, 3
    );
    matrix mat_result = createMatrixFromArray(
            (int[]) {
                    3, 7, 2,
                    5, 8, 4,
                    7, 9, 3,
                    6, 10, 8
            }, 4, 3
    );
    sortRowsByMaxElement(&mat);
    assert(areTwoMatricesEqual(&mat, &mat_result));
    freeMemMatrix(&mat);
    freeMemMatrix(&mat_result);
}

void test_sortColsByMinElement_matrixOfUnique() {
    matrix mat = createMatrixFromArray(
            (int[]) {
                    3, 9, 2, 1,
                    5, 8, 4, 6,
                    10, 7, 0, 11
            }, 3, 4
    );
    matrix mat_result = createMatrixFromArray(
            (int[]) {
                    2, 1, 3, 9,
                    4, 6, 5, 8,
                    0, 11, 10, 7
            }, 3, 4
    );
    sortColsByMinElement(&mat);
    assert(areTwoMatricesEqual(&mat, &mat_result));
    freeMemMatrix(&mat);
    freeMemMatrix(&mat_result);
}

void test_sortColsByMinElement_minRepeating() {
    matrix mat = createMatrixFromArray(
            (int[]) {
                    3, 0, 2, 3,
                    5, 8, 4, 6,
                    10, 7, 0, 11
            }, 3, 4
    );
    matrix mat_result = createMatrixFromArray(
            (int[]) {
                    0, 2, 3, 3,
                    8, 4, 5, 6,
                    7, 0, 10,11
            }, 3, 4
    );
    sortColsByMinElement(&mat);
    assert(areTwoMatricesEqual(&mat, &mat_result));
    freeMemMatrix(&mat);
    freeMemMatrix(&mat_result);
}

void test_sortColsByMinElement_noNeedToSort() {
    matrix mat = createMatrixFromArray(
            (int[]) {
                    0, 2, 3, 5,
                    5, 8, 4, 6,
                    10, 7, 3, 11
            }, 3, 4
    );
    matrix mat_result = createMatrixFromArray(
            (int[]) {
                    0, 2, 3, 5,
                    5, 8, 4, 6,
                    10, 7, 3, 11
            }, 3, 4
    );
    sortColsByMinElement(&mat);
    assert(areTwoMatricesEqual(&mat, &mat_result));
    freeMemMatrix(&mat);
    freeMemMatrix(&mat_result);
}

void test_getSquareOfMatrixIfSymmetric_symmetric() {
    matrix mat = createMatrixFromArray(
            (int[]) {
                    3, 1,
                    1, 3
            }, 2, 2
    );
    matrix mat_result = createMatrixFromArray(
            (int[]) {
                    10, 6,
                    6, 10
            }, 2, 2
    );
    getSquareOfMatrixIfSymmetric(&mat);
    assert(areTwoMatricesEqual(&mat, &mat_result));
    freeMemMatrix(&mat);
    freeMemMatrix(&mat_result);
}

void test_getSquareOfMatrixIfSymmetric_symmetricButMore() {
    matrix mat = createMatrixFromArray(
            (int[]) {
                    2, 1, 4,
                    1, 3, 2,
                    4, 2, 5
            }, 3, 3
    );
    matrix mat_result = createMatrixFromArray(
            (int[]) {
                    21, 13, 30,
                    13, 14, 20,
                    30, 20, 45
            }, 3, 3
    );
    getSquareOfMatrixIfSymmetric(&mat);
    assert(areTwoMatricesEqual(&mat, &mat_result));
    freeMemMatrix(&mat);
    freeMemMatrix(&mat_result);
}

void test_getSquareOfMatrixIfSymmetric_asymmetric() {
    matrix mat = createMatrixFromArray(
            (int[]) {
                    3, 2,
                    1, 3
            }, 2, 2
    );
    matrix mat_result = createMatrixFromArray(
            (int[]) {
                    3, 2,
                    1, 3
            }, 2, 2
    );
    getSquareOfMatrixIfSymmetric(&mat);
    assert(areTwoMatricesEqual(&mat, &mat_result));
    freeMemMatrix(&mat);
    freeMemMatrix(&mat_result);
}

void test_transposeIfMatrixHasNotEqualSumOfRows_squareUniqueSums() {
    matrix mat = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    2, 4, 1,
                    4, 3, 4
            }, 3, 3
    );
    matrix mat_result = createMatrixFromArray(
            (int[]) {
                    1, 2, 4,
                    2, 4, 3,
                    3, 1, 4
            }, 3, 3
    );
    transposeIfMatrixHasNotEqualSumOfRows(&mat);
    assert(areTwoMatricesEqual(&mat, &mat_result));
    freeMemMatrix(&mat);
    freeMemMatrix(&mat_result);
}

void test_transposeIfMatrixHasNotEqualSumOfRows_freeShapeUniqueSums() {
    matrix mat = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    2, 4, 1,
                    4, 3, 4,
                    2, 7, 8,
                    1, 0, 1
            }, 5, 3
    );
    matrix mat_result = createMatrixFromArray(
            (int[]) {
                    1, 2, 4, 2, 1,
                    2, 4, 3, 7, 0,
                    3, 1, 4, 8, 1
            }, 3, 5
    );
    transposeIfMatrixHasNotEqualSumOfRows(&mat);
    assert(areTwoMatricesEqual(&mat, &mat_result));
    freeMemMatrix(&mat);
    freeMemMatrix(&mat_result);
}

void test_transposeIfMatrixHasNotEqualSumOfRows_freeShapeSumsRepeated() {
    matrix mat = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    6, 6, 5,
                    3, 0, 3,
                    2, 7, 8,
                    1, 0, 1
            }, 5, 3
    );
    matrix mat_result = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    6, 6, 5,
                    3, 0, 3,
                    2, 7, 8,
                    1, 0, 1
            }, 5, 3
    );
    transposeIfMatrixHasNotEqualSumOfRows(&mat);
    assert(areTwoMatricesEqual(&mat, &mat_result));
    freeMemMatrix(&mat);
    freeMemMatrix(&mat_result);
}

void test_isMutuallyInverseMatrices_inverse() {
    matrix mat1 = createMatrixFromArray(
            (int[]) {
                    2, 7,
                    1, 4
            }, 2, 2
    );
    matrix mat2 = createMatrixFromArray(
            (int[]) {
                    4, -7,
                    -1, 2
            }, 2, 2
    );
    assert(isMutuallyInverseMatrices(mat1, mat2));
    freeMemMatrix(&mat1);
    freeMemMatrix(&mat2);
}

void test_isMutuallyInverseMatrices_notInverse() {
    matrix mat1 = createMatrixFromArray(
            (int[]) {
                    2, 7,
                    1, 4
            }, 2, 2
    );
    matrix mat2 = createMatrixFromArray(
            (int[]) {
                    4, 2,
                    -1, -7
            }, 2, 3
    );
    assert(!isMutuallyInverseMatrices(mat1, mat2));
    freeMemMatrix(&mat1);
    freeMemMatrix(&mat2);
}

void test_findSumOfMaxesOfPseudoDiagonal_RowsMoreThanCols() {
    matrix mat = createMatrixFromArray(
            (int[]) {
                    3, 2,
                    1, 4,
                    3, 2,
                    1, 7
            }, 4, 2
    );
    assert(findSumOfMaxesOfPseudoDiagonal(mat) == 12);
    freeMemMatrix(&mat);
}

void test_findSumOfMaxesOfPseudoDiagonal_ColsMoreThanRows() {
    matrix mat = createMatrixFromArray(
            (int[]) {
                    3, 2, 2, 4,
                    1, 4, 6, 3,
                    3, 2, 1, 2
            }, 3, 4
    );
    assert(findSumOfMaxesOfPseudoDiagonal(mat) == 18);
    freeMemMatrix(&mat);
}

void test_findSumOfMaxesOfPseudoDiagonal_square() {
    matrix mat = createMatrixFromArray(
            (int[]) {
                    3, 2, 5,
                    1, 3, 6,
                    3, 2, 1
            }, 3, 3
    );
    assert(findSumOfMaxesOfPseudoDiagonal(mat) == 16);
    freeMemMatrix(&mat);
}

void test_findSumOfMaxesOfPseudoDiagonal_someMaxAtBeginningOfDiagonal() {
    matrix mat = createMatrixFromArray(
            (int[]) {
                    3, 2, 5, 4,
                    1, 3, 6, 3,
                    3, 2, 1, 2
            }, 3, 4
    );
    assert(findSumOfMaxesOfPseudoDiagonal(mat) == 20);
    freeMemMatrix(&mat);
}

void test_getMinInArea_areaStartsWithFirstElement() {
    matrix mat = createMatrixFromArray(
            (int[]) {
                    10, 7, 5, 6,
                    3, 11, 8, 9,
                    4, 1, 12, 12
            }, 3, 4
    );
    assert(getMinInArea(mat) == 5);
    freeMemMatrix(&mat);
}

void test_getMinInArea_areaStartsBelowFirstElement() {
    matrix mat = createMatrixFromArray(
            (int[]) {
                    10, 7, 5, 6,
                    3, 11, 8, 9,
                    4, 14, 1, 12
            }, 3, 4
    );
    assert(getMinInArea(mat) == 3);
    freeMemMatrix(&mat);
}

void test_getMinInArea_areaLeftEdgesFree() {
    matrix mat = createMatrixFromArray(
            (int[]) {
                    10, 7, 5, 6, 2,
                    3, 18, 12, 9, 15,
                    4, 0, 1, 13, 13,
            }, 3, 4
    );
    assert(getMinInArea(mat) == 5);
    freeMemMatrix(&mat);
}


void test_sortByDistances_rowsMoreThanCols() {
    matrix mat = createMatrixFromArray(
            (int[]) {
                    1, 2, 4,
                    2, 8, 3,
                    3, 1, 0,
                    1, 5, 2
            }, 4, 3
    );
    matrix result_mat = createMatrixFromArray(
            (int[]) {
                    3, 1, 0,
                    1, 2, 4,
                    1, 5, 2,
                    2, 8, 3
            }, 4, 3
    );
    sortByDistances(&mat);
    assert(areTwoMatricesEqual(&mat, &result_mat));
    freeMemMatrix(&mat);
    freeMemMatrix(&result_mat);
}

void test_sortByDistances_colsMoreThanRows() {
    matrix mat = createMatrixFromArray(
            (int[]) {
                    2, 5, 3, 2,
                    3, 7, 0, 4,
                    1, 3, 4,0
            }, 3, 4
    );
    matrix result_mat = createMatrixFromArray(
            (int[]) {
                    1, 3, 4, 0,
                    2, 5, 3, 2,
                    3, 7, 0, 4,
            }, 3, 4
    );
    sortByDistances(&mat);
    assert(areTwoMatricesEqual(&mat, &result_mat));
    freeMemMatrix(&mat);
    freeMemMatrix(&result_mat);
}

void test_sortByDistances_someDistancesAreEqual() {
    matrix mat = createMatrixFromArray(
            (int[]) {
                    1, 2, 4,
                    2, 8, 3,
                    3, 1, 0,
                    1, 4, 2
            }, 4, 3
    );
    matrix result_mat = createMatrixFromArray(
            (int[]) {
                    3, 1, 0,
                    1, 2, 4,
                    1, 4, 2,
                    2, 8, 3
            }, 4, 3
    );
    sortByDistances(&mat);
    assert(areTwoMatricesEqual(&mat, &result_mat));
    freeMemMatrix(&mat);
    freeMemMatrix(&result_mat);
}

void test () {
    test_swapRowsWithMaxAndMinElement_commonMatrix();
    test_swapRowsWithMaxAndMinElement_MaxMinInOneRow();
    test_sortRowsByMaxElement_matrixOfUnique();
    test_sortRowsByMaxElement_maxRepeating();
    test_sortRowsByMaxElement_noNeedToSort();
    test_sortColsByMinElement_matrixOfUnique();
    test_sortColsByMinElement_minRepeating();
    test_sortColsByMinElement_noNeedToSort();
    test_getSquareOfMatrixIfSymmetric_symmetric();
    test_getSquareOfMatrixIfSymmetric_asymmetric();
    test_getSquareOfMatrixIfSymmetric_symmetricButMore();
    test_transposeIfMatrixHasNotEqualSumOfRows_squareUniqueSums();
    test_transposeIfMatrixHasNotEqualSumOfRows_freeShapeUniqueSums();
    test_transposeIfMatrixHasNotEqualSumOfRows_freeShapeSumsRepeated();
    test_isMutuallyInverseMatrices_inverse();
    test_isMutuallyInverseMatrices_notInverse();
    test_findSumOfMaxesOfPseudoDiagonal_RowsMoreThanCols();
    test_findSumOfMaxesOfPseudoDiagonal_ColsMoreThanRows();
    test_findSumOfMaxesOfPseudoDiagonal_square();
    test_findSumOfMaxesOfPseudoDiagonal_someMaxAtBeginningOfDiagonal();
    test_getMinInArea_areaStartsWithFirstElement();
    test_getMinInArea_areaStartsBelowFirstElement();
    test_getMinInArea_areaLeftEdgesFree();
    test_sortByDistances_rowsMoreThanCols();
    test_sortByDistances_colsMoreThanRows();
    test_sortByDistances_someDistancesAreEqual();
}

int main() {
    test();
    return 0;
}
