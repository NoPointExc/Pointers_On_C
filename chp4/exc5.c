#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 129
#define FALSE  0
#define TRUE   1

 main(void){
	int printed=FALSE;
	char cur[MAX_LINE];
	char pre[MAX_LINE];
	while(gets(cur)!=NULL){
		//printf("in: %s\n", cur );
		if(strcmp(pre,cur)!=0){
			printed=FALSE;
			strcpy(pre,cur);	
		}else if(!printed){
			printf("%s\n", cur);
			printed=TRUE;
		}		
	}
}