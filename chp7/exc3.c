#include <stdio.h>

#define END_STR  '\0'
#define STR_LEN  100
int asciiToInteger(char *str);

void main(void){
	char str[STR_LEN];
	scanf("%s",str);
	//printf("%s\n", str);
	int ans=asciiToInteger(str);
	printf("ans=%i\n", ans);
}


int asciiToInteger(char *str){
	int val=0;
	while(*str!=END_STR){
		int cur=*str-'0';
		if(cur<0||cur>9) return 0;
		val=val*10+cur;
		str++;
	}
	return val;
}
