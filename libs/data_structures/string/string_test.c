#include "string_.c"
#include "assert.h"

void test_strlen_commonString() {
    char *s = "Hello!";
    assert(strlen_(s) == 6);
}
void test_strlen_hasControlCharacters() {
    char *s = "\t\"Hello!\"";
    assert(strlen_(s) == 9);
}
void test_strlen_hasEscapingCharacters() {
    char *s = "\\tHello!\\t";
    assert(strlen_(s) == 10);
}
void test_strlen_moreMemoryThanNeed() {
    char s[14] = "Hello!";
    assert(strlen_(s) == 6);
}
void test_strlen_emptyString() {
    char s[14] = "Hello!";
    assert(strlen_(s) == 6);
}
void test_strlen_() {
    test_strlen_commonString();
    test_strlen_hasControlCharacters();
    test_strlen_hasEscapingCharacters();
    test_strlen_moreMemoryThanNeed();
    test_strlen_emptyString();
}

void test() {
    test_strlen_();
}

int main () {
    test();
    printf("All is okay");
    return 0;
}