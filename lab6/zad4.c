#include <stdio.h>
#include <stdlib.h>

double *wczyt1Dyn(int n);

int main()
{
    int n, i;
    double *tab;

    printf("Podaj liczbe elementow tablicy: ");
    scanf("%d", &n);

    tab = wczyt1Dyn(n); /* wczytanie tablicy */

    printf("Wczytana tablica:\n");
    for (i = 0; i < n; i++)
    {
        printf("%lf ", tab[i]); /* wyświetlenie tablicy */
    }
    printf("\n");

    free(tab); /* zwolnienie pamięci */

    return 0;
}

double *wczyt1Dyn(int n)
{
    int i;
    double *px;
    px = (double *)malloc(n * sizeof(double)); /* alokacja pamięci */
    if (px == NULL)
    {
        printf("Blad alokacji pamieci\n");
        exit(1); /* zakończenie programu z kodem błędu */
    }
    for (i = 0; i < n; i++)
    {
        printf("\n Podaj element[%d]=", i);
        scanf("%lf", px + i); /* wczytanie elementu */
    }
    return px; /* zwrócenie wskaźnika do alokowanej tablicy */
}