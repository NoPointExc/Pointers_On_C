#include <stdio.h>
#include <stdarg.h>

#define MAX_SIZE 100;

void print(char *formate, ...);

void main(void){

}

void print(char *formate, ...){
	va_start vaList;
	va_start(vaList,formate);
	char buff[MAX_SIZE];
	char *pf;
	unsigned int i=0;
	for(pf=formate;*pf!='\0';pf++){
		if(*pf!='%'){
			if(i<MAX_SIZE) buff[i++]=*pf;
			else{
				printf("%s\n","string too long" );
				return;
			}
		}else{
			char next=*(pf+1);
			if(next=='d'){
				int next_dec=va_arg(vaList,int);
				char tmp[MAX_SIZE];
				itoa(next_dec,tmp,10);
			}else if(next=='f'){
				float next_flo=va_arg(vaList,float);
			}else if(next=='s'){
				char * next_str=va_arg(vaList,*char);
			}else if(next=='c'){
				char next_char=va_arg(vaList,char);
			}else{
				if(i<MAX_SIZE) buff[i++]=*pf;
				else{
					printf("%s\n","string too long" );
					return;
				}
			}
		}
	}
	printf("%s\n",buff);	
}

