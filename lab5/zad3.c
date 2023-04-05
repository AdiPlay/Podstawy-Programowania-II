#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void zamienKK(int n, int m, double x[][m], int nrKol1, int nrKol2);
void zamienWW(int n, int m, double x[][m], int nrWiersza1, int nrWiersza2);
void transpose(int n, double x[][n]);
double sarrus(double x[][3]);


int main(int argc, char const *argv[])
{
    double x[3][3], temp;
    srand(time(NULL));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            x[i][j] = rand()%10;
        }
    }
    printf("Macierz:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%.2lf\t", x[i][j]);
        }
        printf("\n");
    }
    
    printf("Macierz transponowana:\n");
    transpose(3, x);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%.2lf\t", x[i][j]);
        }
        printf("\n");
    }
    printf("Wyznacznik macierzy: %.2lf\n", sarrus(x));
    zamienKK(3, 3, x, 0, 2);
    printf("Macierz po zamianie 1 i 3 kolumny:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%.2lf\t", x[i][j]);
        }
        printf("\n");
    }
    zamienWW(3, 3, x, 0, 2);
    printf("Macierz po zamianie 1 i 3 wiersza:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%.2lf\t", x[i][j]);
        }
        printf("\n");
    }
    


    return 0;
}

void zamienKK(int n, int m, double x[][m], int nrKol1, int nrKol2)
{
    double temp;
    for (int i = 0; i < n; i++)
    {
        temp = x[i][nrKol1];
        x[i][nrKol1] = x[i][nrKol2];
        x[i][nrKol2] = temp;
    }
}

void zamienWW(int n, int m, double x[][m], int nrWiersza1, int nrWiersza2)
{
    double temp;
    for (int j = 0; j < m; j++)
    {
        temp = x[nrWiersza1][j];
        x[nrWiersza1][j] = x[nrWiersza2][j];
        x[nrWiersza2][j] = temp;
    }
}

void transpose(int n, double x[][n])
{
    double temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            temp = x[i][j];
            x[i][j] = x[j][i];
            x[j][i] = temp;
        }
    }
}

double sarrus(double x[][3])
{
    double wynik = 0.0;
    wynik += x[0][0] * x[1][1] * x[2][2];
    wynik += x[1][0] * x[2][1] * x[0][2];
    wynik += x[0][1] * x[1][2] * x[2][0];
    wynik -= x[2][0] * x[1][1] * x[0][2];
    wynik -= x[1][0] * x[0][1] * x[2][2];
    wynik -= x[2][1] * x[1][2] * x[0][0];
    return wynik;
}
