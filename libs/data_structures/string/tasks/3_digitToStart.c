#include <ctype.h>
#include "string_support_functions.c"

//Преобразовывает строку так, чтобы цифры каждого слова были перенесены в начало слова в обратном порядке,
//а буквы – в конец слова, без изменения порядка следования.
void digitToStart(char *s);

void test_digitToStart_empty() {
    char s[] = "";
    char *s_expected = "";
    digitToStart(s);
    assertString(s, s_expected);
}
void test_digitToStart_noWords() {
    char s[] = "\t\n";
    char *s_expected = "\t \n";
    digitToStart(s);
    assertString(s_expected, s);
}
void test_digitToStart_oneWord() {
    char s[] = "l0v3";
    char *s_expected = "30lv";
    digitToStart(s);
    assertString(s_expected, s);
}
void test_digitToStart_diverseWords() {
    char s[] = "my,s7r0ng\tp4ssw0rd 1234";
    char *s_expected = "my 07srng\t04psswrd 4321";
    digitToStart(s);
    assertString(s_expected, s);
}

void test_digitToStart() {
    test_digitToStart_empty();
    test_digitToStart_noWords();
    test_digitToStart_oneWord();
    test_digitToStart_diverseWords();
}


int main() {
    test_digitToStart();
}
