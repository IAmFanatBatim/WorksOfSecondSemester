#include <ctype.h>
#include "string_support_functions.c"
#define assertString(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)

//Удаляет из строки s все пробельные символы
void removeNonLetters(char *s);

void test_removeNonLetters_diverse() {
    char s[] = "You cried for help \n\t - but nobody came";
    char *s_expected = "Youcriedforhelp-butnobodycame";
    removeNonLetters(s);
    assertString(s_expected, s);
}
void test_removeNonLetters_onlySpaces() {
    char s[] = "\t \n\t \n\t ";
    char *s_expected = "";
    removeNonLetters(s);
    assertString(s_expected, s);
}
void test_removeNonLetters_noSpaces() {
    char s[] = "Hello!";
    char *s_expected = "Hello!";
    removeNonLetters(s);
    assertString(s_expected, s);
}
void test_removeNonLetters_escapedSpaces() {
    char s[] = "\\t\\n\\t";
    char *s_expected = "\\t\\n\\t";
    removeNonLetters(s);
    assertString(s_expected, s);
}
void test_removeNonLetters() {
    test_removeNonLetters_diverse();
    test_removeNonLetters_onlySpaces();
    test_removeNonLetters_noSpaces();
    test_removeNonLetters_escapedSpaces();
}

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

int main() {
    test_removeNonLetters();
}
