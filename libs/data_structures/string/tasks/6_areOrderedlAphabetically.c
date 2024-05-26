#include <ctype.h>
#include <malloc.h>
#include "string_support_functions.c"

//преобразовывает строку, заменяя каждую цифру соответствующим ей числом пробелов.
bool areOrderedAlphabetically(char *s);

//<Автоматизированные тесты>

void test_areOrderedAlphabetically_empty() {
    char s[] = "";
    assert(areOrderedAlphabetically(s) == 1);
}
void test_areOrderedAlphabetically_oneWord() {
    char s[] = "Apple";
    assert(areOrderedAlphabetically(s) == 1);
}
void test_areOrderedAlphabetically_orderedStrict() {
    char s[] = "Apple Banana Lemon";
    assert(areOrderedAlphabetically(s) == 1);
}
void test_areOrderedAlphabetically_orderedNotStrict() {
    char s[] = "Apple Banana Banana Lemon";
    assert(areOrderedAlphabetically(s) == 1);
}
void test_areOrderedAlphabetically_notOrdered() {
    char s[] = "Banana Lemon Cherry";
    assert(areOrderedAlphabetically(s) == 0);
}
void test_areOrderedAlphabetically() {
    test_areOrderedAlphabetically_empty();
    test_areOrderedAlphabetically_oneWord();
    test_areOrderedAlphabetically_orderedStrict();
    test_areOrderedAlphabetically_orderedNotStrict();
    test_areOrderedAlphabetically_notOrdered();
}

int main() {
    test_areOrderedAlphabetically();
    printf("All is okay");
}

