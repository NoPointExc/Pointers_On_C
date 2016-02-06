#include <stdio.h>
int main(void){
	
	int a,b,c;
	
	scanf("%d %d %d",&a,&b,&c);
	if((a+b)<=c || (c+b)<=a || (c+a)<=b || a<=0 ||b<=0 ||c<=0 ) {
		printf("%s\n","invalid input" );
		return 0;
	}
	if(a==b && b==c) printf("%s\n", "it is a equilateral triangles." );
	else if(a==b|| b==c || c==a) printf("%s\n", "isosceles triangle" );
	else printf("%s\n","scalene");


	return 1;
}