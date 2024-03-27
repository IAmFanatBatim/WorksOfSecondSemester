#include <stdio.h>
#include "C:\Users\Анна\Desktop\сонины программы\second_semester\WorksOfSecondSemester\libs\data_structures\matrix\matrix.c"

//1. Меняет местами строки квадратной матрицы, в которых находятся максимальный и минимальный элементы
void swapRowsWithMaxAndMinElement (matrix *m) {
    position max_pos = getMaxValuePos(*m);
    position min_pos = getMinValuePos(*m);
    swapRows(m, max_pos.rowIndex, min_pos.rowIndex);
};
