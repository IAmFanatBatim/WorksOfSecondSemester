#include <stdio.h>
#include <io.h>
#include "C:\Users\sovac\Desktop\ОП, преимущественно лабы\second_semester\libs\algorithms\array\array.c"

long getFileSize(FILE *f) {
    long cur_pointer = ftell(f);
    fseek(f, 0, SEEK_END);
    long result = ftell(f);
    fseek(f, cur_pointer, SEEK_SET);
    return result;
}

void writeNumberToBin(FILE *f, int *num) {
    fwrite(num, sizeof(int), 1, f);
}

void getArrayFromBin(FILE *f, int *array, size_t size) {
    fread(array, sizeof(int), size, f);
}

void deleteEvenMirrorOdd(char *filename) {
    FILE *f = fopen(filename, "r+b");
    long size = getFileSize(f);
    long size_in_ints =  size/sizeof(int);

    int *array_of_all_nums = malloc(size);
    getArrayFromBin(f, array_of_all_nums, size_in_ints);
    int odd_counter = 0;

    for (int i = 0; i < size_in_ints; i++) {
        int cur_num = array_of_all_nums[size_in_ints-i-1];
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
    getArrayFromBin(f2, b, 3);
    outputArray_(b, 3);
    return 0;
}
