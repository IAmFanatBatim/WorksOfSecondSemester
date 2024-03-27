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

void test () {
    test_swapRowsWithMaxAndMinElement_commonMatrix();
    test_swapRowsWithMaxAndMinElement_MaxMinInOneRow();
}

int main() {
    test();
    return 0;
}
