#include <stdio.h>

void reverseStr(char *string);

void main(void){
	char str[]="abcdefgh";
	reverseStr(str);
	printf("%s\n",str);
}


void reverseStr(char *str){
	char *head=str,*tail=str;
	while(*(tail+1)!='\0') tail++;
	while(head<tail){
		*tail^=*head;
		*head^=*tail;
		*tail^=*head;
		head++;
		tail--;
	}
}
