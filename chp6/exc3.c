#include <stdio.h>

void reverseStr(char *string);

void main(void){
	char *str="abcdefgh";
	reverseStr(str);

}


void reverseStr(char *string){
	char *head=string, *tail=string;
	while(*tail++!='\0');
	char *newHead=tail;
	while(head++!=newHead){
		*tail=(char)*head;
		tail++;		
	}	
	string=newHead;
}
