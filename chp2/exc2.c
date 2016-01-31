#include <stdio.h>

int main(void){
	int left=0;
	char cur;
	while((cur=getchar())!=EOF){
		if(cur=='(') left++;
		else if(cur==')') left--;
		if(left<0) {
			printf("%s\n","wrong" );
			return 0;
		}
	}
	if(left==0) printf("%s\n", "correct");
	return left==0;	
}