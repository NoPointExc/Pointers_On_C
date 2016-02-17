#include <stdio.h>

#define NUL '\0'
#define LEN  7

void my_strncat(char *dest, char *src, int dest_len);

void main(void){
	char dest[LEN]={'1','2','3','4',NUL};
	dest[5]=NUL;
	char src[]="abcefg";
	my_strncat(dest,src,LEN);
	printf("%s\n",dest);
}


void my_strncat(char *dest, char *src, int dest_len){
	int len=0;
	char *tail=dest;
	/**
	 * find the tail of des	t
	 */
	while(*tail!=NUL ){
		tail++;
		len++;
	}
	/**
	 * copt to the tail
	 */
	while(len<dest_len && *src!=NUL){
		*tail++=*src++;
		len++;
	}
	*tail=NUL;
}