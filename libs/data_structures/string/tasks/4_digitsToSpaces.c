#include <ctype.h>
#include "string_support_functions.c"

//преобразовывает строку, заменяя каждую цифру соответствующим ей числом пробелов.
void digitsToSpaces(char *s);

//<Автоматизированные тесты>

void test_digitsToSpaces_empty() {
    char s[] = "";
    char *s_expected = "";
    digitsToSpaces(s);
    assertString(s, s_expected);
}
void test_digitsToSpaces_noDigits() {
    char s[] = "No Hope";
    char *s_expected = "Ho Hope";
    digitsToSpaces(s);
    assertString(s_expected, s);
}
void test_digitsToSpaces_noIncreasingSize() {
    char s[] = "N1o H0op1e";
    char *s_expected = "N o Hop e";
    digitsToSpaces(s);
    assertString(s_expected, s);
}
void test_digitsToSpaces_increasingSize() {
    char s[] = "N3o H12ope";
    char *s_expected = "N   o H   ope";
    digitsToSpaces(s);
    assertString(s_expected, s);
}
void test_digitsToSpaces() {
    test_digitsToSpaces_empty();
    test_digitsToSpaces_noDigits();
    test_digitsToSpaces_noIncreasingSize();
    test_digitsToSpaces_increasingSize();
}

int main() {
    test_digitsToSpaces();
}
