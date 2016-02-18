#include <stdio.h>
#include <string.h>


#define NUL '\0'

void dollars(char *dest, char const *src);

void main(void){
	char dest[100],src[100];
	scanf("%s",src);
	//*src=NUL;
	printf("%s\n",src );
	dollars(dest,src);
	printf("%s\n",dest);
}

void dollars(char *dest, char const *src){
	int len=(int)strlen(src);	
	*dest++='$';
	/**
	 * appends enough bits
	 */
	if(len<3) {*dest++='0';*dest++='.';}
	if(len<2) *dest++='0';
	if(len<1) *dest++='0';
	/**
	 * travel through the src
	 */
	int i;
	for(i=0;*src!=NUL;i++){
		*dest++=*src++;
		if(i!=0&&len-i-2>1&&(len-i-2)%3==1) *dest++=',';
		if(len-i==3) *dest++='.';		
	}
	*dest=NUL;

}