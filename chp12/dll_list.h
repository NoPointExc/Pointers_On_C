typedef struct DLL_NODE{
	int val;
	struct DLL_NODE *bwd;	
	struct DLL_NODE *fwd;
} Node;


Node *create_list(int *vals,int len);
char *to_str(Node *list, int size);
int dll_remove(Node *rootp, Node *node);

