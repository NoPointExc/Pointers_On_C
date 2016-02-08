#include <stdio.h>
#include <string.h>

int substr(char dst[], char src[], int start, int len);


main(void){
	char src[]="abcdefghijklmnopqrsguvwxyz1234567890+-~";
	char dst[30];
 	int i=0;

 	int rst=substr(dst,src,4,40);
 	printf("rst=%d  dst=%s\n",rst,dst);
}

int substr(char dst[], char src[], int start, int len){
	int i=-1;

	int srcLen=strlen(src);
	int dstLen=strlen(dst);
	if(start<0 || start>=srcLen || len<0) return i;	
	if(len+start<srcLen){
		for(i=start;i<len+start;i++) dst[i-start]=src[i];		
		dst[len]='\0';

	}else{
		for(i=start;i<srcLen;i++) dst[i-start]=src[i];
		dst[srcLen]='\0';
	}
	return i-start;
}