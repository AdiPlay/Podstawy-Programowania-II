#include <stdio.h>

void sumWKP(int n, int m, int x[n][m], int nrWiersza, int nrKolumny, double wyniki[]);

int main() {
    int tab[3][3] = { {1, 2, 3}, {2, 5, 7}, {0 ,1, -1} };
    int nrWiersza, nrKolumny, i;
    double wyniki[3];
    
    printf("Podaj numer wiersza (0-2): ");
    scanf("%d", &nrWiersza);
    printf("Podaj numer kolumny (0-2): ");
    scanf("%d", &nrKolumny);
    
    sumWKP(3, 3, tab, nrWiersza, nrKolumny, wyniki);
    
    printf("Suma elementow wiersza %d: %g\n", nrWiersza, wyniki[0]);
    printf("Suma elementow kolumny %d: %g\n", nrKolumny, wyniki[1]);
    printf("Suma elementow na glownej przekatnej: %g\n", wyniki[2]);
    
    return 0;
}

void sumWKP(int n, int m, int x[n][m], int nrWiersza, int nrKolumny, double wyniki[]) {
    int i, j;
    wyniki[0] = 0; // suma wybranego wiersza
    wyniki[1] = 0; // suma wybranej kolumny
    wyniki[2] = 0; // suma elementów na głównej przekątnej
    
    // obliczenie sumy wybranego wiersza
    for (j = 0; j < m; j++) {
        wyniki[0] += x[nrWiersza][j];
    }
    
    // obliczenie sumy wybranej kolumny
    for (i = 0; i < n; i++) {
        wyniki[1] += x[i][nrKolumny];
    }
    
    // obliczenie sumy elementów na głównej przekątnej
    for (i = 0; i < n; i++) {
        if (i == nrKolumny) {
            wyniki[2] += x[i][i];
        }
    }
}