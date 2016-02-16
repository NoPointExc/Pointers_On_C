#include <stdio.h>

#define FALSE 0
#define TRUE 1

static int id=1;
void eight_queens(int *map,int num);
int is_valid(int *map,int x,int y);
void print_map(int *map);

void main(void){
	int map[8][8]={0};
	//print_map(*map);
	eight_queens(*map,0);
}

void eight_queens(int *map,int num){

	/**
	 * if finished, print and return
	 */
	if(num==8){
		print_map(map);
		return;
	}
	/**
	 * check every posibble position in this line
	 */
	int n;
	for(n=0;n<8;n++){
		if(is_valid(map,n,num)){
			map[n+num*8]=TRUE;
			eight_queens(map,num+1);
			map[n+num*8]=FALSE;
		}
	}		
}

int is_valid(int *map,int x,int y){
	int i; 
	for(i=0;i<8;i++){
		/**
		 * check diagonal line
		 */
		if(x-i>=0 && y-i>=0 && map[x-i+(y-i)*8]) return FALSE;
		if(x-i>=0 && y+i<8 && map[x-i+(y+i)*8]) return FALSE;
		if(x+i<8 && y-i>=0 && map[x+i+(y-i)*8]) return FALSE;
		if(x+i<8 && y+i<8 && map[x+i+(y+i)*8]) return FALSE;
		/**
		 * check row
		 */
		if(map[i+y*8]==1) return FALSE;
		/**
		 * check column
		 */
		if(map[i*8+x]==1) return FALSE;
	}
	return TRUE;
}

void print_map(int *map){
	int i,j;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			printf(" %i ",map[i*8+j]);
		}
		printf("\n");
	}
	printf(" --------- %i ---------\n",id++);
}