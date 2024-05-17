#include "Transition.h"
int i = 0, situation = 0, dependent, mone;
TokenPtr var, reduce = NULL;
TreeNodePtr node, node2, myTree;

void Reduce()
{
	if (dependent == -999) {
		printf("Input error\n");
		exit(1);
	}
	mone = 0;
	/*node.arr = (TreeNodePtr*)malloc(sizeof(TreeNodePtr));*/
	
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
//פונקציה המבצעת את המעבר על הקלט עפ"י המטריצה והמחסנית
TreeNodePtr TransitionOfMat()
{
	fillMat();
	fillDerivation();
	fillInput();
	initialize(&s);	//כל עוד המחסנית לא ריקה והקלט לא הסתים
	while (!(isEmpty(&s)) && i != (sizeof(arrInput) / sizeof(arrInput[0]))) {
		push(&s,(void*) &situation);
		//להוסיף מצביעים לפונקציות
	/*	if (!reduce) {
			var = arrInput[i++];
		}
		else {
			var = reduce;
			reduce = NULL;
		}*/
		function_pointers2[REDUCEFILL(reduce)];
		//משתנה שיתכן שהוא shift/reduce/acc
		dependent = arrMat[situation][var->numT];
		//acc
		/*if (var == 0) {
			return i == (sizeof(arrInput) / sizeof(arrInput[0]));
		}*/
		//shift
		node->token=var;
		node->arr = NULL;
		*function_pointers1[REDUCE(dependent)];
		/*if (dependent > 0) {
			push(&s, (void*) &node);
			situation = dependent;
		}
		else {
			if (dependent == -999) {
				printf("Input error\n");
				exit(1);
			}
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
		}*/

	}
	free(node);
	free(node2);
	free(reduce);
	free(var);
	
	//free(arrInput);
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
	
	//שחרור המחסנית
	free(&s);
	return myTree;
}

