#include <ctype.h>
#include "string_support_functions.c"

//Определяет последнее из слов первой строки, которое есть во второй строке.
WordDescriptor lastWordInFirstStringInSecondString(char *s1, char *s2);

//<Автоматизированные тесты>

void test_lastWordInFirstStringInSecondString_noWordsFirst() {
    char s1[] = "";
    char s2[] = "apple";
    char s_result[MAX_STRING_SIZE];
    char s_expected[] = "";
    WordDescriptor word = lastWordInFirstStringInSecondString(s1, s2);
    wordDescriptorToString(word, s_result);
    assertString(s_expected, s_result);

}
void test_lastWordInFirstStringInSecondString_noWordsSecond() {
    char s1[] = "cherry";
    char s2[] = "";
    char s_result[MAX_STRING_SIZE];
    char s_expected[] = "";
    WordDescriptor word = lastWordInFirstStringInSecondString(s1, s2);
    wordDescriptorToString(word, s_result);
    assertString(s_expected, s_result);
}
void test_lastWordInFirstStringInSecondString_noCommonWords() {
    char s1[] = "cherry";
    char s2[] = "apple";
    char s_result[MAX_STRING_SIZE];
    char s_expected[] = "";
    WordDescriptor word = lastWordInFirstStringInSecondString(s1, s2);
    wordDescriptorToString(word, s_result);
    assertString(s_expected, s_result);
}
void test_lastWordInFirstStringInSecondString_oneCommonWord() {
    char s1[] = "cherry apple";
    char s2[] = "apple lemon banana";
    char s_result[MAX_STRING_SIZE];
    char s_expected[] = "apple";
    WordDescriptor word = lastWordInFirstStringInSecondString(s1, s2);
    wordDescriptorToString(word, s_result);
    assertString(s_expected, s_result);
}
void test_lastWordInFirstStringInSecondString_twoCommonWords() {
    char s1[] = "cherry apple";
    char s2[] = "lemon apple cherry banana";
    char s_result[MAX_STRING_SIZE];
    char s_expected[] = "apple";
    WordDescriptor word = lastWordInFirstStringInSecondString(s1, s2);
    wordDescriptorToString(word, s_result);
    assertString(s_expected, s_result);

}
void test_lastWordInFirstStringInSecondString() {
    test_lastWordInFirstStringInSecondString_noWordsFirst();
    test_lastWordInFirstStringInSecondString_noWordsSecond();
    test_lastWordInFirstStringInSecondString_noCommonWords();
    test_lastWordInFirstStringInSecondString_oneCommonWord();
    test_lastWordInFirstStringInSecondString_twoCommonWords();
}

WordDescriptor lastWordInFirstStringInSecondString(char *s1, char *s2) {
    WordDescriptor cur_last_word;
    cur_last_word.begin = s1;
    cur_last_word.end = s1;
    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);
    for (int first_bag_index = 0; first_bag_index < _bag.size; first_bag_index++) {
        bool is_pair_found = false;
        for (int second_bag_index = 0; second_bag_index < _bag.size && !is_pair_found; second_bag_index++) {
            if (areWordsEqual(_bag.words[first_bag_index], _bag2.words[second_bag_index]) == 0) {
                cur_last_word = _bag.words[first_bag_index];
                is_pair_found = true;
            }
        }
    }
    return cur_last_word;
}

int main() {
    test_lastWordInFirstStringInSecondString();
}

