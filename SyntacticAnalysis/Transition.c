#include "Transition.h"
#include "../LexicalAnalysis/LexicalAnalysis/mainLex.h"
int i = 0, situation = 0, dependent, mone;
TokenPtr var, reduce = NULL;
TreeNodePtr node, node2, myTree;
TokenPtr* arrInput;
Stack1 s;
void Reduce()
{
	if (dependent == -999) {
		printf("Input error\n");
		exit(1);
	}
	mone = 0;

	
	for (size_t i = 0; i < (arrDerivation[abs(dependent)][1]); i++)
	{
		 
		node2= (TreeNodePtr)pop(&s);
		node->arr = NULL;
		node->arr = (TreeNodePtr*)realloc(node->arr, sizeof(TreeNodePtr) * (++mone));
		node->arr[mone - 1] = node2;
		pop(&s);
	}
	reduce->numT = arrDerivation[abs(dependent)][0];

}
void Shift()
{
	push(&s, (void*)&node);
	situation = dependent;
}
void ReduceFill()
{
	var = reduce;
	reduce = NULL;
}
void ReduceNotFill()
{
	var = arrInput[i++];
}
void(*function_pointers1[2])() = {  Shift,Reduce };
void(*function_pointers2[2])() = {  ReduceNotFill ,ReduceFill };
//������� ������ �� ����� �� ���� ��"� ������� ��������
TreeNodePtr TransitionOfMat()
{
	fillMat();
	fillDerivation();
	fillInput();
	initialize(&s);	//�� ��� ������� �� ���� ����� �� �����
	while (!(isEmpty(&s)) && i != (sizeof(arrInput) / sizeof(arrInput[0]))) {
		push(&s,(void*) &situation);

		function_pointers2[REDUCEFILL(reduce)];
		//����� ����� ���� shift/reduce/acc
		dependent = arrMat[situation][var->numT];
		
		node->token=var;
		node->arr = NULL;
		*function_pointers1[REDUCE(dependent)];
	

	}
	free(node);
	free(node2);
	free(reduce);
	free(var);
	
	
	free(arrMat);
	free(arrDerivation);
	if (! i == (sizeof(arrInput) / sizeof(arrInput[0]))) {
		free(&s);
		printf("Input error\n");
		exit(1);
	}
	myTree = (TreeNodePtr)pop(&s);
	if (!(isEmpty(&s)))
	{
		free(&s);
		printf("Input error\n");
		exit(1);
	}
	
	//����� �������
	free(&s);
	return myTree;
}

int main() {}