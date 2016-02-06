#include <stdio.h>
#include <stddef.h>
void copy_n(char dst[],char src[],int n);
int main(void){
	char dst[100],src[100];
	int n;
	scanf("%s",&src);
	scanf("%d",&n);
	copy_n(dst,src,n);
	printf("%s\n", dst);
	return 1;
}

void copy_n(char dst[], char src[], int n){
	int i;
	int len=sizeof(src);
	if(len<n){
		for(i=0;i<len;i++){
			dst[i]=src[i];
		}
		for(i=len;i<n;i++) dst[i]='\0';
	}else{
		for(i=0;i<n;i++) dst[i]=src[i];
	}
}