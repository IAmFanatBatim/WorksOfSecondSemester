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

//Структура, описывающая положение слова в строке
typedef struct {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа
} WordDescriptor;

//Возвращает 1 и вписывает в структуру word указатели на начало и конец первого слова, найденного после указателя beginSearch
//Если был встречен ноль-символ, а слово не было считано, возвращает 0
int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;
    word->end = findSpace(word->begin);
    return 1;
}
