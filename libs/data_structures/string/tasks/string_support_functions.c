#include "C:\Users\sovac\Desktop\ОП, преимущественно лабы\second_semester\libs\data_structures\string\string_.c"

//Выводит в поток ошибок, что  тест выполнен успешно, если они равны
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
void wordDescriptorToString(WordDescriptor word, char *destination);


