#include <stdio.h>
#include <ctype.h>

#define NUL '\0'

void str_statistic(char *str);

void main(void){
	char buffer[100]="dsaf KJe &(*7 121Jd ";
	//scanf("%s",buffer);
	str_statistic(buffer);
}

void str_statistic(char *str){
	float ctr=0,spc=0,digit=0,lower=0,upper=0,punctuation=0, non_printable=0,sum=0;
	for(;*str!=NUL;str++){
		if(iscntrl(*str)) ctr++;
		else if(isspace(*str)) spc++;
		else if(isdigit(*str)) digit++;
		else if(islower(*str)) lower++;
		else if(isupper(*str)) upper++;
		else if(ispunct(*str)) punctuation++;
		else if(!isprint(*str)) non_printable++;		
		sum++;
	}
	/**
	 * print statistic result
	 */
	printf("control character:%.2f\n",ctr/sum);
	printf("space:%.2f\n",spc/sum);
	printf("digit:%.2f\n",digit/sum);
	printf("lower character:%.2f\n",lower/sum);
	printf("upper character:%.2f\n",upper/sum);
	printf("punctuation character:%.2f\n",punctuation/sum);
	printf("non-printable character:%.2f\n",non_printable/sum);	
	printf("sum: %i\n", (int)sum);
}
