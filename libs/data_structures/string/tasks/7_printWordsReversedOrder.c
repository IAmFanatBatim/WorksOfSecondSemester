#include <ctype.h>
#include <malloc.h>
#include "string_support_functions.c"

//выводит на экран слова строки в обратном порядке, по одному на строку вывода
void printWordsReversedOrder(char *s);

void printWordsReversedOrder(char *s) {
    getBagOfWords(&_bag, s);
    for (int i = _bag.size - 1; i >= 0; i--) {
        char *cur_begin = _bag.words[i].begin;
        while (cur_begin != _bag.words[i].end) {
            printf("%c", *cur_begin);
            cur_begin++;
        }
        printf("\n");
    }
}

int main() {
    char *s1 = "";
    char *s2 = "\t \n \t";
    char *s3 = "Apple";
    char *s4 = "Apple Banana Lemon";

    printWordsReversedOrder(s1);
    printf("\n");
    printWordsReversedOrder(s2);
    printf("\n");
    printWordsReversedOrder(s3);
    printf("\n");
    printWordsReversedOrder(s4);
    printf("\n");
}

