#include "HashTableReserves.h"
UniformPtr HashUniform[101];
//char** types;
void DeclareStruct()
{
	for (size_t i = 0; i < 101; i++)
	{
		HashUniform[i] = NULL;
	}
}


//פונקציה שקוראת מקובץ סוגי הטוקנים וממלאה במערך
//ניתוח לשיעורין
//void FillingTypes() {
//	int sizeTypes = 10;
//	types = (char**)malloc(sizeTypes * sizeof(char*));
//	int i=0;
//	if (types == NULL) {
//		printf("Memory not allocated\n");
//		exit(1);
//	}
//	char type[30];
//	FILE* file=NULL;
//	errno_t e = fopen_s(&file, "C:/Users/Public/Pictures/types.txt", "rt");
//	if (e!=0) {
//		printf("Error open file\n");
//		exit(1);
//	}
//	while (fscanf_s(file, "%s", type ,30) != EOF) {
//		if (i == sizeTypes) {
//			sizeTypes = sizeTypes * 2;
//			types = (char**)realloc(&types, sizeTypes * sizeof(char[20]));
//			if (types == NULL) {
//				printf("Memory not allocated\n");
//				exit(1);
//			}
//		}
//		types[i] = (char*)malloc(20 * sizeof(char));
//		myStrcpy(types[i], type);
//		i++;
//
//	}
//}
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
	int y = HashFunc(word);
	if (HashUniform[y] == NULL) {
		
		HashUniform[y] = (UniformRec*)malloc(sizeof(UniformRec));

		if (HashUniform[y] == NULL) {
			printf("Memory not allocated\n");
			exit(1);
		}
	
		myStrcpy(HashUniform[y]->str , word);
		HashUniform[y]->type = type;
		HashUniform[y]->next = (UniformPtr)malloc(sizeof(UniformRec));
	}
	else
	{
		UniformPtr next1 = HashUniform[y];
		while (next1->next && next1->next!=Garbage)
			next1=next1->next;
		myStrcpy(next1->str , word);
		next1->type = type;
		next1->next = (UniformPtr)malloc(sizeof(UniformRec));

	}

}
// פונקציה הממלאה את טבלת הגיבוב של 
void HashTable() {
	char word[10];
	int num=0;
	FILE* file=NULL;
	/*
	for (int i = 0; i <= 100; i++) {
		HashUniform[i] = NULL;
	}*/
	errno_t e= fopen_s(&file, "C:/Users/Public/Pictures/Requiredfiles/reserves.txt", "rt");
	if (e!=0) {
		printf("Error open file reserves\n");
		exit(1);
	}
	
	while (fscanf_s(file, "%s %d", word, 10,&num) != EOF) {
		
		InHash(word, num);
	}
	fclose(file);
}
