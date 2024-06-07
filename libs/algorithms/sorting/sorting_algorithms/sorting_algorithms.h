#ifndef SORTING_ALGORITHMS_LIBRARY_H
#define SORTING_ALGORITHMS_LIBRARY_H

#include <stdint.h>

//Производит сортировку обменом ("пузырьковую" сортировку) массива array размера size.
//Перебираются пары соседних элементов: с индексами 0 и 1, 1 и 2, ..., size-1 и size; если в этих парах порядок нарушен, совершается обмен
//Проход по массиву со сравнениями пар происходит с уменьшением области сравнения на 1
//Продолжаясь до тех пор, пока область не станет нулевой или на очередном проходе не будет совершено ни одного обмена
void bubbleSort(int *array, size_t size);

//Производит сортировку выбором массива array размера size
//В цикле перебираются все элементы массива, кроме последнего; для каждого из них создается переменная min_pos, которая изначально равна индексу элемента
//Во внутреннем цикле перебираются все элементы с большими, чем у текущего, индексами, среди них ищется наименьший, и его индекс сохраняется в min_pos
//В конце совершается обмен текущего элемента с элементом по индексу min_pos
void selectionSort(int *array, size_t size);

//Производит сортировку вставками массива array размера size
//В цикле перебираются все элементы массива; затем он последовательно сравнивается с элементами левее него (сравнение проходит справа налево)
//При этом все элементы сдвигаются на позицию вправо, и это продолжается, пока текущий элемент больше тех, с которыми сравнивается
//Когда это условие перестает выполняться, текущий элемент вставляется на найденную позицию
void insertionSort(int *array, size_t size);

#endif //SORTING_ALGORITHMS_LIBRARY_H
