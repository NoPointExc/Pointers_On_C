#include <stdio.h>

int main(void){
	int line=1;
    char in=getchar();
    while(in!=EOF||in!='.'){
    	printf("%d",line);
    	while(in!='\n' || in!=EOF ||in!='.'){
    		printf("%c",in );
    		in=getchar();
    	}
    	if(in=='\n') printf("%c",in);
    	in=getchar();
    }
	return 0;
}