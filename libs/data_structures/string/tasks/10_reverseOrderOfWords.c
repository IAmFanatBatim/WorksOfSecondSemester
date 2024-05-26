#include <ctype.h>
#include <malloc.h>
#include "string_support_functions.c"

//преобразовывает строку, переставляя ее слов в обратном порядке
void reverseOrderOfWords(char *s);

void test_reverseOrderOfWords_empty() {
    char s[] = "";
    char s_expected[] = "";
    reverseOrderOfWords(s);
    assertString(s_expected, s);
}
void test_reverseOrderOfWords_noWords() {
    char s[] = "\t \n \t";
    char s_expected[] = "\t \n \t";
    reverseOrderOfWords(s);
    assertString(s_expected, s);
}
void test_reverseOrderOfWords_oneWord() {
    char s[] = "Apple";
    char s_expected[] = "Apple";
    reverseOrderOfWords(s);
    assertString(s_expected, s);
}
void test_reverseOrderOfWords_severalWords() {
    char s[] = "Apple Banana Lemon";
    char s_expected[] = "Lemon Banana Apple";
    reverseOrderOfWords(s);
    assertString(s_expected, s);
}
void test_reverseOrderWords() {
    test_reverseOrderOfWords_empty();
    test_reverseOrderOfWords_noWords();
    test_reverseOrderOfWords_oneWord();
    test_reverseOrderOfWords_severalWords();
}

int main() {
    test_reverseOrderWords();
}

