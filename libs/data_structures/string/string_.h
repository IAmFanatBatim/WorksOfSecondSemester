#ifndef INC_STRING__H
#define INC_STRING__H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_STRING_SIZE 2000
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20
char _stringBuffer[MAX_STRING_SIZE + 1];

//Структура, описывающая положение слова в строке
typedef struct {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа
} WordDescriptor;

//Структура, описывающая положение нескольких слов в строке
typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

BagOfWords _bag;
BagOfWords _bag2;

typedef struct GlossWord {
    char word[MAX_WORD_SIZE];
    size_t amount_of_occurrences;
} GlossWord;

typedef struct Glossarium {
    GlossWord words[MAX_N_WORDS_IN_STRING];
    size_t amount_of_words;
} Glossarium;


//Возвращает количество символов в строке, нулевой символ которой находится по указателю begin
size_t strlen_(const char *begin);

//Возвращает указатель на первый элемент с кодом ch, расположенным на ленте памяти между адресами begin и end не включая end.
//Если символ не найден, возвращается значение end
char* find(char *begin, char *end, int ch);

//Возвращает указатель на первый символ, отличный от пробельных, расположенный на ленте памяти, начиная с begin и заканчивая ноль-символом.
//Если символ не найден, возвращается адрес первого ноль-символа
char* findNonSpace(char *begin);

//Возвращает указатель на первый пробельный символ, расположенный на ленте памяти начиная с адреса begin или на первый ноль-символ
char* findSpace(char *begin);

//Возвращает указатель на первый справа символ, отличный от пробельных, расположенный на ленте памяти,
//начиная с rbegin (последний символ строки, за которым следует ноль-символ) и заканчивая rend (адрес символа перед началом строки).
//Если символ не найден, возвращается адрес rend
char* findNonSpaceReverse(char *rbegin, const char *rend);

//Возвращает указатель на первый справа символ, отличный от пробельных, расположенный на ленте памяти,
//начиная с rbegin (последний символ строки, за которым следует ноль-символ) и заканчивая rend (адрес символа перед началом строки)
//Если символ не найден, возвращается адрес rend
char* findSpaceReverse(char *rbegin, const char *rend);

//Возвращает отрицательное значение, если lhs располагается до rhs в лексикографическом порядке (как в словаре),
//значение 0, если lhs и rhs равны, иначе – положительное значение.
int strcmp(const char *lhs, const char *rhs);

//Записывает по адресу beginDestination фрагмент памяти, начиная с адреса beginSource до endSource.
//Возвращает указатель на следующий свободный фрагмент памяти в destination
//По окончанию работы функции ноль-символ не записывается.
char* copy(const char *beginSource, const char *endSource, char *beginDestination);

//Записывает по адресу beginDestination элементы из фрагмента памяти, начиная с beginSource заканчивая endSource,
//удовлетворяющие функции-предикату f. Функция возвращает указатель на следующий свободный для записи фрагмент в памяти.
//По окончанию работы функции ноль-символ не записывается.
char* copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

//Записывает по адресу beginDestination элементы из фрагмента памяти, начиная с rbeginSource, заканчивая rendSource,
//удовлетворяющие функции-предикату f. Функция возвращает значение beginDestination по окончанию работы функции.
//По окончанию работы функции ноль-символ не записывается.
char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

//Выводит в поток ошибок, что для выполняемой функции, тест выполнен успешно, если они равны
//в противном случае выводит в поток ошибок информацию о том, в каком файле, функции и строке произошло расхождение ожидаемого результата с реальным
void assertString(const char *expected, char *got, char const *fileName, char const *funcName, int line);

//Возвращает указатель на первый нулевой символ, встреченный в строке, на начало которой указывает s
char* getEndOfString(char *s);

//Возвращает 1 и вписывает в структуру word указатели на начало и конец первого слова, найденного после указателя beginSearch
//Если был встречен ноль-символ, а слово не было считано, возвращает 0
bool getWord(char *beginSearch, WordDescriptor *word);

//Возвращает 1 и вписывает в структуру word указатели на начало и конец первого слова, найденного до указателя rbegin,
//но не выходящего за рамки левой границы rend; если слово не было считано, возвращает 0
bool getWordReverseB(char *rbegin, char *rend, WordDescriptor *word);

//Возвращает 1 и вписывает в структуру word указатели на начало и конец первого слова, найденного до указателя rbegin,
//но не выходящего за рамки левой границы rend; если слово не было считано, возвращает 0
bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

//Возвращает отрицательное значение, если слово w1 располагается до w2 в лексикографическом порядке (как в словаре),
//значение 0, если они равны, иначе – положительное значение.
int areWordsEqual(WordDescriptor w1, WordDescriptor w2);

//Получает позиции начала и конца каждого слова строки
void getBagOfWords(BagOfWords *bag, char *s);

//Преобразовывает слово в строку, записывая ее по адресу destination
void wordDescriptorToString(WordDescriptor word, char *destination);

//Сравнивает два символа для быстрой сортировки массива типа char
int compare_chars(const void* a, const void* b);

//Определяет, есть ли в данной строке одинаковые слова
bool areIdenticalWordsInString(char *s);

//Сортирует слова в мешке слов по алфавиту
void sortBagOfWords(BagOfWords *source_bag);

//Получает структуру "словарь" по заданному мешку слов
void getGlossBySortedBag(BagOfWords *source_bag, Glossarium *dest_glossarium);

//Выводит структуру "словарь"
void printGloss(Glossarium gloss);

#endif

