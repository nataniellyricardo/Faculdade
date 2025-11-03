#include <stdio.h>

int main(){
	

	
	int x[5]={1, 0, 0, 0, 1};
	int cont=0;
	int i;
	int n=5;
	int a;

	scanf("%d",&a);
	
	for(i=0; i<5; i++){
	if(x[i] == 0){
		if((i > 0 && x[i - 1] == 1) || (i < n -1 && x[i+1]==1)){
		cont++;

		}
}
}		
	if(cont >= a)
		printf("true");
	else
		printf("false");		
	
}
