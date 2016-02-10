#include <stdio.h>

void main(void){
	char str[100];
	int i=0;
	scanf("%s",str);
	for(i=0;str[i]!='\0';i++){
		if(str[i]>='A' && str[i]<'N') str[i]+=13;
		else if(str[i]<='Z' && str[i]>='N') str[i]-=13;
		else if(str[i]>='a' && str[i]<'n') str[i]+=13;
		else if(str[i]<='z' && str[i]>='n') str[i]-=13;
	}
	printf("%s\n",str );
}