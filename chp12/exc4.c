#include <stdio.h>

#include "list.h"


Node * sll_reverse(Node *first);

void main(void){
	int arr[]={1,2,3,4,5,6,7,8,9};
	int len=sizeof(arr)/sizeof(int);
	Node *list=create_list(arr,len);
	char *str=to_str(list,len);
	printf("%s\n",str);
	
	//sll_reverse(list);
	str=to_str(list,len);
	printf("%s\n",str);

	free(list);
	free(str);
}

/**
 * reverse the whole linked list heading with *first
 * @param  first :the first node of the input list
 * @return       the new head leading the list
 */
Node * sll_reverse(Node *first){
	if(first==NULL) return NULL;
	
	/**
	 * travel to the end of the list, get the tail and assigned it to the new_head
	 */	
	Node *new_head=first;
	Node *frd, *bck;
	while(new_head->next!=NULL) new_head=new_head->next;
	
	/**
	 * frd travel from first node to the new head (end), move all nodes from frond to back
	 */
	for(frd=first,bck=new_head;frd!=new_head;frd=frd->next){
		bck->next=frd;
		bck=bck->next;
		bck->next=NULL;
	}
	return new_head;
}