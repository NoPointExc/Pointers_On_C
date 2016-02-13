#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int delSubstr(char *str, char const *substr);

void main(void){
	char str[]="abcdefgh";
	char const *substr="def";
	int ans=delSubstr(str,substr);
	printf("%s   %i\n",str,ans );
}


int delSubstr(char *str, char const *substr){	
	char *p,*iStr;
	char const *iSub;
	
	for(p=str;*p!='\0';p++){	
		//printf("%s\n", p);
	
		for(iSub=substr,iStr=p;*iSub==*iStr && *iSub!='\0';iSub++,iStr++);
		if(*iSub=='\0'){
			//replace and return 1
			iSub=substr;
			while(*iSub!='\0' && *iStr!='\0'){
				*p=*iStr;
				//printf("%i",sizeof(p));
				p++;
				iStr++;
			}
			*p='\0';
			return TRUE;
		}	
	}
	return FALSE;
}