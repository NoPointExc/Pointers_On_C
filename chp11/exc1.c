#include <stdio.h>
#include <stdlib.h>
void * my_calloc(size_t num, size_t size);

void main(void){
	int *p=(int*)my_calloc(5,sizeof(int));
	int i;
	for(i=0;i<5;i++,p++) *p=i;
	for(i=0;i<5;i++,p--) printf("%i\n",*p );
		
	
}

void * my_calloc(size_t num, size_t size){
	void *p=malloc(size*num);
	return p;
}