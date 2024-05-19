#include "string_.c"
#include "assert.h"

void strlen_test_commonString() {
    char *s = "Hello!";
    assert(strlen_(s) == 6);
}

void strlen_test_hasControlCharacters() {
    char *s = "\t\"Hello!\"";
    assert(strlen_(s) == 9);
}

void strlen_test_hasEscapingCharacters() {
    char *s = "\\tHello!\\t";
    assert(strlen_(s) == 10);
}

void strlen_test_moreMemoryThanNeed() {
    char s[14] = "Hello!";
    assert(strlen_(s) == 6);
}

void strlen_test_emptyString() {
    char s[14] = "Hello!";
    assert(strlen_(s) == 6);
}

void strlen_test() {
    strlen_test_commonString();
    strlen_test_hasControlCharacters();
    strlen_test_hasEscapingCharacters();
    strlen_test_moreMemoryThanNeed();
    strlen_test_emptyString();
}

void string_test() {
    strlen_test();
}

int main () {
    string_test();
}