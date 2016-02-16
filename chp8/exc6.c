#include <stdio.h>
#include <stdarg.h>

#define TRUE 1
#define FALSE 0
#define ERROR -1

int array_offset (int array_offset[],...);

void main(void){
	int offset[5]={2,3,7,2,8};
	int ans=array_offset(offset,4,6);
	printf("ans=%i\n",ans );
}

int array_offset (int array_offset[],...){
	int dimension=array_offset[0];
	/**
	 * check the number of dimension
	 */
	if(dimension<=0 || dimension>10) return ERROR;
	int i=0,loc=0,pre_len=0;
	va_list va_list;
	va_start(va_list,array_offset);

	for(i=0;i<dimension;i++){
		int s=va_arg(va_list,int);
		int hi=array_offset[2*i+2];
		int li=array_offset[2*i+1];
		loc=loc*pre_len+(s- li);
		pre_len=hi-li+1;
		/**
		 * check the s in range and length>0
		 */
		if(s>hi || s<li ||pre_len<=0) return ERROR;
	}
	va_end(va_list);
	return loc;
}
