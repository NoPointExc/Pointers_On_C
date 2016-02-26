#include "list.h"

#define TRUE 1
#define FALSE 0

int sll_remove(Node **rootp, Node *node);

void main(void){
	int arr[]={2};
	int len=sizeof(arr)/sizeof(arr[0]);
	Node *list=create_list(arr,len);
	int rst=sll_remove(&list,list);
	char *str=to_str(list,len);
	printf("rst=%d str=%s\n",rst,str);	
}

/**
 * remove a node from the linked list 
 * @param  rootp :points to the pointer which points to the root node
 * @param  node  :the node to remove
 * @return       flase: no indicate node, true: remove successed
 */
int sll_remove(Node **rootp, Node *node){
	Node *cur,*next;
	if(*rootp==NULL) return FALSE;
	if(*rootp==node){
		*rootp=(*rootp)->next;
		return TRUE;
	}
	for(cur=*rootp;(next=cur->next)!=NULL;cur=next){
		if(next==node){
			cur->next=next->next;
			return TRUE;
		}
	}
	return FALSE;
}
