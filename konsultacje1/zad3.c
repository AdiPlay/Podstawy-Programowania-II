#include <stdio.h>

void wczyt2D(int n, int m, double x[n][m]);
void druk2D(int n, int m, double x[n][m]);
int oblicz2D(int n, int m, double x[n][m], int k1, int k2, double *pSumK1, double *pSumK2);

int main()
{
    int sig;
    double x[3][3];
    wczyt2D(3, 3, x);
    druk2D(3, 3, x);
    double sumK1 = 0, sumK2 = 0;
    sig = oblicz2D(3, 3, x, 0, 2, &sumK1, &sumK2);
    printf("\nSuma kolumny 0 = %.2lf\nSuma kolumny 2 = %.2lf", sumK1, sumK2);
    return 0;
}

void wczyt2D(int n, int m, double x[m][n])
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            do
            {
                printf("\n Element [%d][%d] = ", i, j);
                k = scanf("%lf", &x[i][j]);
                fflush(stdin);
            } while (k == 0);
        }
    }
}
void druk2D(int n, int m, double x[n][m])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf(" %.2lf ", x[i][j]);
        }
        printf("\n");
    }
}
int oblicz2D(int n, int m, double x[n][m], int k1, int k2, double *pSumK1, double *pSumK2)
{
    int sig = 0, SumK1 = 0, SumK2 = 0;
    int licz1 = 0, licz2 = 0;
    // sprawdzanie czy kolumny zawieraja przynajmniej jeden element niezerowy
    for (int i = 0; i < n; i++)
    {
        if (x[i][k1] != 0)
        {
            licz1++;
        }
        if (x[i][k2] != 0)
        {
            licz2++;
        }
    }
    // jesli tak to obliczanie sumy
    if (licz1 != 0 && licz2 != 0)
    {
        sig = 1;
        for (int i = 0; i < n; i++)
        {
            SumK1 += x[i][k1];
            SumK2 += x[i][k2];
        }
        // przypisanie sumy do wskaznikow
        *pSumK1 = SumK1;
        *pSumK2 = SumK2;
    }
    return sig;
}

// oblicza i zwraca sume dwoch wybranych kolumn, pod warunkiem ze kazda z kolumn zawiera przynajmniej jeden element niezerowy
