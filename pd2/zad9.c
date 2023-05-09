#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *function(int n, int tab[]);

int main(int argc, char const *argv[]){
    srand(time(NULL));
    int n = 5;
    int tab[5];
    for (int i = 0; i < n; i++){
        tab[i] = rand() % 100;
    }
    printf(" tab: ");
    for (int i = 0; i < n; i++){
        printf("%d ", tab[i]);
    }
    printf("\n");
    int *wynik = function(n, tab);
    printf(" max: %d\n maxIndex: %d\n min: %d\n minIndex: %d\n maxAbs: %d\n maxAbsIndex: %d\n", wynik[0], wynik[1], wynik[2], wynik[3], wynik[4], wynik[5]);
    free(wynik);
    return 0;
}
int *function(int n, int tab[]){
    int *wynik = (int *)malloc(6 * sizeof(int));
    int max = tab[0], min = tab[0], maxIndex = 0, minIndex = 0, maxAbs = abs(tab[0]), maxAbsIndex = 0;
    for (int i = 0; i < n; i++){
        if (tab[i] > max){
            max = tab[i];
            maxIndex = i;
        }
        if (tab[i] < min){
            min = tab[i];
            minIndex = i;
        }
        if (abs(tab[i]) > maxAbs){
            maxAbs = abs(tab[i]);
            maxAbsIndex = i;
        }
    }
    wynik[0] = max;
    wynik[1] = maxIndex;
    wynik[2] = min;
    wynik[3] = minIndex;
    wynik[4] = maxAbs;
    wynik[5] = maxAbsIndex;
    return wynik;
}