#include <stdio.h>
extern int val2;
extern int val0;//no warnning.
void method1(void){
	val2++;
	//val0++;   //return undefine reference, as val0 is "static" in main.c
	printf("val2=%d\n",val2 );
}

 void method2(void){
	printf("%s\n", "method2");
}

static void method3(void){
	printf("%s\n", "method3");
}