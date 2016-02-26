#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void main(void){
	printf("%d\n", sizeof(Node));
	Node first,sec,thr;
	first.val=1;
	sec.val=2;
	thr.val=3;
	first.next=&sec;
	sec.next=&thr;
	thr.next=NULL;
	printf("%d\n",sizeof(first) );
}