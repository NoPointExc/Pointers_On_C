#include <stdio.h>

float single_tax(float income);
static float tax_bar[4]={23350,56550,117950,256500};
static float tax_base[5]={0,3502.50,12798.50,31832.50,81710.50};
static float tax_rate[5]={0.15,0.28,0.31,0.36,0.398};

void main(void){
	float income;
	scanf("%f",&income);
	float tax=single_tax(income);
	printf("single tax=%f\n",tax);
}

float single_tax(float income){
	int i;
	if(income<=0) return 0;
	for(i=0;i<4;i++){
		if(income<tax_bar[i]) return tax_base[i]+tax_rate[i]*income;
	}
	return tax_base[4]+tax_rate[4]*income;
}
