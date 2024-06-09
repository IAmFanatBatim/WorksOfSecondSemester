#include "C:\Users\sovac\Desktop\ОП, преимущественно лабы\second_semester\libs\data_structures\string\string_.c"

//Выводит в поток ошибок, чтовыполняемой функции, тест выполнен успешно, если они равны
//в противном случае выводит в поток ошибок информацию о том, в каком файле, функции и строке произошло расхождение ожидаемого результата с реальным
void assertString(const char *expected, char *got, char const *fileName, char const *funcName, int line) {
    if (strcmp(expected, got)) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

#define assertString(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)

//Возвращает указатель на первый нулевой символ, встреченный в строке, на начало которой указывает s
char* getEndOfString(char *s) {
    while (*s != '\0') {
        s++;
    }
    return s;
}

//Возвращает 1 и вписывает в структуру word указатели на начало и конец первого слова, найденного после указателя beginSearch
//Если был встречен ноль-символ, а слово не было считано, возвращает 0
bool getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;
    word->end = findSpace(word->begin);
    return 1;
}

//Возвращает 1 и вписывает в структуру word указатели на начало и конец первого слова, найденного до указателя rbegin,
//но не выходящего за рамки левой границы rend; если слово не было считано, возвращает 0
bool getWordReverseB(char *rbegin, char *rend, WordDescriptor *word) {
    word->end = findSpaceReverse(rbegin, rend);
    char *first_letter = findNonSpaceReverse(word->end - 1, rend);
    if (first_letter == rend) {
        return 0;
    }
    word->begin = findSpaceReverse(first_letter, rend);
    word->end++;
    word->begin++;
    return 1;
}

//Возвращает 1 и вписывает в структуру word указатели на начало и конец первого слова, найденного до указателя rbegin,
//но не выходящего за рамки левой границы rend; если слово не было считано, возвращает 0
bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->end = findNonSpaceReverse(rbegin, rend);
    if (word->end == rend) {
        return 0;
    }
    word->begin = findSpaceReverse(word->end, rend);
    word->end++;
    word->begin++;
    return 1;
}

//Возвращает отрицательное значение, если слово w1 располагается до w2 в лексикографическом порядке (как в словаре),
//значение 0, если они равны, иначе – положительное значение.
int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    size_t w1Size = w1.end - w1.begin;
    size_t w2Size = w2.end - w2.begin;
    size_t min_size = (w1Size < w2Size) ? w1Size : w2Size;
    int result = memcmp(w1.begin, w2.begin, (min_size)*sizeof(char));
    if (result != 0) {
        return result;
    } else if (w1Size > w2Size) {
        return *(w1.begin + min_size);
    } else if (w1Size < w2Size) {
        return -*(w2.begin + min_size);
    } else {
        return 0;
    }
}

//Получает позиции начала и конца каждого слова строки
void getBagOfWords(BagOfWords *bag, char *s) {
    size_t word_counter = 0;
    while (getWord(s, &(bag->words[word_counter]))) {
        s = bag->words[word_counter].end;
        word_counter++;
    }
    bag->size = word_counter;
}

//Преобразовывает слово в строку, записывая ее по адресу destination
void wordDescriptorToString(WordDescriptor word, char *destination) {
    char *cur_word_character = word.begin;
    while (cur_word_character != word.end) {
        *destination = *cur_word_character;
        cur_word_character++;
        destination++;
    }
    *destination = '\0';
}

//Сравнивает два символа для быстрой сортировки массива типа char
int compare_chars(const void* a, const void* b) {
    int arg1 = *(const char*)a;
    int arg2 = *(const char*)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

//Определяет, есть ли в данной строке одинаковые слова
bool areIdenticalWordsInString(char *s) {
    getBagOfWords(&_bag, s);
    bool has_equal = false;
    for (int first_word_index = 0; first_word_index < _bag.size - 1 && !has_equal; first_word_index++) {
        for (int second_word_index = first_word_index + 1; second_word_index < _bag.size && !has_equal; second_word_index++) {
            if (areWordsEqual(_bag.words[first_word_index], _bag.words[second_word_index]) == 0) {
                has_equal = true;
            }
        }
    }
    return has_equal;
}
