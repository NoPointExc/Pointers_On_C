#include <stdio.h>
#include <stdlib.h>

#define NUL '\0'

char* read_line(void);

void main(void){
	char *str;
	str=read_line();
	printf("%s\n",str );
}

char* read_line(void){
	char buff;
	char *str=(char*)malloc(sizeof(char));
	char *str_tmp;
	int len=0;

	while((buff=getchar())!=NUL){
		printf("%s\n", &buff);
		len++;
		str_tmp=(char*) realloc(str,(len+1)*sizeof(char));
		/**
		 * if no enough memory, return null
		 */
		if(str_tmp==NULL){
			free(str);
			return NULL;
		}
		str=str_tmp;
		str[len-1]=buff;
	}
	str[len]=NUL;
	return str;
}