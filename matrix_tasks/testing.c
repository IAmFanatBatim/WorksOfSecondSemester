#include <stdio.h>
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
                    6, 0, 1
            }, 4, 3
    );
    matrix mat_result = createMatrixFromArray(
            (int[]) {
                    6, 0, 1,
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

void test () {
    test_swapRowsWithMaxAndMinElement_commonMatrix();
    test_swapRowsWithMaxAndMinElement_MaxMinInOneRow();
    test_sortRowsByMaxElement_matrixOfUnique();
    test_sortRowsByMaxElement_maxRepeating();
    test_sortRowsByMaxElement_noNeedToSort();
    test_sortColsByMinElement_matrixOfUnique();
    test_sortColsByMinElement_minRepeating();
    test_sortColsByMinElement_noNeedToSort();
}

int main() {
    test();
    return 0;
}
