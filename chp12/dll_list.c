#include <stdlib.h>
#include <stdio.h>

#include "dll_list.h"

#define TO_CHAR '0'-0
#define NUL '\0'
#define TRUE 1
#define FALSE 0

/**
 * create a double-list from given array
 * @param  len :points to the array
 * @return      a pointer points to the double-linked-list 
 */
Node *create_list(int *vals,int len){
	Node *list=(Node*)malloc(len*sizeof(Node)+1);
	if(list==NULL || vals==NULL) return NULL;	
	int i;
	for(i=0;i<len;i++){
		list[i].val=vals[i];
		if(i!=0) list[i].bwd=&list[i-1];
		if(i!=len-1) list[i].fwd=&list[i+1];
		else list[i].fwd=NULL;		
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
	char *str=malloc(4*size*sizeof(char)+1);
	if(list==NULL){
		str[0]=NUL;
		return str;
	}
	Node *p=list;
	char *it=str;
	int i=0;
	do{					
		it[0]=(char)(p->val+TO_CHAR);
		it[1]='<';
		it[2]='-';
		it[3]='>';
		it+=4;
		p=p->fwd;
		i++;
	}while(p!=list && p!=NULL && i<size );
	it[-3]=NUL;
	return str;
}

/**
 * remove node from a list pointed by rootp
 * @param  rootp points to the root of the list
 * @param  node  points to the node will be deleted
 * @return       true if found and deleted, false if not found node in the list 
 */
int dll_remove(Node *rootp, Node *node){
	while(rootp!=NULL){
		if(rootp->val==node->val){
			Node *ahNode=rootp->bwd;
			Node *bhNode=rootp->fwd;
			ahNode->fwd=bhNode;
			return TRUE;
		}
		rootp=rootp->fwd;		
	}
	return FALSE;
}