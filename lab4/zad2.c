#include <stdio.h>

double average(double tab[], int n);
double max(double tab[], int n);
void wczyt1D(double tab[], int n);

int main()
{
    double tab[6];
    wczyt1D(tab, 6);

    double srednia = average(tab, 6);
    double maksimum = max(tab, 6);

    printf("Tablica:\n");
    int i;
    for (i = 0; i < 6; i++)
    {
        printf("%g ", tab[i]);
    }
    printf("\n");
    printf("Średnia arytmetyczna: %g\n", srednia);
    printf("Maksimum: %g\n", maksimum);

    return 0;
}

double average(double tab[], int n)
{
    double suma = 0.0;
    int i;
    for (i = 0; i < n; i++)
    {
        suma += tab[i];
    }
    return suma / n;
}

double max(double tab[], int n)
{
    double maksimum = tab[0];
    int i;
    for (i = 1; i < n; i++)
    {
        if (tab[i] > maksimum)
        {
            maksimum = tab[i];
        }
    }
    return maksimum;
}

void wczyt1D(double tab[], int n)
{
    int i, k;
    for (i = 0; i < n; i++)
    {
        do
        {
            printf("Podaj %d liczbę: ", i + 1);
            k = scanf("%lf", &tab[i]);
            if (k == 0)
            {
                printf("Błędne dane, wprowadź ponownie: ");
            }
            fflush(stdin);
        } while (k == 0);
    }
}
