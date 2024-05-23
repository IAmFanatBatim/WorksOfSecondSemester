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

