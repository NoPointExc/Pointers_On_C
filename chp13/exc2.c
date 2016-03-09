#include "list.h"

void travel( Node *root, void (*fun)( Node *node ) );
void print(Node *node);
int main(int argc, char const *argv[])
{
	int *arr=(int*)malloc(argc*sizeof(int));
	int i;
	for(i=0;i<argc;i++){
		arr[i]=*argv[i] -TO_CHAR;
	}
	Node *root=create_list(arr,argc);
	char *str=to_str(root,argc);
	printf("%s \n",str);
	travel(root,&print);
	return 1;
}

void travel( Node *root, void (*fun)( Node *node ) )
{
	while(root!=NULL){
		fun(root);
		root=root->next;
	}

}

void print(Node *node){
	printf("%c, ",node->val + TO_CHAR);
}