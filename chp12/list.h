typedef struct NODE{
	struct NODE *next;
	int val;	
} Node;



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

