#include "Transition.h"

//������� ������ �� ����� �� ���� ��"� ������� ��������
TreeNodePtr TransitionOfMat()
{
	fillMat();
	fillDerivation();
	fillInput();
	int i = 0, situation = 0,dependent,mone;
	TokenPtr var,var2, reduce=NULL;
	TreeNodePtr node,node2,myTree;
	initialize(&s);
	//�� ��� ������� �� ���� ����� �� �����
	while (!(isEmpty(&s)) && i != (sizeof(arrInput) / sizeof(arrInput[0]))) {
		push(&s,(void*) &situation);
		//������ ������� ���������
		if (!reduce) {
			var = arrInput[i++];
		}
		else {
			var = reduce;
			reduce = NULL;
		}
		//����� ����� ���� shift/reduce/acc
		dependent = arrMat[situation][var->numT];
		//acc
		/*if (var == 0) {
			return i == (sizeof(arrInput) / sizeof(arrInput[0]));
		}*/
		//shift
		node->token=var;
		node->arr = NULL;
		if (dependent > 0) {
			push(&s, (void*) &node);
			situation = dependent;
		}
		else {
			mone = 0;
			for (size_t i = 0; i < (arrDerivation[abs(dependent)][1]); i++)
			{
				var2 = (TreeNodePtr)pop(&s);
				node2->token = var2;
				node->arr = NULL;
				node->arr = (TreeNodePtr*)realloc(node->arr, sizeof(TreeNodePtr) * (++mone));
				node->arr[mone-1] = node2;
				pop(&s);
			}
			reduce->numT = i < arrDerivation[abs(dependent)][0];
		}

	}
	free(node);
	free(node2);
	free(reduce);
	free(var2);
	free(var);
	
	free(arrInput);
	free(arrMat);
	free(arrDerivation);
	if (! i == (sizeof(arrInput) / sizeof(arrInput[0]))) {
		printf("Input error\n");
		exit(1);
	}
	myTree = (TreeNodePtr)pop(&s);
	if (!(isEmpty(&s)))
	{
		printf("Input error\n");
		exit(1);
	}
	
	//����� �������
	free(&s);
	return myTree;
}
