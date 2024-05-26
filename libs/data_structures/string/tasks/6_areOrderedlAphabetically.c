#include <ctype.h>
#include <malloc.h>
#include "string_support_functions.c"

//возвращает 1, если слова в строке упорядочены лексикографически, и 0 в противном случае
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

bool areOrderedAlphabetically(char *s) {
    bool result = true;
    WordDescriptor previous_word, cur_word;
    bool has_at_least_one_word = getWord(s, &previous_word);
    if (!has_at_least_one_word) {
        return result;
    } else {
        s = previous_word.end;
    }
    while (getWord(s, &cur_word)) {
        if (areWordsEqual(previous_word, cur_word) > 0) {
            result = false;
        }
        previous_word = cur_word;
        s = cur_word.end;
    }
    return result;
}

int main() {
    test_areOrderedAlphabetically();
    printf("All is okay");
}

