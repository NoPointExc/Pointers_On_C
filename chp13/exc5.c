#include <stdio.h>

#define NOT_CTR 0;
#define EMPTY_CTR 1;
#define PLUS_CTR 2;

#define NUL '\0'

char ** do_args( int argc, char **argv, char *control, 
void (*do_arg)( int ch, char * value ),
void (*illegal_arg)( int ch ) );
int whats_ctr(char c,char *control);


int main(int argc, char const *argv[])
{
	char arg[6]={'1','2','a','b','c','f'};
	char *ctr="abc+def+";
	int i;
	for(i=0;i<6;i++){
		int rst= whats_ctr(arg[i],ctr);
		printf("%d\n",rst);
	}
	return 0;
}

//argv[istr][ichar]

char ** do_args( int argc, char **argv, char *control, 
void (*do_arg)( int ch, char * value ),
void (*illegal_arg)( int ch ) )
{
	int istr=1;

	while(istr<argc){
		char *str=argv[istr];
		while(*str!=NUL){
			if(**str=='-'){
				switch( whats_ctr(*(str+1)) ){
					case NOT_CTR: 
						illegal_arg( *(str+1) );
						return argv[istr+1]; //return next str
					case EMPTY_CTR:
						do_arg( *(str+1),NULL);
						break;
					case PLUS_CTR:
						if(*(str+2)==NUL){
							if(istr>=argc){
								illegal_arg( *(str+1) );
								return argv[istr+1]; //return next str
							}else{
								istr+=1;
								do_arg( *(str+1), argv[istr]);
								//!!need to jump to out loop
							}
						}else{
							do_arg( *(str+1), *(str+2));
							//!!need to jump to out loop
						}
					break;
				}
			}
			str+=1;
		}
	}
		
	return argv[istr+1]; //return next str
}

/**
 * detect the type of argument
 * @param  c       argument
 * @param  control control argument list
 * @return         argument type, PLUS_CTR,EMPTY_CTR or NOT_CTR 
 */
int whats_ctr(char c,char *control)
{
	while(*control!=NUL){
		if(*control==c){
			if(*(control+1)=='+') return PLUS_CTR;
			return EMPTY_CTR;
		}
		control+=1;
	}
	return NOT_CTR;
}
