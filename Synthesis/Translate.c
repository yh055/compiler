#include <stdio.h>
#include <stdlib.h>
#include "Translate.h"
#define LEN 6
#include "C:\Users\��� ���\Pictures\project\LexicalAnalysis\LexicalAnalysis\myString.h"
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

    //���� �� ������� ���
   //���� �� ���� - �� ��� ���� ������ ����� - ������ ������
    int index;
    while (tree->token)
    {
        //���� ������ �� ������ ������� ����� ������
        index = GetIndex(tree->token->lexma);
        //�� ���� ����� - ���� ���� ���� �� ����� ������
        if (index < LEN)
        {
            fprintf(file, "%s", dest[index]);
        }

        //����� ������
        if (tree->token->numT == 45)
        {
            //�� ��� �did?
            TreeNodePtr t = tree;
            //�� ��� �� ���� ����
            while (t + 1 != NULL && t->token->numT != 2 && t->token->numT != 3 && t->token->numT != 6) t++;
            switch (t->token->numT)
            {
            case 2: { fprintf(file, "\nint "); break; }
            case 3: { fprintf(file, "\nfloat "); break; }
            case 6: { { fprintf(file, "\nchar* "); break; }
            default:
                break;
            }

                  //����� �� �� ������ �����
                  fprintf(file, tree->token->lexma);
            }

            //����� ����
            if (tree->token->lexma == '[')
            {
                //����� ��� - ���� ���� ����� ����
                TreeNodePtr t = tree->arr;
                //�� ���� ������� �� �����
                //���� ����� ���� ���� �� �� ����� ���� �� �� ��� ����
                fprintf(file, "= realloc(sizeof(double)*");
                //���� ��' ���� - ��� �� ����� ���� ����� ������
                fprintf(file, t->token->lexma);
                //���� �����
                fprintf(file, ");\n");
            }

            //����� �� ����
            fprintf(file, t->token->lexma);
            //���� ����� ��� ���
            tree = tree->arr;
        }
    }
}

//45- �����
//46- ��������
//47 - ������

int main() {}