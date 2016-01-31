#include <stdio.h>
#include <string.h>

int main(void){
	int len=0, maxLen=-1;
	char maxStr[2000];
	char buff[2000];
	
	while((buff[len]=getchar())!=EOF){

		if(buff[len]=='\n'){
			if(len>maxLen){
				maxLen=len;
				strncpy(maxStr,buff,sizeof(buff)-1);
				//maxStr=buff;
			}	
			len=0;		
		}else len++;

	}
	printf("%d\n", maxLen);
	int i;
	//puts(&maxStr[0]);
	 printf("%s", maxStr);
	return 1;
}