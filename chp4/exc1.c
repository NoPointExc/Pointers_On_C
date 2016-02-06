#include <stdio.h>

int main(void){
	double n;
	scanf("%lf",&n);
	printf("%lf\n",n );
	int i=0;
	double a=1.0;
	double next=1.0;
	for(i=0;i<100;i++){
		next=(a+n/a)/2;
		if(next==a) break;
		a=next;
		printf("i:%d  %lf\n",i,a);
	}

	return 1;
}