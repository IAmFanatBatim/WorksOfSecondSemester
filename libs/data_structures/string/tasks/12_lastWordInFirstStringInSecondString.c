#include <ctype.h>
#include "string_support_functions.c"

//Определяет последнее из слов первой строки, которое есть во второй строке.В
WordDescriptor lastWordInFirstStringInSecondString(char *s, WordDescriptor *w);

//<Автоматизированные тесты>

void test_lastWordInFirstStringInSecondString_noWordsFirst() {
    char s1[] = "";
    char s2[] = "apple";
    char s_result[MAX_STRING_SIZE];
    char s_expected[] = "";
    WordDescriptor word = lastWordInFirstStringInSecondString(s1, s2);
    wordDescriptorToString(word, s_result);
    assertString(s_expected, s_result);

}
void test_lastWordInFirstStringInSecondString_noWordsSecond() {
    char s1[] = "cherry";
    char s2[] = "";
    char s_result[MAX_STRING_SIZE];
    char s_expected[] = "";
    WordDescriptor word = lastWordInFirstStringInSecondString(s1, s2);
    wordDescriptorToString(word, s_result);
    assertString(s_expected, s_result);
}
void test_lastWordInFirstStringInSecondString_noCommonWords() {
    char s1[] = "cherry";
    char s2[] = "apple";
    char s_result[MAX_STRING_SIZE];
    char s_expected[] = "";
    WordDescriptor word = lastWordInFirstStringInSecondString(s1, s2);
    wordDescriptorToString(word, s_result);
    assertString(s_expected, s_result);
}
void test_lastWordInFirstStringInSecondString_oneCommonWord() {
    char s1[] = "cherry apple";
    char s2[] = "apple lemon banana";
    char s_result[MAX_STRING_SIZE];
    char s_expected[] = "apple";
    WordDescriptor word = lastWordInFirstStringInSecondString(s1, s2);
    wordDescriptorToString(word, s_result);
    assertString(s_expected, s_result);
}
void test_lastWordInFirstStringInSecondString_twoCommonWords() {
    char s1[] = "cherry apple";
    char s2[] = "apple lemon cherry banana";
    char s_result[MAX_STRING_SIZE];
    char s_expected[] = "apple";
    WordDescriptor word = lastWordInFirstStringInSecondString(s1, s2);
    wordDescriptorToString(word, s_result);
    assertString(s_expected, s_result);

}
void test_lastWordInFirstStringInSecondString() {
    test_lastWordInFirstStringInSecondString_noWordsFirst();
    test_lastWordInFirstStringInSecondString_noWordsSecond();
    test_lastWordInFirstStringInSecondString_noCommonWords();
    test_lastWordInFirstStringInSecondString_oneCommonWord();
    test_lastWordInFirstStringInSecondString_twoCommonWords();
}


int main() {
    test_lastWordInFirstStringInSecondString();
}

