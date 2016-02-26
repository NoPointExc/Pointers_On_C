#include <stdio.h>

#include "list.h"


Node * sll_reverse(Node *first);

void main(void){
	int arr[]={1,2,3,4,5,6,7,8,9};
	int len=sizeof(arr)/sizeof(int);
	Node *list=create_list(arr,len);
	char *str=to_str(list,len);
	printf("%s\n",str);
	free(str);	
	free(list);

	Node *rev_list=sll_reverse(list);
	// str=to_str(rev_list,len);
	// printf("%s\n",str);
	// free(str);
	free(rev_list);

}

/**
 * reverse the whole linked list heading with *first
 * @param  first :the first node of the input list
 * @return       the new head leading the list
 */
Node *sll_reverse(Node *first){
	if(first==NULL) return NULL;
	
	/**
	 * travel to the end of the list, get the tail and assigned it to the new_head
	 */	
	Node *fwd, *mid,*bck;
	
	fwd=first;
	mid=fwd->next;
	bck=mid->next;
	fwd->next=NULL;	
	while(bck!=NULL){
		//printf("%d %d %d, ",fwd->val,mid->val,bck->val );		
		mid->next=fwd;
		fwd=mid;
		mid=bck;
		bck=bck->next;		
	}
	mid->next=fwd;
	printf("%d %d %d \n",mid->val,mid->next->val, mid->next->next->val);

	return mid;
}