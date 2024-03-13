#include "aotomaton.h"
int** arrAutom;
FinalPtr arrFinal ;
int mone = 0;

//פונקציה המקבלת תו ומחזירה את מקומו 
int location(char tav) {
	int mone = 0;
	int loc = ((QUOTATION(tav) * 10 + DOT(tav)) * 10 + NUM(tav))*10 + LETTER(tav);
	while (loc>0) {
		mone++;
		loc/=10;
    }
	return mone;
	

}
//פונקציה הממלאה את המטריצה בהתאם לאוטומט
void filling()
{
	/* arrAutom = (int**)malloc(sizeof(int*) * (mone + 1));*/
	char by[6];
	int situation, gotos;
	FILE* file=NULL;
	errno_t e = fopen_s(&file, "C:/Users/Public/Pictures/automaton.txt", "rt");
	if (e != 0) {
		printf("Error open file\n");
		exit(1);
	}
	while (fscanf_s(file, "%d %s %d", &situation, by,6, &gotos) != EOF) {
		if (mone - 1 < situation) {
			arrAutom = (int**)realloc(&arrAutom, sizeof(int*) * (mone + 1));
			if (arrAutom == NULL) {
				printf("Memory not allocated\n");
				exit(1);
			}
			
			arrAutom[situation] = (int*)realloc(&arrAutom[situation], sizeof(int) * LEN);
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
	/*arrAutom = arrAutom1;*/
}

//פןנקציה הממלאה את מערך המצבים הסופיים
void final1()
{
	int num;
	char token[10];
	int num2;
	FILE* file=NULL;
	errno_t e = fopen_s(&file, "C:/Users/Public/Pictures/final.txt", "rt");
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
//פונקצית המעבר על האוטומט ויצור טוקנים
void switchToAutomatic(char* laxma,int i,int j) {
	FILE* file=NULL;
	errno_t e = fopen_s(&file, "C:/Users/Public/Pictures/token.txt", "at");
	if (e != 0) {
		printf("Error open file\n");
		exit(1);
	}
	char* laxma2 = laxma;
	int numS = 0;
	while (laxma2) {
		numS = arrAutom[numS][location(*laxma2)];
		if (numS == -1) {
			//לזרוק אסימון שגיאה
			fprintf(file, "Error -1 line %d column %d", i, j);
			
		}
    }
	if (arrFinal[numS].str[0] == NULL) {
		//לזרוק אסימון שגיאה
		fprintf(file, "Error -1 line %d column %d",i,j );
	}
	else {
		//ליצור אסימון מהסוג המתאים לכתוב
		fprintf(file, "%s %s line %d column %d", laxma, types[arrFinal[numS].num], i, j);
	}
	fclose(file);
}