#include <stdio.h>

int compare(void const *p0, void const *p1);
void sort(void *head, int len, int size, int (*comp)(void const*p0, void const *p1));
void print(char const *head,int len);

int main(int argc, char const *argv[])
{	
	int i;
	for(i=0;i<argc;i++) printf("%c\n",*argv[i]);
	print(*argv[0],argc);
	return 0;
}

//quick sort
void sort(void *head, int len, int size, int (*comp)(void const*p0, void const *p1))
{
	if(len==0|| len==1) return;
	int mid=len/2;
	sort(head,mid,size,comp);
	sort(head+mid*size,len-mid,size,comp);
}

int compare(void const *p0, void const *p1)
{
	if(p0==NULL || p1==NULL) return -1;
	int val0= *((int *)p0);
	int val1= *((int *)p1);
	return val0>val1;
}

void print(char const *head, int len){
	int i;
	for(i=0;i<len;i++) printf("%c, ",head[i]);
	printf("\n");
}