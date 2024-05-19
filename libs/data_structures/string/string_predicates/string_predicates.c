#ifndef INC_STRING_PREDICATES_C
#define INC_STRING_PREDICATES_C
#include "string_predicates.h"
#include <ctype.h>

int isCapitalLetter(int ch) {
    return (ch >= 'A') && (ch <= 'Z');
}

int isNumberChar(int ch) {
    return (ch >= '0') && (ch <= '9');
}

int isVowel(int ch) {
    int isLowCaseVowel = (ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u') || (ch == 'y');
    int isUpperCaseVowel = (ch == 'A') || (ch == 'E') || (ch == 'I') || (ch == 'O') || (ch == 'U') || (ch == 'Y');
    return isLowCaseVowel || isUpperCaseVowel;

}

#endif

