#include <stdio.h>

void main(void){
	char str[100];
	scanf("%s",str);
	
	int i;
	for(i=0;str[i]!='\0';i++){
		//printf("%c\n",str[i]);
		if(str[i]>='A'&&str[i]<='Z') str[i]+=32;
	}
	printf("%s\n",str);

}
