#include <stdio.h>

#define N 5

void wczyt1D(int n, int tab[]);  
void oblicz(int n, int tab[], int *suma_dodatnie, int *ilosc_ujemne); 


int main(){
    int xx[N];
    int suma, ilosc;
    wczyt1D(N, xx);
    oblicz(N, xx, &suma, &ilosc);
    printf("Suma liczb dodatnich: %d\n", suma);
    printf("Ilosc liczb ujemnych: %d\n", ilosc);
    return 0;
}

void wczyt1D(int n, int tab[]){
    for (int i = 0; i < n; i++){
        printf("Podaj element %d: ", i + 1);
        scanf("%d", &tab[i]);
    }
}

void oblicz(int n, int tab[], int *suma_dodatnie, int *ilosc_ujemne){
    *suma_dodatnie = 0;
    *ilosc_ujemne = 0;
    for (int i = 0; i < n; i++){
        if (tab[i] > 0){
            *suma_dodatnie += tab[i];
        }
        else if (tab[i] < 0){
            (*ilosc_ujemne)++;
        }
    }
}
