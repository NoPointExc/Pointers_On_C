#include <stdio.h>

#define true 1
#define false 0

void main(void){
	printf("%s\n","hello" );
}

int identify_matrix(int matr[10][10]){
	int i,j;
	for(i=0;i<10;i++){
	 if(matr[i][i]!=1) return false;
	 for(j=0;j<10;j++){
	 	if(j!=i && matr[i][j]!=0) return false;
	 }
	}
	return true;
}