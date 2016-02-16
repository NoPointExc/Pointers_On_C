#include <stdio.h>

void matrix_multiply(int *m1, int *m2,int *r, int x, int y, int z);

void main(void){
	int x=3, y=2, z=4;
	int m1[3][2]={
		{2,-6},
		{3,5},
		{1,-1}
	};
	int m2[2][4]={
		{4,-2,-4,-5},
		{-7,-3,6,7}
	};
	int r[3][4];
	matrix_multiply(*m1,*m2,*r,x,y,z);
	int i,j;
	printf("rst= \n" );
	for(i=0;i<x;i++){
		for(j=0;j<z;j++){
			//printf("%i ",*(r+i*z+j) );
			printf("%i ",r[i][j]);
		}
		printf("\n");
	}
}


void matrix_multiply(int *m1, int *m2,int *r, int x, int y, int z){	
	int i,j;
	int k;
	for(i=0;i<x;i++){
		for(j=0;j<z;j++){
			//int sum=0;
			*(r+i*z+j)=0;
			for(k=0;k<y;k++){
			 *(r+i*z+j)+=m1[i*y+k]* m2[k*z+j];
			}
		}
	}		
}