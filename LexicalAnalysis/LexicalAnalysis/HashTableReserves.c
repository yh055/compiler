#include "HashTableReserves.h"


//פונקציה שקוראת מקובץ סוגי הטוקנים וממלאה במערך
void FillingTypes() {
	int sizeTypes = 10;
	types = (char**)malloc(sizeTypes * sizeof(char[20]));
	int i=0;
	if (types == NULL) {
		printf("Memory not allocated\n");
		exit(1);
	}
	char type[30];
	FILE* file=NULL;
	errno_t e = fopen_s(&file, "C:/Users/Public/Pictures/types.txt", "rt");
	if (e!=0) {
		printf("Error open file\n");
		exit(1);
	}
	while (fscanf_s(file, "%s", &type) != EOF) {
		if (i == sizeTypes) {
			sizeTypes = sizeTypes * 2;
			types = (char**)realloc(&types, sizeTypes * sizeof(char[20]));
			if (types == NULL) {
				printf("Memory not allocated\n");
				exit(1);
			}
		}
		myStrcpy(types[i], type);
		i++;

	}
}
//פונקצית הגיבוב
int HashFunc(char* word)
{
	int num=0, i = 0, j = 1;

	while (word[i]) {
		num += (int)word[i++] * j;
		j *= 10;
	}
	return num % LemReserves;

}

void InHash(char* word, int type) {

	if (HashUniform[HashFunc(word)] == NULL) {
		HashUniform[HashFunc(word)] = (UniformPtr)malloc(1 * sizeof(UniformRec));
		if (HashUniform[HashFunc(word)] == NULL) {
			printf("Memory not allocated\n");
			exit(1);
		}
		myStrcpy(HashUniform[HashFunc(word)]->str , word);
		HashUniform[HashFunc(word)]->type = type;
		HashUniform[HashFunc(word)]->next = (UniformPtr)malloc(1 * sizeof(UniformRec));
	}
	else
	{
		UniformPtr next1 = HashUniform[HashFunc(word)]->next;
		while (next1)
			next1->next;
		myStrcpy(&next1->str , word);
		next1->type = type;
		next1->next = NULL;

	}

}
// פונקציה הממלאה את טבלת הגיבוב של 
void HashTable() {
	char word[10];
	int num;
	FILE* file=NULL;
	for (int i = 0; i <= 100; i++) {
		HashUniform[i] = NULL;
	}
	errno_t e= fopen_s(&file, "C:/Users/Public/Pictures/reserves.txt", "rt");
	if (e!=0) {
		printf("Error open file\n");
		exit(1);
	}
	
	while (fscanf_s(&file, "%s %d", word, &num) != EOF) {
		
		InHash(word, num);
	}
	fclose(&file);
}
