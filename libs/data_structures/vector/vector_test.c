#include <assert.h>
#include "vector.c"
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
    assert(!isFull(&v));
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

void test_back_emptyVector() {
    vector v = createVector(0);
    back(&v);
}


void test() {
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
}

int main() {
    test();
    return 0;
}