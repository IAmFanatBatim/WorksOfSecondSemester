#include <ctype.h>
#include "string_support_functions.c"


//<Автоматизированные тесты>

void test_areIdenticalWordsInString_noWords() {
    char s[] = "";
    assert(areIdenticalWordsInString(s) == 0);
}
void test_areIdenticalWordsInString_oneWord() {
    char s[] = "apple";
    assert(areIdenticalWordsInString(s) == 0);
}
void test_areIdenticalWordsInString_noIdenticalWords() {
    char s[] = "apple lemon banana";
    assert(areIdenticalWordsInString(s) == 0);
}
void test_areIdenticalWordsInString_hasIdenticalWords() {
    char s[] = "apple lemon apple banana";
    assert(areIdenticalWordsInString(s) == 1);
}
void test_areIdenticalWordsInString_hasMoreIdenticalWords() {
    char s[] = "apple lemon apple apple";
    assert(areIdenticalWordsInString(s) == 1);

}
void test_areIdenticalWordsInString() {
    test_areIdenticalWordsInString_noWords();
    test_areIdenticalWordsInString_oneWord();
    test_areIdenticalWordsInString_noIdenticalWords();
    test_areIdenticalWordsInString_hasIdenticalWords();
    test_areIdenticalWordsInString_hasMoreIdenticalWords();
}


int main() {
    test_areIdenticalWordsInString();
    printf("All is okay");
}
