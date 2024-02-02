typedef struct UniformRec
{
	char str[20];
	int type;
	struct UniformRec* next;
}UniformRec, * UniformPtr;
typedef struct originalRec
{
	char str[20];
	//מצביע למקום בקוד
	struct originalRec* next;
}originalRec, * originalPtr;
UniformPtr HashUniform[101];
char** types;
