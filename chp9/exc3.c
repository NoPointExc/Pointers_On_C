#include <stdio.h>

#define NUL '\0'
char *my_strcpy(char *dest, const char *src);

void main(void){
	char dest[]="ijkelm";
	char src[]="12345678";
	char *rst=my_strcpy(dest,src);
	printf("%s\n",rst);
	printf("%s\n", dest);
}

char *my_strcpy(char *dest, const char *src){	
	char *head=dest;
	while(*dest!=NUL && *src!=NUL) *dest++=*src++;
	if(*src==NUL && *dest!=NUL) *dest=NUL; 
	return head;
}