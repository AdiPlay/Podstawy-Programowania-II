#include <stdio.h>

int main(int argc, char const *argv[]){
	double a[2][4];
	int i,j,k,n=2,m=4;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			do{
				printf("Podaj elementy a [%d] [%d] = ",i,j);
				k=scanf("%lf",&a[i][j]);
				if(k==0)
					printf("Blad formatu");
				
				fflush(stdin);
				
			}
			while(k==0);
		
	for(i=0;i<n;i++){		
		for(j=0;j<m;j++)		
			printf(" %lf",a[i][j]);
		printf("\n");
			
			}
	
}
