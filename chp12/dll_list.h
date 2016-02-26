#include <stdio.h>
#include <stdlib.h>

#define NUL '\0'

typedef struct DLL_NODE{
	int val;
	struct DLL_NODE *bwd;	
	struct DLL_NODE *fwd;
} Node;

/**
 * create a double-list from given array
 * @param  vals :points to the array
 * @param  size :the size of the array
 * @return      a pointer points to the double-linked-list 
 */
Node *create_list(int *vals){
	int len=sizeof(vals)/sizeof(vals[0]);
	printf("size=%d\n",len);
	Node *list=(Node*)malloc(len*sizeof(Node)+1);
	if(list==NULL || vals==NULL) return NULL;
	int i;
	for(i=0;i<len;i++){
		list[i].val=vals[i];
		if(i!=0) *list[i].bwd=list[i-1];
		if(i!=len-1) *list[i].fwd=list[i+1];		
	}
	return list;	
}

/**
 * display a list in the the form of str.
 * @param  list :points to the first node in the list
 * @param  size [description]
 * @return      [description]
 */
char *to_str(Node *list, int size){
	printf("%d\n",1);
	char *str=(char*)malloc(4*size*sizeof(char)+1);
	if(list==NULL){
		str[0]=NUL;
		return str;
	}
	Node *head=list, *p=list;
	char *it=str;
	do{
		it[0]=p->val;
		it[1]='<';
		it[2]='=';
		it[3]='>';
		it+=4;
		p=p->fwd;
	}while(it->bwd!=head)
	it[-3]=NUL;
	return str;
}