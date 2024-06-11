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

void getBagOfRequiredRepeatedWords(BagOfWords *source_bag, BagOfWords *dest_bag, int amount_of_repeating) {
    int cur_word_in_bag = 0;
    dest_bag->size = 0;
    while(cur_word_in_bag < source_bag->size) {
        int counter_of_repeating = 1;
        while (cur_word_in_bag < (source_bag->size)-1 && areWordsEqual(source_bag->words[cur_word_in_bag], source_bag->words[cur_word_in_bag+1]) == 0) {
            cur_word_in_bag++;
            counter_of_repeating++;
        }
        if (counter_of_repeating == amount_of_repeating) {
            dest_bag->words[dest_bag->size] = source_bag->words[cur_word_in_bag];
            (dest_bag->size)++;
        }
        cur_word_in_bag++;
    }
}

void deleteRepeatingWords(char *filename, int amount_of_repeating) {
    fillBagWithWordsOfFile(filename, &_bag);
    qsort(_bag.words, _bag.size, sizeof(WordDescriptor), areWordsEqualByAddress);
    getBagOfRequiredRepeatedWords(&_bag, &_bag2, amount_of_repeating);

    FILE *f = fopen(filename, "w");

    WordDescriptor cur_word;
    char *read_pointer = _stringBuffer;
    while(getWord(read_pointer, &cur_word)) {
        bool is_word_repeating_required_times = false;
        for (int i = 0; i < _bag2.size; i++) {
            if (areWordsEqual(cur_word, _bag2.words[i]) == 0) {
                is_word_repeating_required_times = true;
                break;
            }
        }
        if (!is_word_repeating_required_times) {
            char *cur_word_string = malloc(cur_word.end - cur_word.begin);
            wordDescriptorToString(cur_word, cur_word_string);
            fputs(cur_word_string, f);
            fputc(' ', f);
        }
        read_pointer = cur_word.end;
    }
    fflush(f);
    fclose(f);
}

int main(int argc, char** argv) {
    if (argc != 2) { // Проверяем, есть ли аргумент
        printf("Fuck you!\n");
        return 1; // Сигнализируем об ошибке
    }
    int real_amount_of_repeating_for_deletions = getNumberFromString(argv[1]);
    deleteRepeatingWords("text.txt", real_amount_of_repeating_for_deletions);
    return 0;
}
