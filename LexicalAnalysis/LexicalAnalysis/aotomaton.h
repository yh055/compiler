#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
//#ifndef  HashTableReserves_h
//#define HashTableReserves_h
//#endif // ! HashTableReserves_c
#include <stdio.h>
#include <stdlib.h>
#include "HashTableReserves.h"
#ifndef myString_h
#define myString_h
#endif // !STRING_H


#define LETTER(tav) ((int)tav > 96 && (int)tav < 123)
#define NUM(tav) ((int)tav > 47 && (int)tav < 58)
#define DOT(tav) ((int)tav == 46)
#define QUOTATION(tav) ((int)tav == 34)
#define LEN 6


typedef struct
{
	char str[20];
	int num;
}Final, * FinalPtr;

int location(char tav);
void filling();
void final1();
void switchToAutomatic(char* laxma, int i, int j);
