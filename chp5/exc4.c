#include <stdio.h>

void setBit(char bitArray[],unsigned bitNumber);
void clearBit(char bitArray[],unsigned bitNumber);
void assignBit(char bitArray[],unsigned bitNumber,int value);
int testBit (char bitArray[], unsigned bitNumber);


void main(void){
	char bitArray[100];
	unsigned int bitNumber;
	scanf("%s   %d",bitArray,&bitNumber);
	printf("input=%s\n",bitArray );
	setBit(bitArray,bitNumber);
	printf("input=%s\n",bitArray );
	
}

void setBit(char bitArray[],unsigned bitNumber){
	bitArray[bitNumber]='1';
}
void clearBit(char bitArray[],unsigned bitNumber){
	bitArray[bitNumber]='0';
}
void assignBit(char bitArray[],unsigned bitNumber,int value){
	bitArray[bitNumber]=value==0?'0':'1';
}
int testBit (char bitArray[], unsigned bitNumber){
	return bitArray[bitNumber]!=0;
}

