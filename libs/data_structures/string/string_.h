#ifndef INC_STRING__H
#define INC_STRING__H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

//Возвращает количество символов в строке, нулевой символ которой находится по указателю begin
size_t strlen_(const char *begin);

//Возвращает указатель на первый элемент с кодом ch, расположенным на ленте памяти между адресами begin и end не включая end.
//Если символ не найден, возвращается значение end
char* find(char *begin, char *end, int ch);

//Возвращает указатель на первый символ, отличный от пробельных, расположенный на ленте памяти, начиная с begin и заканчивая ноль-символом.
//Если символ не найден, возвращается адрес первого ноль-символа
char* findNonSpace(char *begin);

//Возвращает указатель на первый пробельный символ, расположенный на ленте памяти начиная с адреса begin или на первый ноль-символ
char* findSpace(char *begin);

//Возвращает указатель на первый справа символ, отличный от пробельных, расположенный на ленте памяти,
//начиная с rbegin (последний символ строки, за которым следует ноль-символ) и заканчивая rend (адрес символа перед началом строки).
//Если символ не найден, возвращается адрес rend
char* findNonSpaceReverse(char *rbegin, const char *rend);

//Возвращает указатель на первый справа символ, отличный от пробельных, расположенный на ленте памяти,
//начиная с rbegin (последний символ строки, за которым следует ноль-символ) и заканчивая rend (адрес символа перед началом строки)
//Если символ не найден, возвращается адрес rend
char* findSpaceReverse(char *rbegin, const char *rend);

#endif

