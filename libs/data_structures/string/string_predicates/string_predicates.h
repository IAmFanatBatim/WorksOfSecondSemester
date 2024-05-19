#ifndef INC_STRING_PREDICATES_H
#define INC_STRING_PREDICATES_H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

//Возвращает 1, если символ ch является заглавной буквой, и 0 в противном случае
int isCapitalLetter(int ch);

//Возвращает 1, если символ ch является цифрой, и 0 в противном случае
int isNumberChar(int ch);

//Возвращает 1, если символ ch является гласной буквой, и 0 в противном случае
int isVowel(int ch);

#endif

