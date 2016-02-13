#include <stdio.h>
//#define NULL 0
char const *find_char (char const *source, char const *chars);

void main(void){
	char str[]="abcdef";
	
	char *source=str;
	printf("%s\n",source);
	char c='c';
	char *chars=&c;
	//printf("%s\n", source);
	char const *ans=find_char(source,chars);
	
	printf("%s\n",ans);
}
//char const *, a pointer to an const char
char const *find_char (char const *source, char const *chars){

	if(chars==NULL || source==NULL) return NULL;
	
	for(;*source!='\0';source++){
		if(*source==*chars) return source;
	}
	return NULL;
}

