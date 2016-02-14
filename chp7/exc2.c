#include <stdio.h>

int gcd( int m, int n);

void main(void){
	int m,n,ans;
	scanf("%i %i",&m,&n);
	ans=gcd(m,n);
	printf("ans=%i\n",ans );
}


int gcd( int m, int n){
	printf("m=%i  n=%i\n", m,n);
	int r;
	if(m<=0||n<=0) return 0;
	if(m<n){
		m^=n;
		n^=m;
		m^=n;
	}
	//m>=n
	r=m%n;
	if(r==0) return n;
	else return gcd(n,r);
}
