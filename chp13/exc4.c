#include <stdio.h>

void sort(void *head[],int size, int (*comp)(char *p0, char  *p1) );
void quick_sort(void *head[], int left, int right, int (*comp)(char *p0, char *p1) );
void swap(char *p0, char *p1);
//for debug and test
int compare(char   *p0, char  *p1);
void print(char const *head[],int len);

void sort(void *head[],int size, int (*comp)(char  *p0, char  *p1) )
{
	quick_sort(head,1,size-1,comp );
}

void quick_sort(void *head[], int left, int right, int (*comp)(char  *p0, char  *p1) )
{
	//printf("L=%d R=%d ",left,right );
	int i=left+1,t=right;
	if(left>=right) return;
	swap(head[left],head[(left+right)/2]);
	while(i<=t){
		//if [i] >=[left]
		if( comp(head[i],head[left])>0 ){
			swap(head[i],head[t]);
			t--;
		}else{
			i++;
		}
	}
	swap(head[left],head[i-1]);
	quick_sort(head,left,i-1,comp);
	quick_sort(head,i,right,comp);
}


void swap(char *p0, char *p1)
{	
	if(p0==p1) return;
	*p0^=*p1;
	*p1^=*p0;
	*p0^=*p1;
}

//*****************Test******************
int main(int argc, char const *argv[])
{	
	print( (void *)argv,argc);
	sort((void *)argv,argc,compare);
	print( (void *)argv,argc);	
	return 0;
}

/**
 * if p0>p1. Only for debug and test
 * @param  p0 
 * @param  p1 
 * @return    p0>p1, return 1, else reutn0. NULL pointer, return -1
 */
int compare(char  *p0, char  *p1)
{
	if(p0==NULL || p1==NULL) return -1;
	return *p0>=*p1;
}


void print(char const *head[], int len)
{	
	int i;
	printf("\n");
	for(i=1;i<len;i++) printf("%c , ", *head[i]);
	printf("\n");
}