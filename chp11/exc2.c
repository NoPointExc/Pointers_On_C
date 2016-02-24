#include <stdio.h>
#include <stdlib.h>

int* get_array(void);

void main(void){
	int *arr;
	arr=get_array();
	int i;
	for(i=0;i<5;i++,arr++) printf("%d\n",*arr );
}

int* get_array(void){
	int * arr=NULL;
	int * tmp_arr=NULL;
	int next_int,n=0;
	scanf("%d",&next_int);
	while(next_int!=EOF){
		n++;
		tmp_arr=(int *) realloc(arr,n*sizeof(int));
		/**
		 * No enough space, return null
		 */
		if(tmp_arr==NULL) {
			free(arr);
			return NULL;
		}
		arr=tmp_arr;
		arr[n-1]=next_int;
		scanf("%d",&next_int);		
	}
	return arr;
}