#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define LemReserves 101
#define Garbage 0xCDCDCDCD

#include <stdio.h>
#include <stdlib.h>
#include "HashTableReservesStruct.h"
#ifndef STRING_H
#define STRING_H
#endif // !STRING_H
//void FillingTypes();
int HashFunc(char* word);
void InHash(char* word, int type);
void HashTable();


