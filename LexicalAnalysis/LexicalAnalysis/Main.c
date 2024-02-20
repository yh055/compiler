#include <stdio.h>
#include <stdlib.h>
#ifndef HASHTABLERESERVES_C
#define HASHTABLERESERVES_C
#endif // !HASHTABLERESERVES_C
#include "HashTableReservesStruct.h"

#ifndef AUTOMATON_C
#define AUTOMATON_C
#endif // !AUTOMATON_C

#ifndef STRING_H
#define STRING_H
#endif // !STRING_H
#define sizeEnd 30


char endWordArr[sizeEnd];

void createToken(char* laxma, int i, int j) {
	UniformPtr a = NULL;
	FILE* file = NULL;

	errno_t e = fopen_s(&file, "C:/Users/Public/Pictures/token.txt", "at");
	if (e!=0) {
		printf("Error open file\n");
		exit(1);
	}
	
	//hashבדיקה האם קיימת ב
	//צריך לעבור על כל הרשימה של המקום הזה
	while (HashUniform[HashFunc(laxma)]->next && HashUniform[HashFunc(laxma)]->str != laxma) {
		a = HashUniform[HashFunc(laxma)]->next;
	}
	if (a != NULL)
	{
		//תיצור טוקן מסוג המילה השמורה
		fprintf(file, "%s %s line %d column %d", a->str, types[a->type], i, j);

	}
	//העברה באוטומט
	else {
		fclose(file);
		switchToAutomatic(laxma, i, j);
	}



}
void endWord() {
	char tav;
	FILE* file;
	int i = 0;
	errno_t e1 = fopen_s(&file, "C:/Users/Public/Pictures/endWord.txt", "rt");
	if (e1 != 0) {
		printf("Error open file\n");
		exit(1);
	}
	while (fscanf_s(file, "%c", &tav) != EOF) {
		endWordArr[i++] = tav;
	}
}
void main() {

	//createTokenחלוקה ללקסמות ושליחה לפונקציה
	DeclareStruct();
	HashTable();
	FillingTypes();
	filling();
	final();
	endWord();
	FILE* file=NULL;

	char tav;
	char str[20];
	
	int i = 0,  j = 0,moneRow = 0, moneColumn = 0;
	errno_t e=fopen_s(&file, "C:/Users/Public/Pictures/code.txt", "rt");
	if (e!=0) {
		printf("Error open file\n");
		exit(1);
	}

	

	while (fgetc(file)!=EOF)
	{
	j = 0;
	tav = fgetc(file);
	
	moneColumn++;
	if (tav == '/n'){
		moneRow++;
		moneColumn = 0;
	}
	while (j!= myStrlen(endWordArr) &&tav!=endWordArr[j++])
	{}
	if (i != myStrlen(endWordArr))
	{
		str[i] = '/0';
		if (myStrlen(str)!=0) {
			
			createToken(str, moneRow, moneColumn - myStrlen(str));
		}
		createToken(&tav, moneRow, moneColumn);
		str[0] = '/0';
		i = 0;
	}
	else {
		str[i++] = tav;
	}

}
	fclose(file);
	errno_t e1 = fopen_s(&file, "C:/Users/Public/Pictures/token.txt", "at");
	if (e1 != 0) {
		printf("Error open file\n");
		exit(1);
	}
	fprintf(file, "num line is %d",moneRow);
	//שחרור הזיכרון
	free(types);
	free(HashUniform);
	//free(arrFinal);
	//free(arrAutom);

}


	


	
		
	




 