#include <stdio.h>
	
 static int val0=0;
 int val2=2;
 void method0(void);
 extern void method2(void);
 /*
 an extern static method can be declear, but cann't be use.
  */
 extern void method3(void);
int main(void){
	static int val1=1;
	int i=0;


	for(i=0;i<5;i++){
	 method0();
	 method1();
	}

	printf("main:val2=%d\n", val2);
	/*
	a=1 always
	b=1,2,3,4,5
	 */
	method2();
	//method3(); method3 is defined as static in method1.c
	return 1;
}

void method0(void){
	int a=0;
	static int b=0;
	a+=1;
	b+=1;
	printf("a=%d b=%d\n",a,b );


}

/*
for function and global value, static make them be "privacy".
for val inside the funcions, static make a value "static".
 */