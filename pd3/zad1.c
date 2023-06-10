#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void przepisz43(int macierz[][4], int nrWiersza, int nrKolumny, int podmacierz[][3]);
void przepisz54(int macierz[][5], int nrWiersza, int nrKolumny, int podmacierz[][4]);
int sarrus(int macierz[][3]);
int laplace(int macierz[][4]);

int main(int argc, char *argv[])
{
    // Generowanie macierzy A za pomocą funkcji rand()
    int A[5][5], n = 5;
    unsigned int nrAlbumu = 19727; // Należy wstawić własny nr albumu
    unsigned int i, j, m, mod;
    srand(time(NULL));
    int w3 = 3;
    int k1 = 1;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            m = nrAlbumu % (rand() % 10 + 1);
            A[i][j] = rand() % 10 + m;
        }

    // Wygenerowana macierz A
    printf("Macierz A:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%3d ", A[i][j]);
        printf("\n");
    }

    int B0[4][4], B1[4][4], B2[4][4], B3[4][4], B4[4][4];
    // Podział macierzy A (5x5) na podmacierze B (4x4)
    przepisz54(A, 0, k1, B0);
    przepisz54(A, 1, k1, B1);
    przepisz54(A, 2, k1, B2);
    przepisz54(A, 3, k1, B3);
    przepisz54(A, 4, k1, B4);

    // Podział macierzy B (4x4) na podmacierze C (3x3)
    int C0[3][3], C1[3][3], C2[3][3], C3[3][3], C4[3][3];
    przepisz43(B0, w3, 0, C0);
    przepisz43(B1, w3, 0, C1);
    przepisz43(B2, w3, 0, C2);
    przepisz43(B3, w3, 0, C3);

    // Obliczenie wyznaczników macierzy C (3x3) i B (4x4)
    // Metoda Sarrusa
    int detC0 = sarrus(C0);
    int detC1 = sarrus(C1);
    int detC2 = sarrus(C2);
    int detC3 = sarrus(C3);
    // Metoda Laplace'a
    int detB0 = laplace(B0);
    int detB1 = laplace(B1);
    int detB2 = laplace(B2);
    int detB3 = laplace(B3);
    int detB4 = laplace(B4);

    // Macierze
    printf("\nMacierze:\n");
    printf("B0:\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            printf("%3d ", B0[i][j]);
        printf("\n");
    }
    printf("B1:\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            printf("%3d ", B1[i][j]);
        printf("\n");
    }
    printf("B2:\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            printf("%3d ", B2[i][j]);
        printf("\n");
    }
    printf("B3:\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            printf("%3d ", B3[i][j]);
        printf("\n");
    }
    printf("B4:\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            printf("%3d ", B4[i][j]);
        printf("\n");
    }

    printf("C0:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%3d ", C0[i][j]);
        printf("\n");
    }
    printf("C1:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%3d ", C1[i][j]);
        printf("\n");
    }
    printf("C2:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%3d ", C2[i][j]);
        printf("\n");
    }
    printf("C3:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%3d ", C3[i][j]);
        printf("\n");
    }

    // Wyznaczniki
    printf("\nWyznaczniki:\n");
    printf("detB0 = %d\n", detB0);
    printf("detB1 = %d\n", detB1);
    printf("detB2 = %d\n", detB2);
    printf("detB3 = %d\n", detB3);
    printf("detB4 = %d\n", detB4);

    printf("detC0 = %d\n", detC0);
    printf("detC1 = %d\n", detC1);
    printf("detC2 = %d\n", detC2);
    printf("detC3 = %d\n", detC3);
}

void przepisz43(int macierz[][4], int nrWiersza, int nrKolumny,
                int podmacierz[][3])
{
    int m = 0, n = 0;
    for (int i = 0; i < 4; i++)
    {
        if (i != nrWiersza)
        {
            n = 0;
            for (int j = 0; j < 4; j++)
            {
                if (j != nrKolumny)
                {
                    podmacierz[m][n] = macierz[i][j];
                    n++;
                }
            }
            m++;
        }
    }
}

void przepisz54(int macierz[][5], int nrWiersza, int nrKolumny,
                int podmacierz[][4])
{
    int m = 0, n = 0;
    for (int i = 0; i < 5; i++)
    {
        if (i != nrWiersza)
        {
            n = 0;
            for (int j = 0; j < 5; j++)
            {
                if (j != nrKolumny)
                {
                    podmacierz[m][n] = macierz[i][j];
                    n++;
                }
            }
            m++;
        }
    }
}

int sarrus(int macierz[][3])
{
    return macierz[0][0] * macierz[1][1] * macierz[2][2] +
           macierz[0][1] * macierz[1][2] * macierz[2][0] +
           macierz[0][2] * macierz[1][0] * macierz[2][1] -
           macierz[0][2] * macierz[1][1] * macierz[2][0] -
           macierz[0][1] * macierz[1][0] * macierz[2][2] -
           macierz[0][0] * macierz[1][2] * macierz[2][1];
}

int laplace(int macierz[][4])
{
    int det = 0;
    for (int i = 0; i < 4; i++)
    {
        int m[3][3];
        przepisz43(macierz, 0, i, m);
        int sign = (i % 2 == 0) ? 1 : -1;
        det += sign * macierz[0][i] * sarrus(m);
    }
    return det;
}