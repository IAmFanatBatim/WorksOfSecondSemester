
#include <ctype.h>
#include <malloc.h>
#include "string_support_functions.c"

//преобразовывает строку, заменяя каждую цифру соответствующим ей числом пробелов.
void replace(char *source, char *w1, char *w2);

//<Автоматизированные тесты>

void test_replace_withEmpty() {
    char s[MAX_STRING_SIZE] = "No more damned tests!";
    char *w1 = "damned";
    char *w2 = "";
    char *s_expected = "No more  tests!";
    replace(s, w1, w2);
    assertString(s_expected, s);
}
void test_replace_withShorter() {
    char s[MAX_STRING_SIZE] = "Hello everyone!";
    char *w1 = "Hello";
    char *w2 = "Hi";
    char *s_expected = "Hi everyone!";
    replace(s, w1, w2);
    assertString(s_expected, s);
}
void test_replace_withLonger() {
    char s[MAX_STRING_SIZE] = "Hello everyone!";
    char *w1 = "Hello";
    char *w2 = "Goodbye";
    char *s_expected = "Goodbye everyone!";
    replace(s, w1, w2);
    assertString(s_expected, s);
}
void test_replace_notWordEntering() {
    char s[MAX_STRING_SIZE] = "Ich liebe dich";
    char *w1 = "Ich";
    char *w2 = "Wir";
    char *s_expected = "Wir liebe dich";
    replace(s, w1, w2);
    assertString(s_expected, s);
}
void test_replace_multiplySpaces() {
    char s[MAX_STRING_SIZE] = "Tra \t la \t la";
    char *w1 = "la";
    char *w2 = "lo";
    char *s_expected = "Tra \t lo \t lo";
    replace(s, w1, w2);
    assertString(s_expected, s);
}
void test_replace() {
    test_replace_withEmpty();
    test_replace_withLonger();
    test_replace_withShorter();
    test_replace_notWordEntering();
    test_replace_multiplySpaces();
}

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};
    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
    } else {
        copy(source, getEndOfString(source), _stringBuffer);
        readPtr = _stringBuffer;
    }
    recPtr = source;
    WordDescriptor cur_source_word;
    while (getWord(readPtr, &cur_source_word)) {
        if (areWordsEqual(cur_source_word, word1) == 0) {
            recPtr = copy(word2.begin, word2.end, recPtr);
        } else {
            recPtr = copy(cur_source_word.begin, cur_source_word.end, recPtr);
        }
        readPtr = cur_source_word.end;
        while (isspace(*readPtr) && *readPtr != '\0') {
            *recPtr = *readPtr;
            readPtr++;
            recPtr++;
        }
    }
    *recPtr = '\0';
}


int main() {
    test_replace();
}