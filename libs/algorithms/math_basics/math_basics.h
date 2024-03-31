#ifndef INC_MATH_BASICS_H
#define INC_MATH_BASICS_H
#include <stdbool.h>

//Функция-предикат для быстрой сортировки по возрастанию
int compare_ints(const void* a, const void* b);

//Функция-предикат для быстрой сортировки по возрастанию чисел типа long long
int cmp_long_long(const void* a, const void* b);

//возвращает минимальное из двух целых чисел x и y
int min2(const int x, const int y);

//возвращает максимальное из двух целых чисел x и y
int max2(const int x, const int y);

//возвращает минимальное из трех целых чисел x, y и z
int min3(const int x, const int y, const int z);

//возвращает максимальное из трех целых чисел x, y и z
int max3(const int x, const int y, const int z);

//возвращает 1, если вещественные числа x и y различаются незначительно и могут считаться равными, и 0 в противном случае
bool are_double_equal(double x, double y);

#endif
