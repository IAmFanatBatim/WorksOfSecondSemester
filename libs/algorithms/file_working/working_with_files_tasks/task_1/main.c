#include <stdio.h>
#include <ctype.h>
#include "C:\Users\sovac\Desktop\ОП, преимущественно лабы\second_semester\libs\algorithms\array\array.c"
#include "C:\Users\sovac\Desktop\ОП, преимущественно лабы\second_semester\libs\algorithms\math_basics\math_basics.c"

int getNumber(FILE *f) {
    int result = 0;
    int sign = 1;
    int cur_char = getc(f);
    while (isspace(cur_char)) {
        cur_char = getc(f);
    }
    if (cur_char == '-') {
        sign = -1;
        cur_char = getc(f);
    }
    while (!isspace(cur_char) && !feof(f)) {
        result = result*10 + cur_char-'0';
        cur_char = getc(f);
    }
    return result*sign;
}

int writeNumber(FILE *f, int num) {
    int digits_amount = getDigitsAmount(num);
    while (digits_amount > 0) {
        digits_amount--;
        char cur_ch = num / (int) pow(10, digits_amount) + '0';
        num %= (int) pow(10, digits_amount);
        fputc(cur_ch, f);
    }
}

void getArrayOfNumbers(FILE *f, int *array, size_t size) {
    for (int i = 0; i < size; i++) {
        array[i] = getNumber(f);
    }
}

void writeArrayOfNumbers(FILE *f, int *array, size_t size) {
    for (int i = 0; i < size; i++) {
        writeNumber(f, array[i]);
        fputc(' ', f);
    }
}

void pseudoTransposeFileMatrix(char *filename) {
    FILE *f = fopen(filename, "r+");
    int order = getNumber(f);
    long start_of_data = ftell(f);

    int matrix_size = order*order;
    int *data = malloc(sizeof(int) * matrix_size);
    getArrayOfNumbers(f, data, matrix_size);

    for (int i = 0; i < matrix_size; i++) {
        int cur_row = i/order;
        int cur_col = i%order;
        swapVoid(&data[cur_row*order + cur_col], &data[cur_col*order + cur_row], sizeof(int));
        if (cur_col == order - 1) {
            i += cur_row+1;
        }
    }

    fseek(f, start_of_data, SEEK_SET);
    writeArrayOfNumbers(f, data, matrix_size);
    fflush(f);
    fclose(f);
}

int main() {
    pseudoTransposeFileMatrix("matrix.txt");
    return 0;
}
