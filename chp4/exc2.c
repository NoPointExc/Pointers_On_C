#include <stdio.h>

int main(void){
	int i,j;
	for(i=1;i<100;i+=2){
		int remind=1;
		for(j=3;j<i && remind!=0;j+=2){
			remind=i%j;
		}
		if(remind!=0) printf("%d\n",i);
	}
	return 1;
}