#include <stdio.h>
int func(void);

void main(void){
	char i;
	for(i='A';i<='Z';i++) printf("%d  %c\n",i-'A',i);

}

int func(void){
	static int c=1;
	return ++c;
}

