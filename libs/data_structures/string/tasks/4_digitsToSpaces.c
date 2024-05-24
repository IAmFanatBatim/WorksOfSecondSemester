#include <ctype.h>
#include <malloc.h>
#include "string_support_functions.c"

//преобразовывает строку, заменяя каждую цифру соответствующим ей числом пробелов.
void digitsToSpaces(char *s);

//<Автоматизированные тесты>

void test_digitsToSpaces_empty() {
    char s[MAX_STRING_SIZE] = "";
    char *s_expected = "";
    digitsToSpaces(s);
    assertString(s, s_expected);
}
void test_digitsToSpaces_noDigits() {
    char s[MAX_STRING_SIZE] = "No Hope";
    char *s_expected = "No Hope";
    digitsToSpaces(s);
    assertString(s_expected, s);
}
void test_digitsToSpaces_noIncreasingSize() {
    char s[MAX_STRING_SIZE] = "N1o H0op1e";
    char *s_expected = "N o Hop e";
    digitsToSpaces(s);
    assertString(s_expected, s);
}
void test_digitsToSpaces_increasingSize() {
    char s[MAX_STRING_SIZE] = "N3o H12ope";
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

void digitsToSpaces(char *s) {
    char *begin_of_buffer = _stringBuffer;
    char *end_of_buffer = copy(s, s + strlen_(s), _stringBuffer);
    while (begin_of_buffer != end_of_buffer) {
        if (isdigit(*begin_of_buffer)) {
            for (int i = 0; i < *begin_of_buffer - '0'; i++) {
                *s = ' ';
                s++;
            }
        } else {
            *s = *begin_of_buffer;
            s++;
        }
        begin_of_buffer++;
    }
    *s = '\0';
}

int main() {
    test_digitsToSpaces();
}
