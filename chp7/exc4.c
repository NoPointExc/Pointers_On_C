#include <stdio.h>
#include <stdarg.h>

int maxList(int num, ...);
void main(void){
	int ans=maxList(4,1,2,3,-1);
	printf("ans=%d\n",ans );
}

int maxList(int num, ...){
	va_list vars;
	int i;
	int max=0;
	va_start(vars,num);
	for(i=0;i<num;i++){
		int val=va_arg(vars,int);
		//printf("%i\n",max );
		if(i==0) max=val;
		else max=max>val?max:val;		
	}
	va_end(vars);
	//printf("%i\n",max );
	return max;
}


