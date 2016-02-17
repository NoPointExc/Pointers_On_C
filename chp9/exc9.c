#include <stdio.h>
#include <string.h>
#include <stddef.h>

int count_chars(char const *str, char const *chars);
void main(void){
	char str[]="abde12sadfa213123";
	char chars[]="1234";
	int rst=count_chars(str,chars);
	printf("rst=%i\n", rst);
}

int count_chars(char const *str, char const *chars){
	int count=0;
	while((str=strpbrk(str,chars))!=NULL){		
		//printf("%s\n",str );
		str++;
		count++;
	}
	return count;
}
