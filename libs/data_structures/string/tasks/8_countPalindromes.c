#include <ctype.h>
#include <malloc.h>
#include "string_support_functions.c"

//возвращает количество палиндромов в строке, слова которой разделены запятыми
int countPalindromes(char *s);

void test_countPalindromes_empty() {
    char s[] = "";
    assert(countPalindromes(s) == 0);
}
void test_countPalindromes_spacesOnly() {
    char s[] = "\t \n \t";
    assert(countPalindromes(s) == 0);
}
void test_countPalindromes_oneWordNoPalindrome() {
    char s[] = "apple";
    assert(countPalindromes(s) == 0);
}
void test_countPalindromes_oneWordPalindrome() {
    char s[] = "madam";
    assert(countPalindromes(s) == 0);
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

int main() {
    test_countPalindromes();
    printf("All is okay");
}



