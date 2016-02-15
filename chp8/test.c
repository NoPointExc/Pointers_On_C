#include <stdio.h>

int get(int *matr, int x, int y){
	int i=0;
	for(i=0;i<25;i++) printf("%i ", *(matr+i));
	return matr[1];
}

void main(void){
	int matr[5][5]={
		{1,0,0,0,0},
		{0,1,0,0,0},
		{0,0,1,0,0},
		{0,0,0,1,0},
		{0,0,0,0,1}
	};
	int ans=get(*matr,0,0);
	printf("%i\n",ans);
}