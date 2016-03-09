#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define CASE_N 7

int non_prtable(int c);

int main( int argc, char const *argv[] )
{	
	if( argc==0 ) return 1;
	int rst[CASE_N]={0};
	int (*check_funs[CASE_N])(int)={&iscntrl,&isspace,&isdigit,&islower,&isupper,&ispunct,&non_prtable};
	int i;
	for(i=1;i<argc;i++){
		int j;
		int arg_i=(int)*argv[i];
		for(j=0;j<CASE_N;j++){
			if( ( check_funs[j])(arg_i)!=0 ) {
				rst[j]+=1;
				break;
			}			
		}
	}
	printf("  cntrl  space  digit  lower upper punct non_prtable\n");
	for( i=0; i<CASE_N; i++ ){
		printf("|  %d  |",rst[i]);
	}
	return 1;
}


int non_prtable(int c){
	return isprint(c)==0;
}