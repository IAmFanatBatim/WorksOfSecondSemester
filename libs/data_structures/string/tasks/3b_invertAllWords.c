#include <ctype.h>
#include "string_support_functions.c"

//Инвертирует все слова в строке
void invertAllWords(char *s);

//<Автоматизированные тесты>

void test_invertAllWords_empty() {
    char s[] = "";
    char *s_expected = "";
    invertAllWords(s);
    assertString(s, s_expected);
}
void test_invertAllWords_noWords() {
    char s[] = "\t \n";
    char *s_expected = "\t \n";
    invertAllWords(s);
    assertString(s_expected, s);
}
void test_invertAllWords_oneWord() {
    char s[] = "l0v3";
    char *s_expected = "3v0l";
    invertAllWords(s);
    assertString(s_expected, s);
}
void test_invertAllWords_diverseWords() {
    char s[] = "my s7r0ng\tp4ssw0rd 1234";
    char *s_expected = "ym gn0r7s\tdr0wss4p 4321";
    invertAllWords(s);
    assertString(s_expected, s);
}
void test_invertAllWords() {
    test_invertAllWords_empty();
    test_invertAllWords_noWords();
    test_invertAllWords_oneWord();
    test_invertAllWords_diverseWords();
}

void invertAllWords(char *s) {
    WordDescriptor word;
    while (getWord(s, &word)) {
        char *start_point = word.begin;
        char *end_point = word.end-1;
        while (start_point < end_point) {
            char temp = *start_point;
            *start_point = *end_point;
            *end_point = temp;
            start_point++;
            end_point--;
        }
        s = word.end;
    }
}

int main() {
    test_invertAllWords();
}
