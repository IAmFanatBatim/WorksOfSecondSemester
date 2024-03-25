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

void test() {
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

int main() {
    //test();
    /*matrix *mats = getMemArrayOfMatrices(3, 2, 2);
    inputMatrices(mats, 3);
    outputMatrices(mats, 3);

    freeMemMatrix(&mats[1]);
    printf("%p", mats[1].values);*/
    matrix mat = getMemMatrix(3, 3);
    inputMatrix(&mat);
    /*swapRows(&mat, 1, 2);
    outputMatrix(mat);
    swapColumns(&mat, 1, 2);
    outputMatrix(mat);*/
    //insertionSortRowsMatrixByRowCriteria(&mat, getSum);
    //outputMatrix(mat);
    selectionSortColsMatrixByColCriteria(&mat, getSum);
    outputMatrix(mat);
    return 0;
}
