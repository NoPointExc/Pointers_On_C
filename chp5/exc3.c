#include <stdio.h> 

unsigned int reverse_bits(unsigned int value);

void main(void){
	unsigned int val;
	scanf("%d",&val);
	unsigned int ans=reverse_bits(val);
	printf("%d\n", ans);
}

unsigned int reverse_bits(unsigned int value){	
	unsigned int revVal=0;
	while(value!=0){		
		revVal=revVal*2+value%2;
		value/=2;
	}
	return revVal;
}