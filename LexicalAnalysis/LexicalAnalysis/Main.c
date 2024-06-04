#include "mainLex.h"


char endWordArr[sizeEnd];
void createToken(char *laxma, int i, int j) {

	UniformPtr a = NULL;
	FILE* file = NULL;

	errno_t e = fopen_s(&file, "C:\\Users\\Public\\Pictures\\Requiredfiles\\token.txt", "wt");
	if (e!=0) {
		printf("Error open file token\n");
		exit(1);
	}
	

	
	
	int iii = HashFunc(laxma);
	a = HashUniform[iii];
	while (a->next!= Garbage && myStrcmp(a->str , laxma)!=0) {
		a = a->next;
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
	char enter;
	FILE* file;
	int i = 0;
	errno_t e1 = fopen_s(&file, "C:/Users/Public/Pictures/Requiredfiles/endWord.txt", "rt");
	if (e1 != 0) {
		printf("Error open file endWord\n");
		exit(1);
	}
	while (fscanf_s(file, "%c", &tav) != EOF) {
		fscanf_s(file, "%c", &enter);
		endWordArr[i++] = tav;
	}
}
void LexicalMain() {

	DeclareStruct();
	HashTable();
	
	filling();
	final1();
	endWord();
	FILE* file=NULL;

	char tav;
	char str[25];
	
	int i = 0,  j = 0,moneRow = 0, moneColumn = 0;
	errno_t e=fopen_s(&file, "C:\\Users\\Public\\Pictures\\Requiredfiles\\code.txt", "rt");
	if (e!=0) {
		printf("Error open file code\n");
		exit(1);
	}

	
	tav = fgetc(file);
	while (tav!=EOF)
	{
	j = 0;

	
	moneColumn++;
	if (tav == '/n'){
		moneRow++;
		moneColumn = 0;
	}
	//כל עוד התו שונה מהתוים המסיימים
	while (j!= myStrlen(endWordArr) &&tav!=endWordArr[j++])
	{}
	//אם התו שווה לאחד מהתוים המסיימים
	if (j != myStrlen(endWordArr))
	{
		str[i] = '\0';
		if (myStrlen(str)!=0) {
			
			createToken(str, moneRow, moneColumn - myStrlen(str));
		}
		createToken(&tav, moneRow, moneColumn);
		str[0] = '\0';
		i = 0;
	}
	else {
		str[i++] = tav;
	}
	tav = fgetc(file);
}
	fclose(file);
	errno_t e1 = fopen_s(&file, "C:/Users/Public/Pictures/Requiredfiles/token.txt", "at");
	if (e1 != 0) {
		printf("Error open file token\n");
		exit(1);
	}
	fprintf(file, "num line is %d",moneRow);
	
	for (size_t i = 0; i < 101; i++)
	{
		free(HashUniform[i]);
	}
	
	

}
int main(){
	
	
	LexicalMain();


	
}
	


	
		
	




 