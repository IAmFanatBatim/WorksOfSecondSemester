#include <ctype.h>
#include "string_support_functions.c"
#include <stdlib.h>

//Удаляет из строки слова, содержащие заданную последовательность символов
void removeWordsWithSomeChain(char *s, char *chain);

//<Автоматизированные тесты>

void test_removeWordsWithSomeChain_empty() {
    char s[] = "";
    char chain[] = "abc";
    char s_expected[] = "";
    removeWordsWithSomeChain(s, chain);
    assertString(s_expected, s);
}
void test_removeWordsWithSomeChain_noWords() {
    char s[] = "\t \n \t";
    char chain[] = "abc";
    char s_expected[] = "";
    removeWordsWithSomeChain(s, chain);
    assertString(s_expected, s);
}
void test_removeWordsWithSomeChain_noDeletions() {
    char s[] = "cherry";
    char chain[] = "abc";
    char s_expected[] = "";
    removeWordsWithSomeChain(s, chain);
    assertString(s_expected, s);
}
void test_removeWordsWithSomeChain_allDeletions() {
    char s[] = "cherry";
    char chain[] = "her";
    char s_expected[] = "";
    removeWordsWithSomeChain(s, chain);
    assertString(s_expected, s);
}
void test_removeWordsWithSomeChain_someDeletions() {
    char s[] = "cherry lady apple hero";
    char chain[] = "her";
    char s_expected[] = "lady hero";
    removeWordsWithSomeChain(s, chain);
    assertString(s_expected, s);
}
void test_removeWordsWithSomeChain_emptyChain() {
    char s[] = "cherry lady apple hero";
    char chain[] = "";
    char s_expected[] = "cherry lady apple hero";
    removeWordsWithSomeChain(s, chain);
    assertString(s_expected, s);
}
void test_removeWordsWithSomeChain() {
    test_removeWordsWithSomeChain_empty();
    test_removeWordsWithSomeChain_noWords();
    test_removeWordsWithSomeChain_noDeletions();
    test_removeWordsWithSomeChain_allDeletions();
    test_removeWordsWithSomeChain_someDeletions();
    test_removeWordsWithSomeChain_empty();
}

void removeWordsWithSomeChain(char *s, char *chain) {

}

int main() {
    test_removeWordsWithSomeChain();
}

