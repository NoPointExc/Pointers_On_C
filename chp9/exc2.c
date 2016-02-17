#include <stdio.h>

#define NUL '\0'

int my_strlen(char *str,int size);

void main(void){
	char str[]={'0','1','2','3','\0','5'};
	int len=my_strlen(str,5);
	printf("len=%i\n",len );
}

int my_strlen(char *str,int size){
	int len=0;
	for(;*str!=NUL&&len<size;str++) len++;
	return len;
}
