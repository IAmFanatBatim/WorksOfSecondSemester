#include <ctype.h>
#include "string_support_functions.c"
#include <stdlib.h>

//Удаляет из строки слова, содержащие заданную последовательность символов
bool areWordLettersInString(char *s, char *word);

//<Автоматизированные тесты>

void test_areWordLettersInString_allEmpty() {
    char s[] = "";
    char word[] = "";
    assert(areWordLettersInString(s, word) == true);
}
void test_areWordLettersInString_emptyWord() {
    char s[] = "cherry";
    char word[] = "";
    assert(areWordLettersInString(s, word) == true);
}
void test_areWordLettersInString_emptyString() {
    char s[] = "";
    char word[] = "her";
    assert(areWordLettersInString(s, word) == false);
}
void test_areWordLettersInString_allLettersIn() {
    char s[] = "cherry lady";
    char word[] = "dear";
    assert(areWordLettersInString(s, word) == true);
}
void test_areWordLettersInString_someLettersIn() {
    char s[] = "cherry lady";
    char word[] = "love";
    assert(areWordLettersInString(s, word) == false);
}

void test_areWordLettersInString() {
    test_areWordLettersInString_allEmpty();
    test_areWordLettersInString_emptyWord();
    test_areWordLettersInString_emptyString();
    test_areWordLettersInString_allLettersIn();
    test_areWordLettersInString_someLettersIn();
}

bool areWordLettersInString(char *s, char *word) {
    if (*s == '\0' && *word != '\0') {
        return 0;
    }
    copy(s, s + strlen_(s), _stringBuffer);
    char word_buffer[strlen_(word)];
    char *end_of_word_buffer = copy(word, word + strlen_(word), word_buffer);
    qsort(_stringBuffer, strlen_(s), sizeof(char), compare_chars);
    qsort(word_buffer, strlen_(word), sizeof(char), compare_chars);
    bool are_all_letters_in_string = true;
    char *read_string = _stringBuffer;
    char *read_word = word_buffer;
    while (read_word != end_of_word_buffer) {
        if (*read_word == '\0') {
            break;
        } else if (*read_string == *read_word) {
            read_string++;
            read_word++;
        } else if (*read_string < *read_word) {
            read_string++;
        } else if (*read_string > *read_word){
            are_all_letters_in_string = false;
            break;
        }
    }
    return are_all_letters_in_string;
}

int main() {
    test_areWordLettersInString();
    printf("All is okay");
}

