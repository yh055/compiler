#include <stdio.h>
#include <stdlib.h>
#include "Translate.h"
#define LEN 6
#include "C:\Users\יעל חדד\Pictures\project\LexicalAnalysis\LexicalAnalysis\myString.h"
char* source[LEN] = { "fun","loop","string","print","input","next" };
char* dest[LEN] = { "void","while","char*","printf","scanf(\"%s\"","continue" };

int GetIndex(char* lex)
{
    int i;
    for (i = 0; i < LEN && !myStrcmp(lex, source[i]); i++);
    return i;
}

void Translation(TreeNodePtr tree)
{
    
    


    FILE* file;
    errno_t e = fopen_s(&file, "C:/Users/Public/Pictures/Requiredfiles/newCode.txt", "wt");
    if (e != 0) {
        printf("Error open file newCode\n");
        exit(1);
    }

    //מעבר על הטוקנים בעץ
   //עבור כל טוקן - אם הוא קיים במילון המקור - להחליף במילון
    int index;
    while (tree->token)
    {
        //קבלת המיקום של הלקסמה הנוכחית במערך המילון
        index = GetIndex(tree->token->lexma);
        //אם קיים במערך - כתוב בקוד החדש את תוצאת המילון
        if (index < LEN)
        {
            fprintf(file, "%s", dest[index]);
        }

        //הגדרת משתנים
        if (tree->token->numT == 45)
        {
            //מה סוג הdid?
            TreeNodePtr t = tree;
            //כל עוד לא הגעת לערך
            while (t + 1 != NULL && t->token->numT != 2 && t->token->numT != 3 && t->token->numT != 6) t++;
            switch (t->token->numT)
            {
            case 2: { fprintf(file, "\nint "); break; }
            case 3: { fprintf(file, "\nfloat "); break; }
            case 6: { { fprintf(file, "\nchar* "); break; }
            default:
                break;
            }

                  //תעתיק את שם המשתנה בעצמו
                  fprintf(file, tree->token->lexma);
            }

            //הגדרת מערך
            if (tree->token->lexma == '[')
            {
                //הטוקן הבא - שהוא גודל המערך החדש
                TreeNodePtr t = tree->arr;
                //אם גודל המחרוזת לא מספיק
                //כתוב הגדרת מערך כאשר כל תא בגודל כפול כי זה הכי גדול
                fprintf(file, "= realloc(sizeof(double)*");
                //הוסף מס' תאים - כמו מה שכתוב אחרי הסוגר המרובע
                fprintf(file, t->token->lexma);
                //הוסף סגירה
                fprintf(file, ");\n");
            }

            //שרשור כל השאר
            fprintf(file, t->token->lexma);
            //מעבר לטוקן הבא בעץ
            tree = tree->arr;
        }
    }
}

//45- הגדרה
//46- פונקציות
//47 - לולאות

int main() {}