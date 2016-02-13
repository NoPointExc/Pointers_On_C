#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int delSubstr(char *str, char const *substr);

void main(void){
	char *str="abcdefgh";
	char const *substr="def";
	int ans=delSubstr(str,substr);
	//printf("%s   %i\n",str,ans );
}


int delSubstr(char *str, char const *substr){
	
	char *p=malloc(sizeof(char*));
	
	for(p=str;*p!='\0';p++){	
		//printf("%s\n", p);
		char const *iSub;
		char *iStr;
		for(iSub=substr,iStr=p;*iSub==*iStr && *iSub!='\0';iSub++,iStr++);
		if(*iSub=='\0'){
			//replace and return 1
			iSub=substr;
			while(*iSub!='\0' && *iStr!='\0'){
				//*p=*iStr;
				printf("%s",p);
				p++;
				iStr++;
			}
			free(p);
			return TRUE;
		}	
	}
	free(p);
	return FALSE;
}