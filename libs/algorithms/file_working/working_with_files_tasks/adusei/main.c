#include <stdio.h>
#include <io.h>
#include <ctype.h>
#include "C:\Users\sovac\Desktop\ОП, преимущественно лабы\second_semester\libs\algorithms\array\array.c"
#include "C:\Users\sovac\Desktop\ОП, преимущественно лабы\second_semester\libs\algorithms\math_basics\math_basics.c"

long getFileSize(FILE *f) {
    long cur_pointer = ftell(f);
    fseek(f, 0, SEEK_END);
    long result = ftell(f);
    fseek(f, cur_pointer, SEEK_SET);
    return result;
}

int getNumberFromBin(FILE *f) {
    int num;
    fread(&num, sizeof(int), 1, f);
    return num;
}

void writeNumberToBin(FILE *f, int *num) {
    fwrite(num, sizeof(int), 1, f);
}

void getArrayFromBin(FILE *f, int *array, size_t size) {
    for (int i = 0; i < size; i++) {
        array[i] = getNumberFromBin(f);
    }
}

void deleteEvenMirrorOdd(char *filename) {
    FILE *f = fopen(filename, "r+b");
    long size = getFileSize(f);
    long size_in_ints = size/sizeof(int);

    int odd_counter = 0;
    for (int i = 0; i < size_in_ints; i++) {
        long shift_in_bytes = size-(i+1)*sizeof(int);
        fseek(f, shift_in_bytes, SEEK_SET);
        printf("pointer: %ld\n", ftell(f));
        int cur_num = getNumberFromBin(f);
        printf("%d\n\n", cur_num);
        if (cur_num % 2 != 0) {
            fseek(f, odd_counter*sizeof(int), SEEK_SET);
            writeNumberToBin(f, &cur_num);
            odd_counter++;
        }
    }
    chsize(fileno(f), odd_counter*sizeof(int));
    fflush(f);
    fclose(f);
}

int main() {
    int a[6] = {2, 13, 173, 16, 1};
    FILE *f = fopen("matrix.bin", "w+b");;
    fwrite(a, sizeof(int), 5, f);

    fseek(f, 0, SEEK_SET);
    getArrayFromBin(f, a, 5);
    outputArray_(a, 5);

    fclose(f);
    deleteEvenMirrorOdd("matrix.bin");

    int b[3];
    FILE *f2 = fopen("matrix.bin", "rb");
    getArrayFromBin(f2, b, 4);
    outputArray_(b, 4);
    return 0;
}
