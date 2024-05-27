#include <ctype.h>
#include "string_support_functions.c"

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

//Выводит слово данной строки, предшествующее первому из слов, содержащих букву "а". Регистр значения не имеет.
WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, WordDescriptor *w);

void test_getWordBeforeFirstWordWithA_noWords() {
    char s[] = "\t \n \t";
    WordDescriptor word;
    assert(getWordBeforeFirstWordWithA(s, &word) == EMPTY_STRING);
}
void test_getWordBeforeFirstWordWithA_noWordsWithA() {
    char s[] = "cherry";
    WordDescriptor word;
    assert(getWordBeforeFirstWordWithA(s, &word) == NOT_FOUND_A_WORD_WITH_A);
}
void test_getWordBeforeFirstWordWithA_firstWordWithA() {
    char s[] = "apple";
    WordDescriptor word;
    assert(getWordBeforeFirstWordWithA(s, &word) == FIRST_WORD_WITH_A);
}
void test_getWordBeforeFirstWordWithA_wordFound() {
    char s[] = "banana apple cherry";
    WordDescriptor word;
    assert(getWordBeforeFirstWordWithA(s, &word) == WORD_FOUND);
    char got[MAX_WORD_SIZE];
    copy(word.begin, word.end, got);
    got[word.end - word.begin] = '\0';
    assertString("banana", got);
}
void test_getWordBeforeFirstWordWithA_wordFoundACapital() {
    char s[] = "Banana Apple Cherry";
    WordDescriptor word;
    assert(getWordBeforeFirstWordWithA(s, &word) == WORD_FOUND);
    char got[MAX_WORD_SIZE];
    copy(word.begin, word.end, got);
    got[word.end - word.begin] = '\0';
    assertString("Banana", got);

}
void test_reverseOrderWords() {
    test_getWordBeforeFirstWordWithA_noWords();
    test_getWordBeforeFirstWordWithA_noWordsWithA();
    test_getWordBeforeFirstWordWithA_firstWordWithA();
    test_getWordBeforeFirstWordWithA_wordFound();
    test_getWordBeforeFirstWordWithA_wordFoundACapital();
}

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, WordDescriptor *w) {

}

int main() {
    test_reverseOrderWords();
}

