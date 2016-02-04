#include<stdio.h>

int main(void)
{
	long int big=65560;
	short int small=1;
	printf("big= %d\n",big);
	printf("small=%d\n", small);
	small^=big;
	big^=small;
	small^=big;
	
	printf("big=%d\n",big );
	printf("small=%d\n",small ); //overflow here
	return 1;
}