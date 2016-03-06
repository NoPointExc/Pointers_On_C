#include <stdio.h>
#include "dll_list.h"


void main(void){
	int arr[]={1,2,3,4,5,6,7,8,9};
	int len=sizeof(arr)/sizeof(arr[0]);
	Node *list=create_list(arr,len);
	char *str;
	str=to_str(list,len);
	printf("%s\n",str);
	int rst=dll_remove(list,list->fwd->fwd);
	str=to_str(list,len);
	printf("%s\n",str);	
}

