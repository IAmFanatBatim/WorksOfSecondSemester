#include <ctype.h>
#include "string_support_functions.c"

typedef enum {
    FIRST_WORD_INTERSECTION,
    NOT_FOUND_WORD_INTERSECTION,
    WORD_FOUND,
    EMPTY_FIRST_STRING
} WordPrecedingStringIntersectionReturnCode;

//Сохраняет в структуру w и выводит слово, предшествующее в строке s1 первому слову, встречающемуся в обеих строках.
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
    assert(getWordPrecedingStringIntersection(s1, s2, &word) == NOT_FOUND_WORD_INTERSECTION);
}
void test_getWordPrecedingStringIntersection_noCommonWords() {
    char s1[] = "cherry";
    char s2[] = "apple";
    WordDescriptor word;
    assert(getWordPrecedingStringIntersection(s1, s2, &word) == NOT_FOUND_WORD_INTERSECTION);
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
    test_getWordPrecedingStringIntersection_noWords();
    test_getWordPrecedingStringIntersection_noWordsFirst();
    test_getWordPrecedingStringIntersection_noWordsSecond();
    test_getWordPrecedingStringIntersection_noCommonWords();
    test_getWordPrecedingStringIntersection_commonWordNotFirst();
    test_getWordPrecedingStringIntersection_commonWordFirst();
}

WordPrecedingStringIntersectionReturnCode getWordPrecedingStringIntersection(char *s1, char *s2, WordDescriptor *w) {
    //WordDescriptor cur_word;
    bool is_intersection_word_found = false;
    bool is_another_word_found = false;

    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);

    for (int first_bag_index = 0; first_bag_index < _bag.size && !is_intersection_word_found; first_bag_index++) {
        for (int second_bag_index = 0; second_bag_index< _bag2.size; second_bag_index++) {
            if (areWordsEqual(_bag.words[first_bag_index], _bag2.words[second_bag_index]) == 0) {
                is_intersection_word_found = true;
                if (is_another_word_found) {
                    *w = _bag.words[first_bag_index - 1];
                }
            }
        }
        if (!is_intersection_word_found) {
            is_another_word_found = true;
        }
    }

    if (is_intersection_word_found && is_another_word_found) {
        char *cur_character_pointer = w->begin;
        while (cur_character_pointer != w->end) {
            printf("%c", *cur_character_pointer);
            cur_character_pointer++;
        }
        printf("\n");
        return WORD_FOUND;
    } else if (is_intersection_word_found) {
        printf("First word of first string is included in the second string\n");
        return FIRST_WORD_INTERSECTION;
    } else if (is_another_word_found) {
        printf("There are no words in first string which included in the second string\n");
        return NOT_FOUND_WORD_INTERSECTION;
    } else {
        printf("There are no words in the first string\n");
        return EMPTY_FIRST_STRING;
    }
}

int main() {
    test_getWordPrecedingStringIntersection();
}

