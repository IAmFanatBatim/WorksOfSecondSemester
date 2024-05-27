#include <ctype.h>
#include "string_support_functions.c"

typedef enum {
    FIRST_WORD_INTERSECTION,
    NOT_FOUND_A_WORD_INTERSECTION,
    WORD_FOUND,
    EMPTY_FIRST_STRING
} WordPrecedingStringIntersectionReturnCode;

//Определяет последнее из слов первой строки, которое есть во второй строке.
WordPrecedingStringIntersectionReturnCode getWordPrecedingStringIntersection(char *s1, char *s2, WordDescriptor *w);

//<Автоматизированные тесты>

void test_getWordPrecedingStringIntersection_noWords() {
    char s1[] = "";
    char s2[] = "\t \n \t";
    WordDescriptor word;
    assert(getWordPrecedingStringIntersection(s1, s2, &word) == EMPTY_FIRST_STRING);
}
void test_getWordPrecedingStringIntersection_noWordsFirst() {
    char s1[] = "";
    char s2[] = "apple";
    WordDescriptor word;
    assert(getWordPrecedingStringIntersection(s1, s2, &word) == EMPTY_FIRST_STRING);
}
void test_getWordPrecedingStringIntersection_noWordsSecond() {
    char s1[] = "cherry";
    char s2[] = "";
    WordDescriptor word;
    assert(getWordPrecedingStringIntersection(s1, s2, &word) == NOT_FOUND_A_WORD_INTERSECTION);
}
void test_getWordPrecedingStringIntersection_noCommonWords() {
    char s1[] = "cherry";
    char s2[] = "apple";
    WordDescriptor word;
    assert(getWordPrecedingStringIntersection(s1, s2, &word) == NOT_FOUND_A_WORD_INTERSECTION);
}
void test_getWordPrecedingStringIntersection_commonWordNotFirst() {
    char s1[] = "cherry apple";
    char s2[] = "apple lemon banana";
    char s_result[MAX_STRING_SIZE];
    char s_expected[] = "cherry";
    WordDescriptor word;
    assert(getWordPrecedingStringIntersection(s1, s2, &word) == WORD_FOUND);
    wordDescriptorToString(word, s_result);
    assertString(s_expected, s_result);
}
void test_getWordPrecedingStringIntersection_commonWordFirst() {
    char s1[] = "cherry apple";
    char s2[] = "lemon apple cherry banana";
    WordDescriptor word;
    assert(getWordPrecedingStringIntersection(s1, s2, &word) == FIRST_WORD_INTERSECTION);

}
void test_getWordPrecedingStringIntersection() {
    test_getWordPrecedingStringIntersection_noWordsFirst();
    test_getWordPrecedingStringIntersection_noWordsSecond();
    test_getWordPrecedingStringIntersection_noCommonWords();
    test_getWordPrecedingStringIntersection_commonWordNotFirst();
    test_getWordPrecedingStringIntersection_commonWordFirst();
}

WordPrecedingStringIntersectionReturnCode getWordPrecedingStringIntersection(char *s1, char *s2, WordDescriptor *w) {
}

int main() {
    test_getWordPrecedingStringIntersection();
}

