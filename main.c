#include <assert.h>
#include "libs\data_structures\vector\vector.c"
#include "libs\data_structures\vectorVoid\vectorVoid.c"
#include "libs\data_structures\matrix\matrix.c"
void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 1);

    assert(v.data[0] == 1);
    assert(v.size == 1);
    assert(v.capacity == 1);
}

void test_pushBack_halfFullVector() {
    vector v = createVector(2);
    append_(v.data, &v.size, 1);
    pushBack(&v, 2);

    assert(v.data[1] == 2);
    assert(v.size == 2);
    assert(v.capacity == 2);
}

void test_pushBack_fullVector() {
    vector v = createVector(2);
    append_(v.data, &v.size, 1);
    append_(v.data, &v.size, 2);
    pushBack(&v, 3);

    assert(v.data[2] == 3);
    assert(v.size == 3);
    assert(v.capacity == 4);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_getVectorValue_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    assert(v.size == 3);
    assert(getVectorValue(&v, 0) == 1);
    assert(getVectorValue(&v, 1) == 2);
    assert(getVectorValue(&v, 2) == 3);
}

void test_isFull_fullVector() {
    vector v = createVector(2);
    pushBack(&v, 1);
    pushBack(&v, 2);
    assert(v.size == 2);
    assert(isFull(&v));
}

void test_isFull_notFullVector() {
    vector v = createVector(4);
    pushBack(&v, 1);
    pushBack(&v, 2);
    assert(v.size == 2);
    assert(!isFull(&v));
}

void test_isEmpty_emptyVector() {
    vector v = createVector(2);
    assert(v.size == 0);
    assert(isEmpty(&v));
}

void test_isEmpty_notEmptyVector() {
    vector v = createVector(4);
    pushBack(&v, 1);
    pushBack(&v, 2);
    assert(v.size == 2);
    assert(!isEmpty(&v));
}

void test_atVector_notEmptyVector() {
    vector v = createVector(4);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    assert(v.size == 3);
    assert(*atVector(&v, 1) == 2);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(4);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    assert(v.size == 3);
    assert(*atVector(&v, v.size - 1) == 3);
}

void test_back_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    assert(*back(&v) == 3);
}
void test_back_oneElementInVector() {
    vector v = createVector(0);
    pushBack(&v, 1);
    assert(*back(&v) == 1);
}

void test_front_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    assert(*front(&v) == 1);
}
void test_front_oneElementInVector() {
    vector v = createVector(0);
    pushBack(&v, 1);
    assert(*front(&v) == 1);
}

void test_shrinkToFit_halfFullVector() {
    vector v = createVector(4);
    pushBack(&v, 2);
    pushBack(&v, 3);
    assert(v.size == 2);

    shrinkToFit(&v);
    assert(v.capacity == 2);
}

void test_pushBackV_emptyVector() {
    vectorVoid v = createVectorV(0, sizeof(double));
    double x_src = 1.2;
    pushBackV(&v, &x_src);

    double x_dst;
    getVectorValueV(&v, 0, &x_dst);

    assert(are_double_equal(x_dst, 1.2));
    assert(v.size == 1);
    assert(v.capacity == 1);
}

void test_pushBackV_halfFullVector() {
    vectorVoid v = createVectorV(3, sizeof(double));
    double elements[2] = {1.2, 3};
    size_t len = 2;
    for (size_t i = 0; i < len; i++) {
        pushBackV(&v, &elements[i]);
    }
    double x_src = 6.66;
    pushBackV(&v, &x_src);

    double x_dst;
    getVectorValueV(&v, v.size - 1, &x_dst);

    assert(are_double_equal(x_dst, 6.66));
    assert(v.size == 3);
    assert(v.capacity == 3);
}

