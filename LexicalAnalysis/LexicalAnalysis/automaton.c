#include "aotomaton.h"
int** arrAutom;
FinalPtr arrFinal ;
int mone = 0;
#define GARBAGE 0xcdcdcdcd
//������� ������ �� ������� �� ����� 
int location(char tav) {
	int mone = 0;
	int loc = ((QUOTATION(tav) * 10 + DOT(tav)) * 10 + NUM(tav))*10 + LETTER(tav);
	while (loc>0) {
		mone++;
		loc/=10;
    }
	return mone;
	

}
//������� ������ �� ������� ����� �������
void filling()
{

	char by[6];
	int situation, gotos;
	FILE* file=NULL;
	errno_t e = fopen_s(&file, "C:/Users/Public/Pictures/Requiredfiles/automaton.txt", "rt");
	if (e != 0) {
		printf("Error open file automaton\n");
		exit(1);
	}
	//arrAutom = (int**)malloc(sizeof(int*) *1);
	while (fscanf_s(file, "%d %s %d", &situation, by,6, &gotos) != EOF) {
		if (mone - 1 < situation) {
			arrAutom = (int**)realloc(arrAutom, sizeof(int*) * (mone + 1));
			if (arrAutom == NULL) {
				printf("Memory not allocated\n");
				exit(1);
			}
			if (arrAutom[situation] == NULL || arrAutom[situation]== GARBAGE) {
				arrAutom[situation] = (int*)malloc(sizeof(int) * LEN);
			}
			else {
				arrAutom[situation] = (int*)realloc(arrAutom[situation], sizeof(int) * LEN);
			}
			
			if (arrAutom[situation] == NULL) {
				printf("Memory not allocated\n");
				exit(1);
			}
			for (int i = 0; i < LEN; i++)
			{
				arrAutom[situation][i] = -1;
			}
			mone++;
		}
		arrAutom[situation][location(by[0])] = gotos;
	}
	fclose(file);

}

//������� ������ �� ���� ������ �������
void final1()
{
	int num;
	char token[10];
	int num2;
	FILE* file=NULL;
	errno_t e = fopen_s(&file, "C:/Users/Public/Pictures/Requiredfiles/final.txt", "rt");
	if (e != 0) {
		printf("Error open file\n");
		exit(1);
	}
	arrFinal = (FinalPtr)malloc(mone * sizeof(Final));
	if (arrFinal == NULL) {
		printf("Memory not allocated\n");
		exit(1);
	}
	for (int i = 0; i < mone; i++)
	{
		
		arrFinal[i].str[0] = NULL;
		arrFinal[i].num = -1;
	}
	while (fscanf_s(file, "%d %s %d", &num, token,10,&num2) != EOF) {
		myStrcpy(arrFinal[num].str , token);
		arrFinal[num].num = num2;
	}
}
//������� ����� �� ������� ����� ������
void switchToAutomatic(char* laxma,int i,int j) {
	FILE* file=NULL;
	errno_t e = fopen_s(&file, "C:/Users/Public/Pictures/Requiredfiles/token.txt", "at");
	if (e != 0) {
		printf("Error open file\n");
		exit(1);
	}
	char* laxma2 = laxma;
	int numS = 0;
	while (laxma2) {
		numS = arrAutom[numS][location(*laxma2)];
		if (numS == -1) {
			//����� ������ �����
			fprintf(file, "Error -1 line %d column %d", i, j);
			exit(1);
		}
    }
	if (arrFinal[numS].str[0] == NULL) {
		//����� ������ �����
		fprintf(file, "Error -1 line %d column %d",i,j );
		exit(1);
	}
	else {
		//����� ������ ����� ������ �����
		fprintf(file, "%s %s line %d column %d", laxma, arrFinal[numS].num, i, j);
	}
	fclose(file);
}