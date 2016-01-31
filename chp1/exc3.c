# include <stdio.h>

int main(void){
	int sum=0;
	signed char str[200];
	signed char in=getchar();
	int len=0;
	while((in=getchar())!=EOF){
		str[len]=in;
		len++;
	}

	int i;
	for(i=0;i<len  ;i++){
		if(str[i]!='\n') sum+=str[i];
		else {
			printf("%d\n",sum );
			sum=0;		
		}
	}
	
	return 1;
}