#include <stdio.h>
#include <stdlib.h>
#include "stack1.h"
#include "Metrix.h"
#define REDUCE(x) x<=0

#define REDUCEFILL(x) x!= NULL

typedef struct TreeNode1
{
	TokenPtr token;
	struct TreeNode1** arr;
	
} TreeNode, *TreeNodePtr;
