#include "Metrix.h"
#include "../LexicalAnalysis/LexicalAnalysis/myString.h"
TokenPtr* arrInput;
//מילוי המטריצה בצורה דינמית ע"י מעבר על הקובץ
void fillMat() {
    FILE* file=NULL;
    errno_t er = fopen_s(file,"C:/Users/יעל חדד\Pictures\mat.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
   
    numL = 0;
    numC = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        arrMat = (int**)realloc(&arrMat, sizeof(int*) * (++numL));
        numC = 0;
        char* line = my_strtok(buffer, ",");
        while (line != NULL) {
            arrMat[numL-1] = (int*)realloc(&arrMat[numL-1], sizeof(int) * ++numC);
            arrMat[numL - 1][numC-1]=line;
            line = my_strtok(NULL, ",");
        }
       
    
   
    }


    fclose(file);
}
//ממלא את מערך חוקי הגזירה
void fillDerivation() {
    int numR, numD, numC;
    errno_t e = fopen_s(&file, "C:/Users/יעל חדד\Pictures\project\derivational.txt", "rt");
    if (e != 0) {
        printf("Error open file\n");
        exit(1);
    }
    arrDerivation = malloc(sizeof(int*) * RULES_L);
    if (arrDerivation == NULL) {
        printf("Memory not allocated\n");
        exit(1);
    }
    while (fscanf_s(file, "%d %d %d",&numR,&numD,&numC) != EOF) {
      
        arrDerivation[numR]= malloc(sizeof(int) * RULES_C);
        if (arrDerivation[numR] == NULL) {
            printf("Memory not allocated\n");
            exit(1);
        }
        arrDerivation[numR][0] = numD;
        arrDerivation[numR][1] = numC;
       }
}//ממלאה את מערך מספרי הקלט מקובץ הטוקנים
//ניתוח לשיעורין
void fillInput()
{
    int numT, i, j, mone = 5,k=0;
    arrInput = malloc(sizeof(TokenPtr*) * mone);
    
    char* lexma="";
    errno_t e = fopen_s(&file, "C:/Users/יעל חדד\Pictures\project\LexicalAnalysis\token.txt", "rt");
    if (e != 0) {
        printf("Error open file\n");
        exit(1);
    }
    while (fscanf_s(file, "%s %d %d %d", lexma,20, &numT, &i,&j) != EOF) {
        if (k >= mone) {
            mone *= 2;
            arrInput = (TokenPtr*)realloc(&arrInput, sizeof(TokenPtr) * (mone));
        }
        arrInput[k]->numT = numT;
        myStrcpy(arrInput[k]->lexma, lexma);
        arrInput[k]->i = i;
        arrInput[k++]->j = j;
    }
}