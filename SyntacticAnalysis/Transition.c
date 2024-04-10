#include "Transition.h"

//פונקציה המבצעת את המעבר על הקלט עפ"י המטריצה והמחסנית
TreeNodePtr TransitionOfMat()
{
	fillMat();
	fillDerivation();
	fillInput();
	int i = 0, situation = 0,dependent,mone;
	TokenPtr var,var2, reduce=NULL;
	TreeNodePtr node,node2,myTree;
	initialize(&s);
	//כל עוד המחסנית לא ריקה והקלט לא הסתים
	while (!(isEmpty(&s)) && i != (sizeof(arrInput) / sizeof(arrInput[0]))) {
		push(&s,(void*) &situation);
		//להוסיף מצביעים לפונקציות
		if (!reduce) {
			var = arrInput[i++];
		}
		else {
			var = reduce;
			reduce = NULL;
		}
		//משתנה שיתכן שהוא shift/reduce/acc
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
	
	//שחרור המחסנית
	free(&s);
	return myTree;
}
