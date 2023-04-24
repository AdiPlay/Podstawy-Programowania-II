#include <stdio.h>
#include <stdlib.h>

double* wczyt1Dyn(int n);

int main(){
    int n = 5;
    double *tablica;
    tablica = wczyt1Dyn(n);
    for (int i=0; i<n; i++){
        printf("%lf\n", *(tablica+i));
    }
    free(tablica);
    return 0;
}

double* wczyt1Dyn(int n){
    int i,k;
    double *px;
    px=(double*) malloc(n*sizeof(double));
    for (i=0;i<n;i++){
       do{
            printf("Podaj %d element: ", i + 1);
            k = scanf("%lf", px++);
            if (k == 0)
            {
                printf("Błędne dane, wprowadź ponownie: \n");
            }
            fflush(stdin);
        } while (k == 0);
    }
    px=px-n;
    return px;
}