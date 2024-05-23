#include <ctype.h>
#include "string_support_functions.c"
#define assertString(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)

//Удаляет из строки s все пробельные символы
void reduceRepetitionChains(char *s);

void test_reduceRepetitionChains_empty() {
    char s[] = "";
    char *s_expected = "";
    reduceRepetitionChains(s);
    assertString(s_expected, s);
}
void test_reduceRepetitionChains_oneCharacter() {
    char s[] = "o";
    char *s_expected = "o";
    reduceRepetitionChains(s);
    assertString(s_expected, s);
}
void test_reduceRepetitionChains_oneChain() {
    char s[] = "oooo";
    char *s_expected = "o";
    reduceRepetitionChains(s);
    assertString(s_expected, s);
}
void test_reduceRepetitionChains_chainsInRow() {
    char s[] = "ooooaaaaaaaoo";
    char *s_expected = "oao";
    reduceRepetitionChains(s);
    assertString(s_expected, s);
}
void test_reduceRepetitionChains_chainsWithInterval() {
    char s[] = "Hooow boooorinnng";
    char *s_expected = "How boring";
    reduceRepetitionChains(s);
    assertString(s_expected, s);
}
void test_reduceRepetitionChains() {
    test_reduceRepetitionChains_empty();
    test_reduceRepetitionChains_oneCharacter();
    test_reduceRepetitionChains_oneChain();
    test_reduceRepetitionChains_chainsInRow();
    test_reduceRepetitionChains_chainsWithInterval();
}

int main() {
    test_reduceRepetitionChains();
}
