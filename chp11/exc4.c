#include <stdio.h>
#include <stdlib.h>

#include "list.h"

Node* create_list(int *vals, int size);



void main(void){
 	//int vals[]={1,2,3,4,5};
 	
 	int *vals=NULL;
 	int size=sizeof(vals)/sizeof(int);
 	Node* head=create_list(vals,size);
 	if(head==NULL) printf("%s\n","head==NULL");
 	Node *p=head;
	int i;

	while(p!=NULL){
		printf("%i\n",p->val );
		p=p->next;
	}

		


}

Node* create_list(int *vals, int size){
	Node *list=(Node*)malloc(size*sizeof(Node));
	if(list==NULL || vals==NULL) return NULL;
	Node *head=list;	
	int i;	
	for(i=0;i<size;i++){
		/**
		 * point to next node
		 */
		if(i<size-1) list->next=&head[i+1];		
		else list->next=NULL;
		/**
		 * assign val
		 */
		list->val=vals[i];
		list=list->next;
	}
	
	return head;
}