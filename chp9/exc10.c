#include <stdio.h>
#include <string.h>

#define NUL '\0'
#define DIFF 'a'-'A'
#define TRUE 1
#define FALSE 0

int palindrome(char *string);

void main(void){
	char str[]="eabcd0cba";
	int rst=palindrome(str);
	printf("%i\n",rst);
}

int palindrome(char *string){
	char *tail=string;
	while(*tail!=NUL) tail++;
	while(string<tail){
		char h=0,t=0;
		while(string<tail &&!isalpha(*string)) string++;
		if(string>=tail) return TRUE;
		h=tolower(*string);
		while(string<tail && !isalpha(*tail)) tail--;
		if(string>=tail) return TRUE;
		t=tolower(*tail);
		if(h!=t) return FALSE;
		string++;
		tail--;
	}
	return TRUE;
}