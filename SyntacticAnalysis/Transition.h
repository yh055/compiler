#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "Metrix.h"
typedef struct
{
	TokenPtr token;
	struct TreeNodePtr* arr;
} TreeNode, * TreeNodePtr;
Stack s;