#include <stdio.h>

#define true 1
#define false 0


int identify_matrix(int *matr,int size);

void main (void){
	int matr[5][5]={
		{1,0,0,0,0},
		{0,1,0,0,0},
		{0,0,1,0,0},
		{0,0,0,1,0},
		{0,0,0,0,1}
	};
	int ans=identify_matrix(*matr,5);
	printf("ans=%i\n",ans);
}

int identify_matrix(int *matr,int size){
	int i,j;
	for(i=0;i<size;i++){
		if(matr[i*size+i]!=1) return false;
		for(j=0;j<size;j++){
			if(j!=i && matr[i*size+j]!=0) return false;
		}
	}
	return true;
}