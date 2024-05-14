#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "Metrix.h"
#define REDUCE(x) x<=0

#define REDUCEFILL(x) x!= NULL
typedef struct
{
	TokenPtr token;
	struct TreeNodePtr* arr;
} TreeNode, *TreeNodePtr;
Stack s;