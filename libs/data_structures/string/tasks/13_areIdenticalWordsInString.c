#include <ctype.h>
#include "string_support_functions.c"

//Определяет, есть ли в данной строке слова, составленные из одинакового набора букв
bool areIdenticalLetterSetsInString(char *s);

//<Автоматизированные тесты>

void test_areIdenticalLetterSetsInString_noWords() {
    char s[] = "";
    assert(areIdenticalLetterSetsInString(s) == 0);
}
void test_areIdenticalLetterSetsInString_oneWord() {
    char s[] = "apple";
    assert(areIdenticalLetterSetsInString(s) == 0);
}
void test_areIdenticalLetterSetsInString_noIdenticalLetterSets() {
    char s[] = "apple lemon banana";
    assert(areIdenticalLetterSetsInString(s) == 0);
}
void test_areIdenticalLetterSetsInString_hasIncludedLetterSets() {
    char s[] = "apple lemon pal";
    assert(areIdenticalLetterSetsInString(s) == 0);
}
void test_areIdenticalLetterSetsInString_hasIdenticalLetterSets() {
    char s[] = "apple lemon menol banana";
    assert(areIdenticalLetterSetsInString(s) == 1);

}
void test_areIdenticalLetterSetsInString() {
    test_areIdenticalLetterSetsInString_noWords();
    test_areIdenticalLetterSetsInString_oneWord();
    test_areIdenticalLetterSetsInString_noIdenticalLetterSets();
    test_areIdenticalLetterSetsInString_hasIncludedLetterSets();
    test_areIdenticalLetterSetsInString_hasIdenticalLetterSets();
}

int main() {
    test_areIdenticalLetterSetsInString();
    printf("All is okay");
}

