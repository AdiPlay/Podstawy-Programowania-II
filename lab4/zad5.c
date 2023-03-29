#include <stdio.h>

#define N 5

void wczyt1D(int n, int tab[]);  // wczytanie tablicy
void oblicz(int n, int tab[], int *suma_dodatnie, int *ilosc_ujemne);  // obliczenie sumy dodatnich i ilości ujemnych


int main()
{
    int xx[N];
    int suma, ilosc;

    wczyt1D(N, xx);
    oblicz(N, xx, &suma, &ilosc);

    printf("Suma dodatnich: %d\n", suma);
    printf("Ilosc ujemnych: %d\n", ilosc);

    return 0;
}

void wczyt1D(int n, int tab[])
{
    for (int i = 0; i < n; i++)
    {
        printf("Podaj element %d: ", i + 1);
        scanf("%d", &tab[i]);
    }
}

void oblicz(int n, int tab[], int *suma_dodatnie, int *ilosc_ujemne)
{
    *suma_dodatnie = 0;
    *ilosc_ujemne = 0;
    for (int i = 0; i < n; i++)
    {
        if (tab[i] > 0)
        {
            *suma_dodatnie += tab[i];
        }
        else if (tab[i] < 0)
        {
            (*ilosc_ujemne)++;
        }
    }
}
