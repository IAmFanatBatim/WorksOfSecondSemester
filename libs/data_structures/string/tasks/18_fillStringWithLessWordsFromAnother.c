#include <ctype.h>
#include "string_support_functions.c"

//Дополняет ту из строк. в которой слов меньше, последними словами из другой строки
void fillStringWithLessWordsFromAnother(char *s1, char *s2);

//<Автоматизированные тесты>

void test_fillStringWithLessWordsFromAnother_noWords() {
    char s1[MAX_STRING_SIZE] = "";
    char s2[MAX_STRING_SIZE] = "\t \n \t";
    char s_expected1[] = "";
    char s_expected2[] = "\t \n \t";
    fillStringWithLessWordsFromAnother(s1, s2);
    assertString(s_expected1, s1);
    assertString(s_expected2, s2);
}
void test_fillStringWithLessWordsFromAnother_sameWordsAmount() {
    char s1[MAX_STRING_SIZE] = "cherry apple";
    char s2[MAX_STRING_SIZE] = "lemon banana";
    char s_expected1[] = "cherry apple";
    char s_expected2[] = "lemon banana";
    fillStringWithLessWordsFromAnother(s1, s2);
    assertString(s_expected1, s1);
    assertString(s_expected2, s2);
}
void test_fillStringWithLessWordsFromAnother_firstLonger() {
    char s1[MAX_STRING_SIZE] = "cherry apple banana";
    char s2[MAX_STRING_SIZE] = "lemon";
    char s_expected1[] = "cherry apple banana";
    char s_expected2[] = "lemon apple banana";
    fillStringWithLessWordsFromAnother(s1, s2);
    assertString(s_expected1, s1);
    assertString(s_expected2, s2);
}
void test_fillStringWithLessWordsFromAnother_firstShorter() {
    char s1[MAX_STRING_SIZE] = "cherry";
    char s2[MAX_STRING_SIZE] = "lemon apple banana";
    char s_expected1[] = "cherry apple banana";
    char s_expected2[] = "lemon apple banana";
    fillStringWithLessWordsFromAnother(s1, s2);
    assertString(s_expected1, s1);
    assertString(s_expected2, s2);
}
void test_fillStringWithLessWordsFromAnother_oneEmpty() {
    char s1[MAX_STRING_SIZE] = "cherry";
    char s2[MAX_STRING_SIZE] = "";
    char s_expected1[] = "cherry";
    char s_expected2[] = "cherry";
    fillStringWithLessWordsFromAnother(s1, s2);
    assertString(s_expected1, s1);
    assertString(s_expected2, s2);

}
void test_fillStringWithLessWordsFromAnother() {
    test_fillStringWithLessWordsFromAnother_noWords();
    test_fillStringWithLessWordsFromAnother_sameWordsAmount();
    test_fillStringWithLessWordsFromAnother_firstLonger();
    test_fillStringWithLessWordsFromAnother_firstShorter();
    test_fillStringWithLessWordsFromAnother_oneEmpty();
}

void fillStringWithLessWordsFromAnother(char *s1, char *s2) {
    char *read_1 = s1;
    char *read_2 = s2;
    char *write_1 = s1;
    char *write_2 = s2;
    WordDescriptor cur_word_1, cur_word_2;
    while (getWord(read_1, &cur_word_1) && getWord(read_2, &cur_word_2)) {
        read_1 = cur_word_1.end;
        write_1 = cur_word_1.end;
        read_2 = cur_word_2.end;
        write_2 = cur_word_2.end;
    }
    while (getWord(read_1, &cur_word_1)) {
        if (write_2 != s2) {
            *write_2 = ' ';
            write_2++;
        }
        write_2 = copy(cur_word_1.begin, cur_word_1.end, write_2);
        read_1 = cur_word_1.end;
    }
    while (getWord(read_2, &cur_word_2)) {
        if (write_1 != s1) {
            *write_1 = ' ';
            write_1++;
        }
        write_1 = copy(cur_word_2.begin, cur_word_2.end, write_1);
        read_2 = cur_word_2.end;
    }
}

int main() {
    test_fillStringWithLessWordsFromAnother();
}

