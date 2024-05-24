
#include <ctype.h>
#include <malloc.h>
#include "string_support_functions.c"

//преобразовывает строку, заменяя каждую цифру соответствующим ей числом пробелов.
void replace(char *s, char *w1, char *w2);

//<Автоматизированные тесты>

void test_replace_withEmpty() {
    char s[MAX_STRING_SIZE] = "No more damned tests!";
    char *w1 = "damned";
    char *w2 = "";
    char *s_expected = "No more  tests!";
    replace(s, w1, w2);
    assertString(s, s_expected);
}
void test_replace_withShorter() {
    char s[MAX_STRING_SIZE] = "Hello everyone!";
    char *w1 = "Hello";
    char *w2 = "Hi";
    char *s_expected = "Hi everyone!";
    replace(s, w1, w2);
    assertString(s, s_expected);
}
void test_replace_withLonger() {
    char s[MAX_STRING_SIZE] = "Hello everyone!";
    char *w1 = "Hello";
    char *w2 = "Goodbye";
    char *s_expected = "Goodbye everyone!";
    replace(s, w1, w2);
    assertString(s, s_expected);
}
void test_replace_notWordEntering() {
    char s[MAX_STRING_SIZE] = "Ich liebe dich";
    char *w1 = "Ich";
    char *w2 = "Wir";
    char *s_expected = "Wir liebe dich";
    replace(s, w1, w2);
    assertString(s, s_expected);
}
void test_replace() {
    test_replace_withEmpty();
    test_replace_withLonger();
    test_replace_withShorter();
    test_replace_notWordEntering();
}

int main() {
    test_replace();
}