#include <ctype.h>
#include "string_support_functions.c"
#include <stdlib.h>

//Удаляет из строки копии последнего слова
void removeCopiesOfLastWord(char *s);

//<Автоматизированные тесты>

void test_removeCopiesOfLastWord_noWords() {
    char s[] = "";
    char s_expected[] = "";
    removeCopiesOfLastWord(s);
    assertString(s_expected, s);
}
void test_removeCopiesOfLastWord_oneWord() {
    char s[] = "apple";
    char s_expected[] = "";
    removeCopiesOfLastWord(s);
    assertString(s_expected, s);
}
void test_removeCopiesOfLastWord_allWordsAreSame() {
    char s[] = "apple apple apple";
    char s_expected[] = "";
    removeCopiesOfLastWord(s);
    assertString(s_expected, s);
}
void test_removeCopiesOfLastWord_allWordsAreDifferent() {
    char s[] = "apple lemon banana";
    char s_expected[] = "apple lemon";
    removeCopiesOfLastWord(s);
    assertString(s_expected, s);
}
void test_removeCopiesOfLastWord_diverseWords() {
    char s[] = "apple lemon banana lemon";
    char s_expected[] = "apple banana";
    removeCopiesOfLastWord(s);
    assertString(s_expected, s);
}
void test_removeCopiesOfLastWord() {
    test_removeCopiesOfLastWord_noWords();
    test_removeCopiesOfLastWord_oneWord();
    test_removeCopiesOfLastWord_allWordsAreSame();
    test_removeCopiesOfLastWord_allWordsAreDifferent();
    test_removeCopiesOfLastWord_diverseWords();
}

void removeCopiesOfLastWord(char *s) {
    WordDescriptor last_word;
    bool was_last_word_gotten = getWordReverse(s + strlen_(s) - 1, s-1, &last_word);
    char *read_ptr = s;
    char *write_ptr = s;
    if (was_last_word_gotten) {
        WordDescriptor cur_word;
        while (getWord(read_ptr, &cur_word)) {
            if (areWordsEqual(cur_word, last_word) != 0) {
                if (write_ptr != s) {
                    *write_ptr = ' ';
                    write_ptr++;
                }
                write_ptr = copy(cur_word.begin, cur_word.end, write_ptr);
            }
            read_ptr = cur_word.end;
        }
    }
    *write_ptr = '\0';
}

int main() {
    test_removeCopiesOfLastWord();
}

