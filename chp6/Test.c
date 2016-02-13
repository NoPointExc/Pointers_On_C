#include <stdio.h>
#include <stdlib.h>

void main(void){
	char *a="abcd";
	char *b="1234";
	char *c=(char *)malloc(sizeof(char));
	char *d;
	*a=*b; //segmentation fault
	*c=*b; //ok
	*d=*b;
}