#include <stdio.h>
#include <stdlib.h>
#ifndef myString_h
#define myString_h
#endif // !STRING_H
#define RULES_L 190
#define RULES_C 2
int** arrMat;
int** arrDerivation;

int numL, numC;
char buffer[1024];
FILE* file;

typedef struct
{
	char lexma[20];
	int numT;
	int i;
	int j;
}Token, * TokenPtr;
extern TokenPtr* arrInput;