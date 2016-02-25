#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int get_size(Node* head);

void main(void){
	int arr[]={1,2};
	//int *arr=NULL;
	Node *head=create_list(arr,sizeof(arr)/sizeof(int));
	int size=get_size(head);
	printf("size=%d\n", size);
}

int get_size(Node* head){
	int count=0;
	while(head!=NULL) {
		head=head->next;
		count++;
	}	
	return count;
}