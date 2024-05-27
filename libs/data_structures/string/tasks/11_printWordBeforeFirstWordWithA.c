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
//<Автоматизированные тесты>

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
    char s[] = "lemon apple cherry";
    WordDescriptor word;
    assert(getWordBeforeFirstWordWithA(s, &word) == WORD_FOUND);
    char got[MAX_WORD_SIZE];
    copy(word.begin, word.end, got);
    got[word.end - word.begin] = '\0';
    assertString("lemon", got);
}
void test_getWordBeforeFirstWordWithA_wordFoundACapital() {
    char s[] = "Lemon Apple Cherry";
    WordDescriptor word;
    assert(getWordBeforeFirstWordWithA(s, &word) == WORD_FOUND);
    char got[MAX_WORD_SIZE];
    copy(word.begin, word.end, got);
    got[word.end - word.begin] = '\0';
    assertString("Lemon", got);

}
void test_reverseOrderWords() {
    test_getWordBeforeFirstWordWithA_noWords();
    test_getWordBeforeFirstWordWithA_noWordsWithA();
    test_getWordBeforeFirstWordWithA_firstWordWithA();
    test_getWordBeforeFirstWordWithA_wordFound();
    test_getWordBeforeFirstWordWithA_wordFoundACapital();
}

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, WordDescriptor *w) {
    WordDescriptor cur_word;
    bool is_word_without_a_found = false;
    bool is_word_with_a_found = false;

    while (getWord(s, &cur_word) && !is_word_with_a_found) {
        char *cur_char_of_word = cur_word.begin;
        while (cur_char_of_word != cur_word.end) {
            if (*cur_char_of_word == 'a' || *cur_char_of_word == 'A') {
                is_word_with_a_found = true;
                break;
            }
            cur_char_of_word++;
        }
        if (!is_word_with_a_found) {
            is_word_without_a_found = true;
            *w = cur_word;
        }
        s = cur_word.end;
    }

    if (is_word_with_a_found && is_word_without_a_found) {
        char *cur_word_pointer = w->begin;
        while (cur_word_pointer != w->end) {
            printf("%c", *cur_word_pointer);
            cur_word_pointer++;
        }
        printf("\n");
        return WORD_FOUND;
    } else if (is_word_with_a_found) {
        printf("First word contains 'a' letter\n");
        return FIRST_WORD_WITH_A;
    } else if (is_word_without_a_found) {
        printf("There are no words in 'a' letter the string\n");
        return NOT_FOUND_A_WORD_WITH_A;
    } else {
        printf("There are no words in the string\n");
        return EMPTY_STRING;
    }
}

int main() {
    test_reverseOrderWords();
}

