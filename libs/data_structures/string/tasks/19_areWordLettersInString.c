#include <ctype.h>
#include "string_support_functions.c"
#include <stdlib.h>

//Удаляет из строки слова, содержащие заданную последовательность символов
bool areWordLettersInString(char *s, char *word);

//<Автоматизированные тесты>

void test_areWordLettersInString_allEmpty() {
    char s[] = "";
    char word[] = "";
    assert(areWordLettersInString(s, word) == true);
}
void test_areWordLettersInString_emptyWord() {
    char s[] = "cherry";
    char word[] = "";
    assert(areWordLettersInString(s, word) == true);
}
void test_areWordLettersInString_emptyString() {
    char s[] = "";
    char word[] = "her";
    assert(areWordLettersInString(s, word) == false);
}
void test_areWordLettersInString_allLettersIn() {
    char s[] = "cherry lady";
    char word[] = "dear";
    assert(areWordLettersInString(s, word) == true);
}
void test_areWordLettersInString_someLettersIn() {
    char s[] = "cherry lady";
    char word[] = "love";
    assert(areWordLettersInString(s, word) == false);
}

void test_areWordLettersInString() {
    test_areWordLettersInString_allEmpty();
    test_areWordLettersInString_emptyWord();
    test_areWordLettersInString_emptyString();
    test_areWordLettersInString_allLettersIn();
    test_areWordLettersInString_someLettersIn();
}

int main() {
    test_areWordLettersInString();
    printf("All is okay");
}

