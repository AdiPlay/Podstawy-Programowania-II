#include <stdio.h>

void wczyt1D(double[], int n);
void druk1D(double[], int n);

int main(int argc, char const *argv[])
{
    double x[5], y[6];

    printf("Wprowadź 5 liczb do tablicy x:\n");
    wczyt1D(x, 5);
    printf("Tablica x:\n");
    druk1D(x, 5);

    printf("Wprowadź 6 liczb do tablicy y:\n");
    wczyt1D(y, 6);
    printf("Tablica y:\n");
    druk1D(y, 6);

    return 0;
}

void wczyt1D(double tab[], int n)
{
    int i;
    int k;
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
        }while(k == 0);
    }
}

void druk1D(double tab[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%g ", tab[i]);
    }
    printf("\n");
}