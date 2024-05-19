#include "mainLex.h"

char endWordArr[sizeEnd];

void createToken(char* laxma, int i, int j) {
	UniformPtr a = NULL;
	FILE* file = NULL;

	errno_t e = fopen_s(&file, "C:\\Users\\Public\\Pictures\\Requiredfiles\\token.txt", "at");
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
	char str[255];
	
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
	while (j!= myStrlen(endWordArr) &&tav!=endWordArr[j++])
	{}
	if (i == myStrlen(endWordArr))
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
	tav = fgetc(file);
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


	


	
		
	




 