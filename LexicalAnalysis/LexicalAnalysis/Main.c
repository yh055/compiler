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
#include <malloc.h>

char endWordArr[sizeEnd];

void createToken(char* laxma, int i, int j) {
	UniformPtr a = NULL;
	FILE* file = NULL;

	errno_t e = fopen_s(&file, "..\..\token.txt", "at");
	if (e!=0) {
		printf("Error open file token\n");
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
		fprintf(file, "%s %s line %d column %d", a->str, a->type, i, j);

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
	errno_t e1 = fopen_s(&file, "C:/Users/Public/Pictures/Requiredfiles/endWord.txt", "rt");
	if (e1 != 0) {
		printf("Error open file endWord\n");
		exit(1);
	}
	while (fscanf_s(file, "%c", &tav) != EOF) {
		endWordArr[i++] = tav;
	}
}
void main() {
	//הגדלת גודל הערימה
	/*heapinit(50, 100);*/
	//createTokenחלוקה ללקסמות ושליחה לפונקציה
	DeclareStruct();
	HashTable();
	/*FillingTypes();*/
	filling();
	final1();
	endWord();
	FILE* file=NULL;

	char tav;
	char str[20];
	
	int i = 0,  j = 0,moneRow = 0, moneColumn = 0;
	errno_t e=fopen_s(&file, "C:/Users/Public/Pictures/Requiredfiles/code.txt", "rt");
	if (e!=0) {
		printf("Error open file code\n");
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
	errno_t e1 = fopen_s(&file, "C:/Users/Public/Pictures/Requiredfiles/token.txt", "at");
	if (e1 != 0) {
		printf("Error open file token\n");
		exit(1);
	}
	fprintf(file, "num line is %d",moneRow);
	//שחרור הזיכרון

	/*free(types);*/
	for (size_t i = 0; i < 101; i++)
	{
		free(HashUniform[i]);
	}
	
	/*free(arrFinal);*/
	//free(arrAutom);

}


	


	
		
	




 