#include <stdlib.h>
#include <stdio.h>

#define TO_CHAR '0'-0
#define NUL '\0'

typedef struct NODE{
	struct NODE *next;
	int val;	
} Node;

/**
 * creat a list with given int array
 * @param  vals :points to the first int in the array
 * @param  size :the size of the array
 * @return      pointer points to the head of created linked list 
 */
Node* create_list(int *vals, int size){
	Node *list=(Node*)malloc(size*sizeof(Node));
	if(list==NULL || vals==NULL) return NULL;
	Node *head=list;	
	int i;	
	for(i=0;i<size;i++){
		if(i<size-1) list->next=&head[i+1];		
		else list->next=NULL;
		list->val=vals[i];
		list=list->next;
	}
	
	return head;
}

/**
 * display the list in a string
 * @param  root :pointed to the first list node  
 * @return      a list in string
 * @warnning  only number 0~9 is considerd
 */
char* to_str(Node* root,int len){
	char *str=malloc(3*len*sizeof(char)+1);
	if(root==NULL) {
		str[0]=NUL;
		return str;
	};
	char *it=str;
	while(root!=NULL){
		it[0]=(char)(root->val + TO_CHAR);
		it[1]='-';
		it[2]='>';
		it+=3;
		root=root->next;
	}
	it[-2]=NUL;
	return str;
}