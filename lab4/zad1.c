#include <stdio.h>
#include <stdlib.h>

void wczyt1D(double[], int n, char nazwa);
void druk1D(double[], int n, char nazwa);

int main(int argc, char const *argv[])
{
    double x[5], y[6];
    char cx = 'x';
    char cy = 'y';
    wczyt1D(x, 5, cx);
    druk1D(x, 5, cx);
    wczyt1D(y, 6, cy);
    druk1D(y, 6, cy);
    return 0;
}

void wczyt1D(double tab[], int n, char nazwa)
{
    int i;
    int k;
    printf("Wprowadź %d elementow do tablicy %c:\n", n, nazwa);
    for (i = 0; i < n; i++)
    {
        do
        {
            printf("Podaj %d element: ", i + 1);
            k = scanf("%lf", &tab[i]);
            if (k == 0)
            {
                printf("Błędne dane, wprowadź ponownie: \n");
            }
            fflush(stdin);
        } while (k == 0);
    }
}

void druk1D(double tab[], int n, char nazwa)
{
    int i;
    printf("Wypisuję tablicę %c: \n", nazwa);
    for (i = 0; i < n; i++)
    {
        printf("%.2lf ", tab[i]);
    }
    printf("\n");
}
