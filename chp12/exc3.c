/**
 * No much difference from program 12.7, expect corner case in head and tail
 * TODO: not tested
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#include "dll_list.h"

int dll_insert(Node *head, Node *tail, int val);

void main(void){

}

int dll_insert(Node *head, Node *tail, int val){
	Node *this;
	Node *next;
	Node *new_node;

	/**
	*  val should insert in unknown position before head
	*  return false
	*/
	if(head!=NULL && val < head->val)  return -2; 
	/**
	 * val is same as head.val
	 * return 0
	 */
	if(head!=NULL && val == head->val)  return 0;    

	for(this=head;(next = this->fwd)!=tail;this=next){
		if(next->val == val) return 0;  //already have this val
		if(next->val > val) break;
	}

	 
	 if(next==tail && next->val < val) return -2;
	 else if(next==tail && next->val == val) return 0;
	 else{
	 	new_node=(Node *)malloc(sizeof(Node));
	 	/**
	 	 * can not malloc memory
	 	 * return false
	 	 */
		if(new_node==NULL) return -1; 
		new_node->bwd=this;
	 	new_node->fwd=next;
	 }

	 return 1;
}


