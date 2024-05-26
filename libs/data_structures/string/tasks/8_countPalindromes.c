#include <ctype.h>
#include <malloc.h>
#include "string_support_functions.c"

//возвращает количество палиндромов в строке, слова которой разделены запятыми
int countPalindromes(char *s);

//<Автоматизированные тесты>

void test_countPalindromes_empty() {
    char s[] = "";
    assert(countPalindromes(s) == 0);
}
void test_countPalindromes_spacesOnly() {
    char s[] = "\t \n \t";
    assert(countPalindromes(s) == 1);
}
void test_countPalindromes_oneWordNoPalindrome() {
    char s[] = "apple";
    assert(countPalindromes(s) == 0);
}
void test_countPalindromes_oneWordPalindrome() {
    char s[] = "madam";
    assert(countPalindromes(s) == 1);
}
void test_countPalindromes_diverseWords() {
    char s[] = "apple,madam,cherry,ada";
    assert(countPalindromes(s) == 2);
}
void test_countPalindromes() {
    test_countPalindromes_empty();
    test_countPalindromes_spacesOnly();
    test_countPalindromes_oneWordNoPalindrome();
    test_countPalindromes_oneWordPalindrome();
    test_countPalindromes_diverseWords();
}

int countPalindromes(char *s) {
    int counter = 0;
    char *cur_begin = s;
    char *cur_end = cur_begin;;
    while (*cur_end != '\0') {
        while (*cur_end != '\0' && *cur_end != ',') {
            cur_end++;
        }
        char *right_edge = cur_end - 1;
        char *left_edge = cur_begin;
        bool is_palindrome = true;
        while (left_edge < right_edge) {
            if (*left_edge != *right_edge) {
                is_palindrome = false;
                break;
            }
            left_edge++;
            right_edge--;
        }
        if (is_palindrome) {
            counter++;
        }
        cur_begin = cur_end + 1;
        cur_end = cur_begin;
    }
    return counter;
}

int main() {
    test_countPalindromes();
    printf("All is okay");
}



