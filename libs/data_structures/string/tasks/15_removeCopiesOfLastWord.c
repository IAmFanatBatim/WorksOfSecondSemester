#include <ctype.h>
#include "string_support_functions.c"
#include <stdlib.h>

//Удаляет из строки копии последнего слова
void removeCopiesOfLastWord(char *s);

//<Автоматизированные тесты>

void test_removeCopiesOfLastWord_noWords() {
    char s[] = "";
    char s_expected[] = "";
    removeCopiesOfLastWord(s);
    assertString(s_expected, s);
}
void test_removeCopiesOfLastWord_oneWord() {
    char s[] = "apple";
    char s_expected[] = "";
    removeCopiesOfLastWord(s);
    assertString(s_expected, s);
}
void test_removeCopiesOfLastWord_allWordsAreSame() {
    char s[] = "apple apple apple";
    char s_expected[] = "";
    removeCopiesOfLastWord(s);
    assertString(s_expected, s);
}
void test_removeCopiesOfLastWord_allWordsAreDifferent() {
    char s[] = "apple lemon banana";
    char s_expected[] = "apple lemon";
    removeCopiesOfLastWord(s);
    assertString(s_expected, s);
}
void test_removeCopiesOfLastWord_diverseWords() {
    char s[] = "apple lemon banana lemon";
    char s_expected[] = "apple banana";
    removeCopiesOfLastWord(s);
    assertString(s_expected, s);
}
void test_removeCopiesOfLastWord() {
    test_removeCopiesOfLastWord_noWords();
    test_removeCopiesOfLastWord_oneWord();
    test_removeCopiesOfLastWord_allWordsAreSame();
    test_removeCopiesOfLastWord_allWordsAreDifferent();
    test_removeCopiesOfLastWord_diverseWords();
}

int main() {
    test_removeCopiesOfLastWord();
}

