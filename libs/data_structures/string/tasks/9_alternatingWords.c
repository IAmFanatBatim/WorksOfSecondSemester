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
    char s1[] = "I\tlike";
    char s2[] = "draw\ncats";
    char s_expected[] = "I draw like cats";
    char s_result[MAX_STRING_SIZE] = "";
    alternatingWords(s1, s2, s_result);
    assertString(s_expected, s_result);
}
void test_alternatingWords_firstLonger() {
    char s1[] = "Hello there folks!";
    char s2[] = "everyone";
    char s_expected[] = "Hello everyone there folks!";
    char s_result[MAX_STRING_SIZE] = "";
    alternatingWords(s1, s2, s_result);
    assertString(s_expected, s_result);
}
void test_alternatingWords_firstShorter() {
    char s1[] = "I know";
    char s2[] = "wanna more than that";
    char s_expected[] = "I wanna know more than that";
    char s_result[MAX_STRING_SIZE] = "";
    alternatingWords(s1, s2, s_result);
    assertString(s_expected, s_result);
}
void test_alternatingWords() {
    test_alternatingWords_noWords();
    test_alternatingWords_oneWordInEvery();
    test_alternatingWords_equalAmountDifferentSpaces();
    test_alternatingWords_firstLonger();
    test_alternatingWords_firstShorter();
}

void alternatingWords(char *s1, char *s2, char *s_dest) {
    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {
        if (isW1Found) {
            char *end_of_result = copy(word1.begin, word1.end, s_dest);
            *end_of_result = ' ';
            s_dest = end_of_result + 1;
            beginSearch1 = word1.end;
        } if (isW2Found) {
            char *end_of_result = copy(word2.begin, word2.end, s_dest);
            *end_of_result = ' ';
            s_dest = end_of_result + 1;
            beginSearch2 = word2.end;
        }
    }
    s_dest--;
    *s_dest = '\0';
}

int main() {
    test_alternatingWords();
}



