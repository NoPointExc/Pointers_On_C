#include "list.h"

Node * sll_reverse(Node *first);

void main(void){
	int arr[]={1,2,3,4,5,6,7,8,9};
	//int arr[]={1,2,3};
	//int arr[]={1,2};
	//int arr[]={1};
	int len=sizeof(arr)/sizeof(int);
	Node *list=create_list(arr,len);
	char *str=to_str(list,len);
	printf("%s\n",str);	
	Node *rev_list=sll_reverse(list);
	str=to_str(rev_list,len);
	printf("%s\n",str);
	free(str);
	free(list);
	free(rev_list);
}

/**
 * reverse the whole linked list heading with *first
 * @param  first :the first node of the input list
 * @return       the new head leading the list
 */
Node *sll_reverse(Node *first){
	if(first==NULL) return NULL;	
	Node *fwd, *mid,*bck;	
	fwd=first;
	mid=fwd->next;
	if(mid==NULL) return first;
	bck=mid->next;
	fwd->next=NULL;	
	while(bck!=NULL){
		mid->next=fwd;
		fwd=mid;
		mid=bck;
		bck=bck->next;		
	}
	mid->next=fwd;
	return mid;
}