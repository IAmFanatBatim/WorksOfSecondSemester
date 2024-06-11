#ifndef INC_STRING__C
#define INC_STRING__C
#include "string_.h"
#include <ctype.h>
#include <memory.h>
#include <assert.h>


size_t strlen_(const char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
}

char* find(char *begin, char *end, int ch) {
    assert(begin <= end);
    while (begin != end && *begin != ch) {
        begin++;
    }
    return begin;
}

char* findNonSpace(char *begin) {
    while (*begin != '\0' && isspace(*begin)) {
        begin++;
    }
    return begin;
}

char* findSpace(char *begin) {
    while (*begin != '\0' && !isspace(*begin)) {
        begin++;
    }
    return begin;
}

char* findNonSpaceReverse(char *rbegin, const char *rend) {
    assert(rbegin >= rend);
    while (rbegin != rend && isspace(*rbegin)) {
        rbegin--;
    }
    return rbegin;
}

char* findSpaceReverse(char *rbegin, const char *rend) {
    assert(rbegin >= rend);
    while (rbegin != rend && !isspace(*rbegin)) {
        rbegin--;
    }
    return rbegin;
}

int strcmp(const char *lhs, const char *rhs) {
    while (*lhs != '\0' && *lhs == *rhs) {
        lhs++;
        rhs++;
    }
    return *lhs - *rhs;
}

char* copy(const char *beginSource, const char *endSource, char *beginDestination) {
    assert(beginSource <= endSource);
    memcpy(beginDestination, beginSource, (endSource - beginSource)*sizeof(char));
    return beginDestination + (endSource - beginSource);
}

char* copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    assert(beginSource <= endSource);
    while (beginSource != endSource) {
        if (f(*beginSource)) {
            *beginDestination = *beginSource;
            beginDestination++;
        }
        beginSource++;
    }
    return beginDestination;
}

char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    assert(rbeginSource >= rendSource);
    while (rbeginSource != rendSource) {
        if (f(*rbeginSource)) {
            *beginDestination = *rbeginSource;
            beginDestination++;
        }
        rbeginSource--;
    }
    return beginDestination;
}

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

char* getEndOfString(char *s) {
    while (*s != '\0') {
        s++;
    }
    return s;
}

bool getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;
    word->end = findSpace(word->begin);
    return 1;
}

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

int areWordsEqualByAddress(const void *word1, const void *word2) {
    WordDescriptor w1 = *(WordDescriptor *)word1;
    WordDescriptor w2 = *(WordDescriptor *)word2;
    return areWordsEqual(w1, w2);
}

void getBagOfWords(BagOfWords *bag, char *s) {
    size_t word_counter = 0;
    while (getWord(s, &(bag->words[word_counter]))) {
        s = bag->words[word_counter].end;
        word_counter++;
    }
    bag->size = word_counter;
}

void wordDescriptorToString(WordDescriptor word, char *destination) {
    char *cur_word_character = word.begin;
    while (cur_word_character != word.end) {
        *destination = *cur_word_character;
        cur_word_character++;
        destination++;
    }
    *destination = '\0';
}

int compare_chars(const void* a, const void* b) {
    int arg1 = *(const char*)a;
    int arg2 = *(const char*)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

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

void sortBagOfWords(BagOfWords *source_bag) {
    qsort(source_bag->words, source_bag->size, sizeof(WordDescriptor), areWordsEqualByAddress);
}

void getGlossBySortedBag(BagOfWords *source_bag, Glossarium *dest_glossarium) {
    int cur_ind_in_gloss = 0;
    int cur_ind_in_bag = 0;

    while(cur_ind_in_bag < source_bag->size) {
        int counter_of_repeating = 1;
        while (cur_ind_in_bag < (source_bag->size)-1 && areWordsEqual(source_bag->words[cur_ind_in_bag], source_bag->words[cur_ind_in_bag+1]) == 0) {
            cur_ind_in_bag++;
            counter_of_repeating++;
        }
        wordDescriptorToString(source_bag->words[cur_ind_in_bag], dest_glossarium->words[cur_ind_in_gloss].word);
        dest_glossarium->words[cur_ind_in_gloss].amount_of_occurrences = counter_of_repeating;
        (dest_glossarium->amount_of_words)++;
        cur_ind_in_bag++;
        cur_ind_in_gloss++;
    }
}

void printGloss(Glossarium gloss) {
    for (int cur_word_ind = 0; cur_word_ind < gloss.amount_of_words; cur_word_ind++){
        printf("%s: ", gloss.words[cur_word_ind].word);
        printf("%llu times\n", gloss.words[cur_word_ind].amount_of_occurrences);
    }
}

#endif
