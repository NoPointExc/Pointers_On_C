#include <stdio.h>


void deblank(char string[]);
int isBlank(char cur);
void main(void){
	char string[]=" 123456        78 9  0123   45 ";
	deblank(string);
	puts(string);
}


void deblank(char *string){
	char *h, *t;
	h=string;
	t=string++;
	while(*h++!='\0'){
		if( !isBlank(*h) || string==h|| !isBlank(t[-1]) ) *t++=*h;
	}
}

int isBlank(char cur){
	return cur==' ';
}