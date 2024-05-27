#include <ctype.h>
#include "string_support_functions.c"

//Определяет, есть ли в данной строке одинаковые слова
bool areIdenticalWordsInString(char *s);

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

bool areIdenticalWordsInString(char *s) {
    getBagOfWords(&_bag, s);
    bool has_equal = false;
    for (int first_word_index = 0; first_word_index < _bag.size - 1 && !has_equal; first_word_index++) {
        for (int second_word_index = first_word_index + 1; second_word_index < _bag.size && !has_equal; second_word_index++) {
            if (areWordsEqual(_bag.words[first_word_index], _bag.words[second_word_index]) == 0) {
                has_equal = true;
            }
        }
    }
    return has_equal;
}

int main() {
    test_areIdenticalWordsInString();
    printf("All is okay");
}

