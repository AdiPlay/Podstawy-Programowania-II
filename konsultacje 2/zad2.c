#include <stdio.h>
#include <stdlib.h>

//funkcja wczyt2D w stylu C99
void wczyt2D(int n, int m, double tab[n][m]);
void drukuj2D(int n, int m, double tab[n][m]);

void fx(int n, int m, double tab[n][m], int k, int w, double *sumaK, double *sumaW);

int main(int argc, char const *argv[])
{
    printf("Podaj wymiary tablicy: ");
    int n, m;
    scanf("%d %d", &n, &m);
    double tab[n][m];
    wczyt2D(n, m, tab);
    printf("Podaj kolumne i wiersz: ");
    int k, w;
    scanf("%d %d", &k, &w);
    double sumaK, sumaW;
    fx(n, m, tab, k, w, &sumaK, &sumaW);
    printf("Suma kolumny %d = %lf\nSuma wiersza %d = %lf\n", k, sumaK, w, sumaW);
    return 0;
}

void wczyt2D(int n, int m, double tab[n][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%lf", &tab[i][j]);
        }
    }
}

void drukuj2D(int n, int m, double tab[n][m])
{
    printf("Tablica:\n");
    for (int i = 0; i < n; i++)
    {
        printf("[");
        for (int j = 0; j < m; j++)
        {
            printf("%lf", tab[i][j]);
            if (j != m - 1)
                printf(", ");
        }
        printf("]\n");
    }
}

void fx(int n, int m, double tab[n][m], int k, int w, double *sumaK, double *sumaW)
{
    *sumaK = 0;
    *sumaW = 0;
    for (int i = 0; i < n; i++)
    {
        *sumaK += tab[i][k];
    }
    for (int i = 0; i < m; i++)
    {
        if(tab[w][i] < 0)
        *sumaW += tab[w][i];
    }
}
