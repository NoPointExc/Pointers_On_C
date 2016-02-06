#include<stdio.h>

int main(void){
	enum coin {penny, nickel, dime,quarter,dollar}; 
	/*
	use int to represent enum, defatult value is 0,1,2,3..
	also, u can specify the value of each enum, e.g.
	enum coni {penny=1,nickel=3};
	 */
	}

	enum coin one,two,three;
	one =penny;
	two=dime;
	three=dollar;
	printf("one=%s two=%s  three=%s\n",one,two,three);
	return 1;
}