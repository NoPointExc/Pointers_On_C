#include <stdio.h>

#define NUL '\0'
#define FALSE 0
#define TRUE 1

int format(char *format_string,char const *digit_string);

void main(void){
	// char format_string[]="#####.#####";
	// char digit_string[]="1";
	// int is_formated=format(format_string,digit_string);
	// printf("%s\n",format_string );

	// char format_string[]="#,###,###.##";
	// char digit_string[]="1234567";
	// int is_formated=format(format_string,digit_string);
	// printf("%s\n",format_string );
	

	// char format_string[]="#####";
	// char digit_string[]="123";
	// int is_formated=format(format_string,digit_string);
	// printf("%s\n",format_string );	

	// char format_string[]="##,###";
	// char digit_string[]="1234";
	// int is_formated=format(format_string,digit_string);
	// printf("%s\n",format_string );

	// char format_string[]="##,###";
	// char digit_string[]="1234567";
	// int is_formated=format(format_string,digit_string);
	// printf("%s\n",format_string );


	// char format_string[]="#,###,###.##";
	// char digit_string[]="123456789";
	// int is_formated=format(format_string,digit_string);
	// printf("%s\n",format_string );

	char format_string[]="#,###,###.##";
	char digit_string[]="1234567";
	int is_formated=format(format_string,digit_string);
	printf("%s\n",format_string );

}

int format(char *format_string, char const *digit_string){
	if(*digit_string==NUL) return FALSE;
	
	char *pf=format_string;
	char const *pd=digit_string;
	int has_period=FALSE;
	int period_left=FALSE;
	int has_left_zero=FALSE;

	while(*pf!=NUL) {
		if(*pf=='.') has_period=TRUE;
		pf++;
	}
	while(*pd!=NUL) pd++;


	while(pf>=format_string){
		if(*pf=='.'){
			period_left=TRUE;
			pf--;
		}else if(*pf==','){
			if(pd>=digit_string) *pf--=',';
			else *pf--=' ';//no digit without inserting		
		}else{
		/**
		 *  *pf = '#'
		 */
			if(pd>=digit_string){
			 	*pf--=*pd--;
			 	 if(period_left) has_left_zero=TRUE;
			}
			else if(period_left) {
				if(!has_left_zero){
				 *pf--='0';
				 has_left_zero=TRUE;
				}
				else *pf--=' ';
			}
			else if(has_period)*pf--='0'; //in the right of '.' 
			else *pf--=' '; //no . in the formate
		}
	}

	if(pd>=digit_string) return FALSE;
	return TRUE;
}