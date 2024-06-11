#include <stdio.h>
#include "C:\Users\sovac\Desktop\ОП, преимущественно лабы\second_semester\libs\algorithms\array\array.c"
#include "C:\Users\sovac\Desktop\ОП, преимущественно лабы\second_semester\libs\data_structures\string\string_.c"

long getFileSize(FILE *f) {
    long cur_pointer = ftell(f);
    fseek(f, 0, SEEK_END);
    long result = ftell(f);
    fseek(f, cur_pointer, SEEK_SET);
    return result;
}

int getNumberFromString(char *s) {
    int sign = 1;
    int result = 0;
    if (*s == '-') {
        sign = -1;
        s++;
    }
    while (!isspace(*s) && *s != '\0') {
        result = result*10 + *s-'0';
        s++;
    }
    return result*sign;
}

void fillBagWithWordsOfFile(char *filename, BagOfWords *bag) {
    FILE *f_pre_open = fopen(filename, "r");
    long size = getFileSize(f_pre_open);
    for (int i = 0; i < size; i++) {
        _stringBuffer[i] = getc(f_pre_open);
    }
    fclose(f_pre_open);

    getBagOfWords(bag, _stringBuffer);
}
