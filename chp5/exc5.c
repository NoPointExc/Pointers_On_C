#include <stdio.h>

unsigned  getMask(unsigned  start,unsigned  end);
int storeBitField(int originalVal, int valToStore, unsigned startBit, unsigned endBit);

void main(void){
	unsigned start,end;
	scanf("%d   %d",&start,&end);
	//printf("%d  %d\n", start,end);
	unsigned ans;
	ans=getMask(start,end);
	printf("%d\n",ans);
}

int storeBitField(int originalVal, int valToStore, unsigned startBit, unsigned endBit){
	//1.get mask
	unsigned mask=getMask(startBit,endBit);
	//2.originalVal AND mask
	int rst;
	rst=originalVal&mask;	 
	int i;
	//3. move
	for(i=0;i<endBit;i++) valToStore<<=1;
	//4.
	valToStore&=mask;
	//5. OR
	rst|=valToStore;	
	return rst;
}


unsigned getMask(unsigned start,unsigned end){
	int i;
	unsigned mask=0;
	if(start>end) return -1;
	if(start==0 && start==end) return 1;
	for(i=0;i<end;i++){
		if(i<=(end-start)) mask++;
		mask<<=1;
	}
	return mask;
}