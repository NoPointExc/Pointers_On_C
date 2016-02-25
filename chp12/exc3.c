/**
 * No much difference from program 12.7, expect corner case in head and tail
 * this program have not been tested
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
	* return error, val should not in this range
	*/
	if(head!=NULL && val < head->val)  return -2;   
	if(head!=NULL && val == head->val)  return 0; //repeat with head->val   

	for(this=head;(next = this->fwd)!=tail;this=next){
		if(next->val == val) return 0;  //already have this val
		if(next->val > val) break;
	}

	 
	 if(next==tail && next->val < val) return -2;
	 else if(next==tail && next->val == val) return 0;
	 else{
	 	new_node=(Node *)malloc(sizeof(Node));
		if(new_node==NULL) return -1; //Error: can not malloc memory
		new_node->bwd=this;
	 	new_node->fwd=next;
	 }

	 return 1;
}


