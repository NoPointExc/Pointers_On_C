#include <stdio.h>
#include <string.h>

#define NUL '\0'

char *edit(char *pattern, char const *digits);

void main(void){
	char pattern[]="$#,##!.##";
	char digits[]="0    6";
	char *edited=edit(pattern,digits);
	printf("%s\n",edited );
}


char *edit(char *pattern, char const *digits){
	
	char *signif=NULL;
	if(pattern==NULL || digits==NULL) return signif;
	char fill_char=*pattern;

	while(*++pattern!=NUL){
		switch(*pattern){
			case NUL: return pattern;				
			case '#': 
				if(*digits==NUL) return signif;
				else if(*digits==' ') {
					digits++;
					*pattern=fill_char;
				}
				else{
					*pattern=*digits++;
					if(signif==NULL) signif=pattern;
				}
				break;
			case '!':
				if(*digits==NUL) return signif;
				else if(*digits==' ') {
					digits++;
					*pattern=fill_char;
				}else{
					*pattern=*digits++;
					if(signif==NULL) signif=pattern;
				}
				break;			
			default: *pattern=fill_char;
		}
		
	}
	return signif;
}