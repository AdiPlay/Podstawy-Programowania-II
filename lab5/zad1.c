#include <stdio.h>

#define M 2

void wczyt2D(int n, double x[][M]);
void druk2D(int n, double x[][M]);
void wczyt2DC99(int n, int m, double x[M][m]);
void druk2DC99(int n, int m, double x[M][m]);

int main(int argc, char const *argv[])
{
    int n;
    double x[M][M];
    double y[M][3];
    double z[M][4];
    printf("Metoda zwykła dla tablicy x:\n");
    wczyt2D(n, x);
    druk2D(n, x);
    printf("Metoda C99 dla tablicy y:\n");
    wczyt2DC99(M, 3, y);
    druk2DC99(M, 3, y);
    printf("Metoda C99 dla tablicy z:\n");
    wczyt2DC99(M, 4, y);
    druk2DC99(M, 4, y);

    return 0;
}

void wczyt2D(int n, double x[][M])
{
    int i, j, k;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < M; j++)
        {
            do
            {
                k = scanf("%lf", &x[i][j]);
                if (k == 0)
                
                    printf("Błędne dane, wprowadź ponownie: ");
                
                fflush(stdin);
            } while (k == 0);
        }
    }
}

void druk2D(int n, double x[][M])
{
    int i, j;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < M; j++)
        {
            printf("[%.2lf]\t", x[i][j]);
        }
        printf("\n");
    }
}

void wczyt2DC99(int n, int m, double x[M][m])
{
    int i, j, k;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < m; j++)
        {
            do
            {
                k = scanf("%lf", &x[i][j]);
                if (k == 0)
                {
                    printf("Błędne dane, wprowadź ponownie: ");
                }
                fflush(stdin);
            } while (k == 0);
        }
    }
}

void druk2DC99(int n, int m, double x[M][m])
{
    int i, j;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%.2lf\t", x[i][j]);
        }
        printf("\n");
    }
}