void test_pushBackV_fullVector() {
    vectorVoid v = createVectorV(2, sizeof(double));
    double elements[2] = {1.2, 3};
    size_t len = 2;
    for (size_t i = 0; i < len; i++) {
        pushBackV(&v, &elements[i]);
    }
    double x_src = 6.66;
    pushBackV(&v, &x_src);

    double x_dst;
    getVectorValueV(&v, v.size - 1, &x_dst);

    assert(are_double_equal(x_dst, 6.66));
    assert(v.size == 3);
    assert(v.capacity == 4);
}

void test_popBackV_notEmptyVector() {
    vectorVoid v = createVectorV(0, sizeof(double));
    double x_src = 6.66;
    pushBackV(&v, &x_src);
    assert(v.size == 1);

    popBackV(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_isFullV_fullVector() {
    vectorVoid v = createVectorV(1, sizeof(double));
    double x_src = 6.66;
    pushBackV(&v, &x_src);
    assert(v.size == 1);
    assert(isFullV(&v));
}

void test_isFullV_notFullVector() {
    vectorVoid v = createVectorV(2, sizeof(double));
    double x_src = 6.66;
    pushBackV(&v, &x_src);
    assert(v.size == 1);
    assert(!isFullV(&v));
}

void test_isEmptyV_emptyVector() {
    vectorVoid v = createVectorV(1, sizeof(double));
    assert(v.size == 0);
    assert(isEmptyV(&v));
}

void test_isEmptyV_notEmptyVector() {
    vectorVoid v = createVectorV(2, sizeof(double));
    double x_src = 6.66;
    pushBackV(&v, &x_src);
    assert(v.size == 1);
    assert(!isEmptyV(&v));
}

void test_shrinkToFitV_halfFullVector() {
    vectorVoid v = createVectorV(4, sizeof(double));
    double elements[2] = {1.2, 3};
    size_t len = 2;
    for (size_t i = 0; i < len; i++) {
        pushBackV(&v, &elements[i]);
    }
    assert(v.size == 2);
    shrinkToFitV(&v);
    assert(v.capacity == 2);
}

void test_vectors() {
    //Тестирование целочисленного вектора, vector
    test_pushBack_emptyVector();
    test_pushBack_halfFullVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_getVectorValue_notEmptyVector();
    test_isFull_fullVector();
    test_isFull_notFullVector();
    test_isEmpty_emptyVector();
    test_isEmpty_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_notEmptyVector();
    test_back_oneElementInVector();
    test_front_notEmptyVector();
    test_front_oneElementInVector();
    test_shrinkToFit_halfFullVector();

    //Тестирование вектора произвольного типа, vectorVoid
    test_pushBackV_emptyVector();
    test_pushBackV_halfFullVector();
    test_pushBackV_fullVector();
    test_popBackV_notEmptyVector();
    test_isFullV_fullVector();
    test_isFullV_notFullVector();
    test_isEmptyV_emptyVector();
    test_isEmptyV_notEmptyVector();
    test_shrinkToFitV_halfFullVector();
}

void test_swapRows() {
    matrix *mats = createArrayOfMatrixFromArray(
            (int []) {
                1, 2, 3,
                4, 5, 6,
                7, 8, 9,

                1, 3, 5,
                6,7, 8,
                2, 0, 3
                },
            2, 3, 3
    );
    matrix *result_mats = createArrayOfMatrixFromArray(
            (int []) {
                    7, 8, 9,
                    4, 5, 6,
                    1, 2, 3,

                    1, 3, 5,
                    2, 0, 3,
                    6, 7, 8
            },
            2, 3, 3
    );
    swapRows(&mats[0], 0, 2);
    swapRows(&mats[1], 1, 2);

    assert(areTwoMatricesEqual(&mats[0], &result_mats[0]));
    assert(areTwoMatricesEqual(&mats[1], &result_mats[1]));

    freeMemMatrices(mats, 2);
    freeMemMatrices(result_mats, 2);
}

void test_swapColumns() {
    matrix *mats = createArrayOfMatrixFromArray(
            (int []) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,

                    1, 3, 5,
                    6,7, 8,
                    2, 0, 3
            },
            2, 3, 3
    );
    matrix *result_mats = createArrayOfMatrixFromArray(
            (int []) {
                    3, 2, 1,
                    6, 5, 4,
                    9, 8, 7,

                    1, 5, 3,
                    6,8, 7,
                    2, 3, 0
            },
            2, 3, 3
    );
    swapColumns(&mats[0], 0, 2);
    swapColumns(&mats[1], 1, 2);

    assert(areTwoMatricesEqual(&mats[0], &result_mats[0]));
    assert(areTwoMatricesEqual(&mats[1], &result_mats[1]));

    freeMemMatrices(mats, 2);
    freeMemMatrices(result_mats, 2);
}

void test_insertionSortRowsMatrixByRowCriteria() {
    matrix *mats = createArrayOfMatrixFromArray(
            (int []) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,

                    1, 3, 5,
                    6,7, 8,
                    2, 0, 3
            },
            2, 3, 3
    );
    matrix *result_mats = createArrayOfMatrixFromArray(
            (int []) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,

                    2, 0, 3,
                    1, 3, 5,
                    6, 7, 8
            },
            2, 3, 3
    );
    insertionSortRowsMatrixByRowCriteria(&mats[0], getSum);
    insertionSortRowsMatrixByRowCriteria(&mats[1], getSum);

    assert(areTwoMatricesEqual(&mats[0], &result_mats[0]));
    assert(areTwoMatricesEqual(&mats[1], &result_mats[1]));

    freeMemMatrices(mats, 2);
    freeMemMatrices(result_mats, 2);
}

