#include <stdio.h>

main(void){
	char in[]="abcdefghijklmnopqrsguvwxyz1234567890";
	char *p=in;
	char arr[100];
	
	int i=0;
	for(i=0;i<40;i++) {
		arr[i]=(char)('0'+i);
		printf("%c ,", (char)('0'+i));
	}
	int size=sizeof(in);
	printf("\n size=%d\n",size);
	printf("%s\n",arr );
	//printf("%s\n", p);
}