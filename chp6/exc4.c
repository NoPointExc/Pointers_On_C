#include <stdio.h>

#define true  1
#define false 0
#define RANGE 10000

void main(void){
	unsigned short num[RANGE];
	unsigned char isPrime[RANGE];
	short i,j;
	for(i=0;i<RANGE;i++){
		num[i]=2*i+1;
		isPrime[i]=true;
	}
	num[0]=2;
	for(i=1;i<RANGE;i++){
		if(!isPrime[i]) continue;
		for(j=i+num[i];j<RANGE;j+=num[i]) isPrime[j]=false;
	}

	//print all the prime number	
	for(i=0;i<RANGE;i++){
		if(isPrime[i])printf("%i ,", num[i]);
	}

}