#include <stdio.h>
#include <stdlib.h>

#include "list.h"

Node* get(Node *from,int val);

void main(void){
	int arr[]={1,2,3,4,5,6,7,8,9};
	//int *arr=NULL;
	Node *head=create_list(arr,sizeof(arr)/sizeof(int));
	int val=-1;
	Node *p=get(head,val);
	if(p!=NULL)printf("*p=%i\n",p->val);
	else printf("%s\n","*p=NULL" );
}

Node* get(Node *from,int val){
	while(from!=NULL && from->val!=val) from=from->next;
	return from;
}