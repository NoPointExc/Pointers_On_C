 /**
*TO FIX: argument stop before -
*/
#include <stdio.h>

#define NOT_CTR 0
#define EMPTY_CTR 1
#define PLUS_CTR 2

#define NUL '\0'
#define MAX_VAL_LEN 100
char ** do_args( int argc, char  **argv, char *control, 
void (*do_arg)( int ch, char * value ),
void (*illegal_arg)( int ch ) );
int whats_ctr(char c,char *control);
char * get_value(char *this_str, char *next_str);
//test
void do_arg(int ch,char *value);
void illegal_arg(int ch);

int main(int argc, char  *argv[])
{
	
	char *control="x+y+z+abc";
	int i;
	do_args(argc,argv,control,do_arg,illegal_arg);
	return 0;
}

//argv[istr][ichar]
char ** do_args( int argc, char  **argv, char *control, 
void (*do_arg)( int ch, char * value ),
void (*illegal_arg)( int ch ) )
{
	int istr=1;
	 while(istr<argc){
		char *str=argv[istr];

		while( *str=='-'){
			int ctr_type=whats_ctr(*(str+1), control);
			if(ctr_type==NOT_CTR){
				illegal_arg( *(str+1) );
				return &argv[istr+1]; //return next str
			}else if(ctr_type==EMPTY_CTR){
				do_arg( *(str+1),NULL);
				str+=2;
			}else if(ctr_type==PLUS_CTR){
				if(*(str+2)==NUL){
					if(istr>=argc){
						illegal_arg( *(str+1) );
						return &argv[istr+1]; //return next str
					}else{
						//have a argument
						istr+=1;
						do_arg( *(str+1), argv[istr]);
						istr+=1;
						break; //go to next str
					}
				}else{
					do_arg( *(str+1), (str+2));
					str+=3;
					break;
				}
			}
		}
	 	istr+=1;
		if(str!=NUL) break; //break if not the end of string and not '-''
	 }	
	return &argv[istr+1]; //return next str
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

//test

void do_arg(int ch,char *value){
	printf("ch=%c, value=%s\n",(char)ch,value);
}

void illegal_arg(int ch){
	printf("illegal_arg =%c\n",ch );
}