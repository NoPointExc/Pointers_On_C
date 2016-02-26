#include "dll_list.h"

void main(void){
	int arr[]={1,2,3,4,5,6,7,8,9};
	//Node *list=create_list(arr);
	Node fir, sec, thr;
	fir.bwd=NULL;
	fir.fwd=&sec;
	fir.val=1;
	sec.val=2;
	sec.fwd=&fir;
	sec.bwd=&thr;
	thr.val=3;
	thr.bwd=&sec;
	thr.fwd=NULL;
	char *str=to_str(&fir,3);
	//char *str=to_str(list,sizeof(arr)/sizeof(arr[0]));
	printf("%s\n",str);

	//free(list);
	//free(str);
}

