#include <stdio.h>
#include <stdlib.h>

void main(void){
	char *a="abcdefgh";
	char *b="1234";
	char *c=(char *)malloc(sizeof(char));
	//printf("%i\n", sizeof(a));
	printf("%s\n", c);
	printf("%i\n", c);
	*c=*a;
	*c=*b;
	printf("%s\n", c);
	printf("%i\n", c);
}