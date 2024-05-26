#include <ctype.h>
#include <malloc.h>
#include "string_support_functions.c"

//записывает по адресу s_dest строку, в которой чередуются слова из строк s1 и s2
//если в одной из них слова заканчиваются раньше, чем во второй, оставшиеся слова записываются в конец
void alternatingWords(char *s1, char *s2, char *s_dest);

//<Автоматизированные тесты>

void test_alternatingWords_noWords() {
    char s1[] = "\t \n \t";
    char s2[] = "";
    char s_expected[] = "";
    char s_result[MAX_STRING_SIZE] = "";
    alternatingWords(s1, s2, s_result);
    assertString(s_expected, s_result);
}
void test_alternatingWords_oneWordInEvery() {
    char s1[] = "Sunny";
    char s2[] = "day";
    char s_expected[] = "Sunny day";
    char s_result[MAX_STRING_SIZE] = "";
    alternatingWords(s1, s2, s_result);
    assertString(s_expected, s_result);
}
void test_alternatingWords_equalAmountDifferentSpaces() {
    char s1[] = "Hello there folks!";
    char s2[] = "everyone";
    char s_expected[] = "Hello everyone there folks!";
    char s_result[MAX_STRING_SIZE] = "";
    alternatingWords(s1, s2, s_result);
    assertString(s_expected, s_result);
}
void test_alternatingWords_firstLonger() {
    char s1[] = "I know";
    char s2[] = "wanna more than that";
    char s_expected[] = "I wanna know more than that";
    char s_result[MAX_STRING_SIZE] = "";
    alternatingWords(s1, s2, s_result);
    assertString(s_expected, s_result);
}
void test_alternatingWords_firstShorter() {
    char s[] = "apple,madam,cherry,ada";
    assert(alternatingWords(s) == 2);
}
void test_alternatingWords() {
    test_alternatingWords_noWords();
    test_alternatingWords_oneWordInEvery();
    test_alternatingWords_equalAmountDifferentSpaces();
    test_alternatingWords_firstLonger();
    test_alternatingWords_firstShorter();
}

int main() {
    test_alternatingWords();
}



