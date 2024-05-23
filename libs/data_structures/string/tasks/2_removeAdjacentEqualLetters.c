#include <ctype.h>
#include "string_support_functions.c"
#define assertString(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)

//Удаляет из строки s все пробельные символы
void removeAdjacentEqualLetters(char *s);

void test_removeAdjacentEqualLetters_empty() {
    char s[] = "";
    char *s_expected = "";
    removeAdjacentEqualLetters(s);
    assertString(s, s_expected);
}
void test_removeAdjacentEqualLetters_oneCharacter() {
    char s[] = "o";
    char *s_expected = "o";
    removeAdjacentEqualLetters(s);
    assertString(s_expected, s);
}
void test_removeAdjacentEqualLetters_oneChain() {
    char s[] = "oooo";
    char *s_expected = "o";
    removeAdjacentEqualLetters(s);
    assertString(s_expected, s);
}
void test_removeAdjacentEqualLetters_chainsInRow() {
    char s[] = "ooooaaaaaaaoo";
    char *s_expected = "oao";
    removeAdjacentEqualLetters(s);
    assertString(s_expected, s);
}
void test_removeAdjacentEqualLetters_chainsWithInterval() {
    char s[] = "Hooow boooorinnng";
    char *s_expected = "How boring";
    removeAdjacentEqualLetters(s);
    assertString(s_expected, s);
}
void test_removeAdjacentEqualLetters() {
    test_removeAdjacentEqualLetters_empty();
    test_removeAdjacentEqualLetters_oneCharacter();
    test_removeAdjacentEqualLetters_oneChain();
    test_removeAdjacentEqualLetters_chainsInRow();
    test_removeAdjacentEqualLetters_chainsWithInterval();
}

//Удаляет из строки s все пробельные символы
void removeAdjacentEqualLetters(char *s) {
    char *pointer_by_written = s;
    char *endSource = getEndOfString(s);
    char *curSource = s;
    if (curSource != endSource) {
        *pointer_by_written = *curSource;
        curSource++;
        while (curSource != endSource) {
            if (*pointer_by_written != *curSource) {
                pointer_by_written++;
                *pointer_by_written = *curSource;
            }
            curSource++;
        }
        pointer_by_written++;
        *pointer_by_written = '\0';
    }
}

int main() {
    test_removeAdjacentEqualLetters();
}
