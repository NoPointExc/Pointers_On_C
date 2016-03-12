#include <stdio.h>

void sort(void *head[],int size, int (*comp)(char *p0, char  *p1) );
void quick_sort(void *head[], int left, int right, int (*comp)(char *p0, char *p1) );
void swap(char *p0, char *p1);
//for debug and test
int compare(char  *p0, char  *p1);
void print(char const *head[],int len);

int main(int argc, char const *argv[])
{	
	//printf("a");
	//print( argv,argc);
	printf("%d\n", argv);
	sort((void *)argv,argc-1,compare);
	printf("%d\n", argv);
	return 0;
}

void sort(void *head[],int size, int (*comp)(char *p0, char  *p1) ){
	quick_sort(head,0,size,comp );
}

void quick_sort(void *head[], int left, int right, int (*comp)(char *p0, char *p1) ){
	int i=left+1,t=right;
	if(left >=right) return;

	while(i<=t){
		//if [i] > [left]
		if( comp(head[i],head[left])>0 ){
			swap(head[i],head[t]);
			t--;
		}else{
			i++;
		}
	}	

	quick_sort(head,left,i-1,comp);
	quick_sort(head,i,right,comp);
}


void swap(char *p0, char *p1)
{
	*p0^=*p1;
	*p1^=*p0;
	*p0^=*p1;
}

/**
 * if p0>p1
 * @param  p0 
 * @param  p1 
 * @return    p0>p1, return 1, else reutn0. NULL pointer, return -1
 */
int compare(char *p0, char *p1)
{
	if(p0==NULL || p1==NULL) return -1;
	return *p0>*p1;
}


void print(char const *head[], int len)
{
	int i;
	for(i=1;i<len;i++) printf("%c , ", *head[i]);
	printf("\n");
}