void test_selectionSortColsMatrixByColCriteria() {
    matrix *mats = createArrayOfMatrixFromArray(
            (int []) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,

                    5, 1, 5,
                    4, 8, 9,
                    9, 0, 1
            },
            2, 3, 3
    );
    matrix *result_mats = createArrayOfMatrixFromArray(
            (int []) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,

                    1, 5, 5,
                    8, 9, 4,
                    0, 1, 9
            },
            2, 3, 3
    );
    selectionSortColsMatrixByColCriteria(&mats[0], getSum);
    selectionSortColsMatrixByColCriteria(&mats[1], getSum);

    assert(areTwoMatricesEqual(&mats[0], &result_mats[0]));
    assert(areTwoMatricesEqual(&mats[1], &result_mats[1]));

    freeMemMatrices(mats, 2);
    freeMemMatrices(result_mats, 2);
}

void test_isSquareMatrix() {
    matrix mat1 = createMatrixFromArray(
            (int []) {
                1, 2, 3,
                4, 5, 6,
                7, 8, 9
        }, 3, 3
    );
    matrix mat2 = createMatrixFromArray(
            (int []) {
                    1, 2, 3,
                    4, 5, 6
            }, 2, 3
    );
    assert(isSquareMatrix(&mat1));
    assert(!isSquareMatrix(&mat2));

    freeMemMatrix(&mat1);
    freeMemMatrix(&mat2);
}

void test_isEMatrix() {
    matrix mat1 = createMatrixFromArray(
            (int []) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1
            }, 3, 3
    );
    matrix mat2 = createMatrixFromArray(
            (int []) {
                    1, 2, 3,
                    2, 1, 0,
                    4, 0, 1
            }, 3, 3
    );
    matrix mat3 = createMatrixFromArray(
            (int []) {
                    1, 0, 0,
                    0, 1, 0
            }, 2, 3
    );
    assert(isEMatrix(&mat1));
    assert(!isEMatrix(&mat2));
    assert(!isEMatrix(&mat3));

    freeMemMatrix(&mat1);
    freeMemMatrix(&mat2);
    freeMemMatrix(&mat3);
}

