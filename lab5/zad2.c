#include <stdio.h>
void sumWKP(int n, int m, int x[n][m], int nrWiersza, int nrKolumny, double wyniki[]);
int main()
{
    int tab[3][3] = {{5, 4, 12}, {10, 15, 70}, {2, 20, 77}};
    int nrWiersza, nrKolumny, i;
    double wyniki[3];
    do
    {
        printf("Podaj numer wiersza (0-2): ");
        scanf("%d", &nrWiersza);
    } while (nrWiersza < 0 || nrWiersza > 2);
    
    do
    {
        printf("Podaj numer kolumny (0-2): ");
        scanf("%d", &nrKolumny);
    } while (nrKolumny < 0 || nrKolumny > 2);

    sumWKP(3, 3, tab, nrWiersza, nrKolumny, wyniki);
    for (i = 0; i < 3; i++)
        printf("%d\t%d\t%d\n", tab[i][0], tab[i][1], tab[i][2]);
    printf("Suma elementow wiersza %d: %g\n", nrWiersza + 1, wyniki[0]);
    printf("Suma elementow kolumny %d: %g\n", nrKolumny + 1, wyniki[1]);
    printf("Suma elementow na glownej przekatnej: %g\n", wyniki[2]);

    return 0;
}
void sumWKP(int n, int m, int x[n][m], int nrWiersza, int nrKolumny, double wyniki[])
{
    int i, j;
    wyniki[0] = 0; // wyniki wybranego wiersza
    wyniki[1] = 0; // wyniki wybranej kolumny
    wyniki[2] = 0; // wyniki elementów na głównej przekątnej

    // obliczenie sumy wybranego wiersza
    for (j = 0; j < m; j++)
        wyniki[0] += x[nrWiersza][j];

    // obliczenie sumy wybranej kolumny
    for (i = 0; i < n; i++)
        wyniki[1] += x[i][nrKolumny];

    // obliczenie sumy elementów na głównej przekątnej
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (i == j)
                wyniki[2] += x[i][i];
}