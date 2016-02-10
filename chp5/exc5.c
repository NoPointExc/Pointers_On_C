#include <stdio.h>

unsigned  getMask(unsigned  start,unsigned  end);

void main(void){
	unsigned start,end;
	scanf("%d   %d",&start,&end);
	//printf("%d  %d\n", start,end);
	unsigned ans;
	ans=getMask(start,end);
	printf("%d\n",ans);
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