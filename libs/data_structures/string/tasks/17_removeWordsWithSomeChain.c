#include <ctype.h>
#include "string_support_functions.c"
#include <stdlib.h>

//Удаляет из строки слова, содержащие заданную последовательность символов
void removeWordsWithSomeChain(char *s, char *chain);

//<Автоматизированные тесты>

void test_removeWordsWithSomeChain_empty() {
    char s[] = "";
    char chain[] = "abc";
    char s_expected[] = "";
    removeWordsWithSomeChain(s, chain);
    assertString(s_expected, s);
}
void test_removeWordsWithSomeChain_noWords() {
    char s[] = "\t \n \t";
    char chain[] = "abc";
    char s_expected[] = "";
    removeWordsWithSomeChain(s, chain);
    assertString(s_expected, s);
}
void test_removeWordsWithSomeChain_noDeletions() {
    char s[] = "cherry";
    char chain[] = "abc";
    char s_expected[] = "cherry";
    removeWordsWithSomeChain(s, chain);
    assertString(s_expected, s);
}
void test_removeWordsWithSomeChain_allDeletions() {
    char s[] = "cherry";
    char chain[] = "her";
    char s_expected[] = "";
    removeWordsWithSomeChain(s, chain);
    assertString(s_expected, s);
}
void test_removeWordsWithSomeChain_someDeletions() {
    char s[] = "cherry lady apple hero";
    char chain[] = "her";
    char s_expected[] = "lady apple";
    removeWordsWithSomeChain(s, chain);
    assertString(s_expected, s);
}
void test_removeWordsWithSomeChain_emptyChain() {
    char s[] = "cherry lady apple hero";
    char chain[] = "";
    char s_expected[] = "cherry lady apple hero";
    removeWordsWithSomeChain(s, chain);
    assertString(s_expected, s);
}
void test_removeWordsWithSomeChain() {
    test_removeWordsWithSomeChain_empty();
    test_removeWordsWithSomeChain_noWords();
    test_removeWordsWithSomeChain_noDeletions();
    test_removeWordsWithSomeChain_allDeletions();
    test_removeWordsWithSomeChain_someDeletions();
    test_removeWordsWithSomeChain_emptyChain();
}

void removeWordsWithSomeChain(char *s, char *chain) {
    if (strlen_(chain) != 0) {
        WordDescriptor cur_word;
        char *read_ptr = s;
        char *write_ptr = s;
        while (getWord(read_ptr, &cur_word)) {
            bool has_chain = false;
            for (int i = 0; i <= cur_word.end - cur_word.begin - strlen_(chain); i++) {
                if (memcmp(chain, cur_word.begin+i, strlen_(chain)) == 0) {
                    has_chain = true;
                    break;
                }
            }
            if (!has_chain) {
                if (write_ptr != s) {
                    *write_ptr = ' ';
                    write_ptr++;
                }
                write_ptr = copy (cur_word.begin, cur_word.end, write_ptr);
            }
            read_ptr = cur_word.end;
        }
        *write_ptr = '\0';
    }
}

int main() {
    test_removeWordsWithSomeChain();
}

