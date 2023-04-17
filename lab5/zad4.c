#include <stdio.h>
void minmax2D(int n, double x[n][n], double wyniki[]);
int main()
{
    double x[4][4] = {{1.0, 2.0, 3.0, 4.0},
                      {5.0, 6.0, 7.0, 8.0},
                      {9.0, 10.0, 11.0, 12.0},
                      {13.0, 14.0, 15.0, 16.0}};

    double wyniki[17];
    minmax2D(4, x, wyniki);

    printf("Tablica jednowymiarowa:\n");
    for (int i = 0; i < 16; i++)
    {
        printf("%.1lf ", wyniki[i]);
        if ((i + 1) % 4 == 0)
        {
            printf("\n");
        }
    }
    printf("Wartosc minimalna: %.1lf\n", wyniki[16]);
    printf("Wartosc maksymalna: %.1lf\n", wyniki[17]);

    return 0;
}
void minmax2D(int n, double x[n][n], double wyniki[])
{
    double min = x[0][0];
    double max = x[0][0];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (x[i][j] < min)
            {
                min = x[i][j];
            }
            if (x[i][j] > max)
            {
                max = x[i][j];
            }
            wyniki[i * n + j] = x[i][j];
        }
    }

    wyniki[n * n] = min;
    wyniki[n * n + 1] = max;
}