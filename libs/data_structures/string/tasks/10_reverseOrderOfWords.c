#include <ctype.h>
#include <malloc.h>
#include "string_support_functions.c"

//преобразовывает строку, переставляя ее слов в обратном порядке
void reverseOrderOfWords(char *s);

void test_reverseOrderOfWords_empty() {
    char s[] = "";
    char s_expected[] = "";
    reverseOrderOfWords(s);
    assertString(s_expected, s);
}
void test_reverseOrderOfWords_noWords() {
    char s[] = "\t \n \t";
    char s_expected[] = "\t \n \t";
    reverseOrderOfWords(s);
    assertString(s_expected, s);
}
void test_reverseOrderOfWords_oneWord() {
    char s[] = "Apple";
    char s_expected[] = "Apple";
    reverseOrderOfWords(s);
    assertString(s_expected, s);
}
void test_reverseOrderOfWords_severalWords() {
    char s[] = "Apple Banana Lemon";
    char s_expected[] = "Lemon Banana Apple";
    reverseOrderOfWords(s);
    assertString(s_expected, s);
}
void test_reverseOrderOfWords_multiplySpaces() {
    char s[] = "Apple Banana    Lemon";
    char s_expected[] = "Lemon    Banana Apple";
    reverseOrderOfWords(s);
    assertString(s_expected, s);
}
void test_reverseOrderWords() {
    test_reverseOrderOfWords_empty();
    test_reverseOrderOfWords_noWords();
    test_reverseOrderOfWords_oneWord();
    test_reverseOrderOfWords_severalWords();
    test_reverseOrderOfWords_multiplySpaces();
}

void reverseOrderOfWords(char *s) {
    char *end_of_buffer = copy(s, s + strlen_(s), _stringBuffer) - 1;
    char *write_pinter = s;
    WordDescriptor word;
    while(getWordReverse(end_of_buffer, _stringBuffer - 1, &word)) {
        char *end_of_pasted_word = copy(word.begin, word.end, write_pinter);
        write_pinter = end_of_pasted_word;
        end_of_buffer = word.begin-1;
        while (isspace(*end_of_buffer) && end_of_buffer != _stringBuffer) {
            *write_pinter = *end_of_buffer;
            write_pinter++;
            end_of_buffer--;
        }
    }
}

int main() {
    test_reverseOrderWords();
}

