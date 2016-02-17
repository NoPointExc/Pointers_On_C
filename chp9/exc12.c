#include <stdio.h>
#include <string.h>

#define NUL '\0'
#define TRUE 1
#define FALSE 0

int prepare_key(char *key);

void main(void){
	char key[26]="ilovexingxing";
	int rst=prepare_key(key);
	printf("rst=%i, key=%s\n",rst,key );
}

int prepare_key(char *key){
	static char alp_table[]="abcdefghijklmnopqrstuvwxyz";
	char buff[26]={0};	
	
	if(key==NULL) return FALSE;
	strcpy(buff,key);
	/**
	 * walk through key
	 */
	int cur=0;
	int i=0;
	while(buff[i]!=NUL){
		if(!isalpha(buff[i])) return FALSE;
		char c=tolower(buff[i]);
		int pos=c-'a';
		if(alp_table[pos]!='*'){
			alp_table[pos]='*';
			key[cur++]=c; //
		} 
		i++;
	}
	
	for(i=0;i<26;i++){
		if(alp_table[i]!='*') key[cur++]=alp_table[i]; //
	}
	key[i]=NUL;
	return TRUE;
}