void test_isSymmetricMatrix() {
    matrix mat1 = createMatrixFromArray(
            (int []) {
                    1, 3, 5,
                    3, 1, 0,
                    5, 0, 1
            }, 3, 3
    );
    matrix mat2 = createMatrixFromArray(
            (int []) {
                    1, 2, 3,
                    2, 1, 0,
                    4, 0, 1
            }, 3, 3
    );
    matrix mat3 = createMatrixFromArray(
            (int []) {
                    1, 2, 3,
                    2, 1, 4
            }, 2, 3
    );
    assert(isSymmetricMatrix(&mat1));
    assert(!isSymmetricMatrix(&mat2));
    assert(!isSymmetricMatrix(&mat3));

    freeMemMatrix(&mat1);
    freeMemMatrix(&mat2);
    freeMemMatrix(&mat3);
}

void test_transposeSquareMatrix() {
    matrix *mats = createArrayOfMatrixFromArray(
            (int []) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,

                    1, 2, 3,
                    2, 8, 9,
                    3, 9, 1
            },
            2, 3, 3
    );
    matrix *result_mats = createArrayOfMatrixFromArray(
            (int []) {
                    1, 4, 7,
                    2, 5, 8,
                    3, 6, 9,

                    1, 2, 3,
                    2, 8, 9,
                    3, 9, 1
            },
            2, 3, 3
    );
    transposeSquareMatrix(&mats[0]);
    transposeSquareMatrix(&mats[1]);
    assert(areTwoMatricesEqual(&mats[0], &result_mats[0]));
    assert(areTwoMatricesEqual(&mats[1], &result_mats[1]));

    freeMemMatrices(mats, 2);
    freeMemMatrices(result_mats, 2);
}

void test_transposeMatrix() {
    matrix mat1 = createMatrixFromArray(
            (int []) {
                    1, 2,
                    3, 4,
                    5, 6,
            }, 3, 2
    );
    matrix mat2 = createMatrixFromArray(
            (int []) {
                    1, 2, 3,
                    4, 5, 6
            }, 2, 3
    );

    matrix mat1_transpose = createMatrixFromArray(
            (int []) {
                    1, 3, 5,
                    2, 4 ,6
            }, 2, 3
    );
    matrix mat2_transpose = createMatrixFromArray(
            (int []) {
                   1, 4,
                   2, 5,
                   3, 6
            }, 3, 2
    );
    transposeMatrix(&mat1);
    transposeMatrix(&mat2);

    assert(areTwoMatricesEqual(&mat1, &mat1_transpose));
    assert(areTwoMatricesEqual(&mat2, &mat2_transpose));

    freeMemMatrix(&mat1);
    freeMemMatrix(&mat2);
    freeMemMatrix(&mat1_transpose);
    freeMemMatrix(&mat2_transpose);
}

void test_getMinValuePos() {
    matrix *mats = createArrayOfMatrixFromArray(
            (int []) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,

                    1, 3, 5,
                    6, 7, 8,
                    2, 0, 3
            },
            2, 3, 3
    );

    assert(getMinValuePos(mats[0]).rowIndex == 0);
    assert(getMinValuePos(mats[0]).colIndex == 0);

    assert(getMinValuePos(mats[1]).rowIndex == 2);
    assert(getMinValuePos(mats[1]).colIndex == 1);

    freeMemMatrices(mats, 2);
}

void test_getMaxValuePos() {
    matrix *mats = createArrayOfMatrixFromArray(
            (int []) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,

                    1, 3, 5,
                    6, 7, 8,
                    2, 0, 3
            },
            2, 3, 3
    );

    assert(getMaxValuePos(mats[0]).rowIndex == 2);
    assert(getMaxValuePos(mats[0]).colIndex == 2);

    assert(getMaxValuePos(mats[1]).rowIndex == 1);
    assert(getMaxValuePos(mats[1]).colIndex == 2);

    freeMemMatrices(mats, 2);
}

void test_matrix () {
    //Тестирование матрицы, matrix
    test_swapRows();
    test_swapColumns();
    test_insertionSortRowsMatrixByRowCriteria();
    test_selectionSortColsMatrixByColCriteria();
    test_isSquareMatrix();
    test_isEMatrix();
    test_isSymmetricMatrix();
    test_transposeSquareMatrix();
    test_transposeMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
}

int main() {
    test_vectors();
    test_matrix();
    return 0;
}
