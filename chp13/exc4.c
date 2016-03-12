#include <stdio.h>

int compare(void const *p0, void const *p1);
void sort(void *head[], int len, int size, int (*comp)(void const*p0, void const *p1) );
void _sort(void *head[], int left, int right, int (*comp)(void const*p0, void const *p1) );
void swap(void *p0, void *p1);
void print(void const *head[],int len);

/*
* the value of argc(memory-address) is not continue, so never use argv or pass *argv instand of argv
**/
int main(int argc, char const *argv[])
{	
	int i;
	print( (void *)argv,argc);
	swap((void *)argv[2],(void *)argv[3]);
	print( (void *)argv,argc);
	return 0;
}

//quick sort
void sort(void *head[], int len, int size, int (*comp)(void const*p0, void const *p1))
{

}

void _sort(void *head[], int left, int right, int (*comp)(void const*p0, void const *p1) ){
	if(left >=right) return;
}


int compare(void const *p0, void const *p1)
{
	if(p0==NULL || p1==NULL) return -1;
	int val0= *((int *)p0);
	int val1= *((int *)p1);
	return val0>val1;
}

void swap(void *p0, void *p1)
{
	//printf("%d\n",(int)*p0);
}

void print(void const *head[], int const len)
{
	int i;
	for(i=1;i<len;i++) printf("%d , ", ((char *)head)[i]);
	printf("\n");
}