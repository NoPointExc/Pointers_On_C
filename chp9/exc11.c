#include <stdio.h>
#include <string.h>



int count_the(char *str);

void main(void){
	char str[]=" The the isandthe the jksdkfthethe the";
	//char str[]="adjfksad dsjf kad fjkd jfkajf k";
	count_the(str);
	//printf("%s\n", );
}

int count_the(char *str){
	static char white_space[]={' ','\t','\f','\r','\v','\n'};
	char *the="the";
	char *token;
	int count=0;
	token = strtok(str, white_space);
	/**
	 * walk through the string
	 */
	while( token!=NULL ) 
	{
	  printf( " %s\n", token );
	  token = strtok(NULL, white_space);
	  if(token!=NULL&&strcmp(token,the)==0) count++;
	}
	printf("the count=%i\n",count);
	return count;
}