#include <stdio.h>

void sumWKP(int n, int m, int x[n][m], int nrWiersza, int nrKolumny, double suma[]);

int main() {
    int tab[3][3] = { {1, 2, 3}, {2, 5, 7}, {0 ,1, -1} };
    int nrWiersza, nrKolumny, i;
    double suma[3];
    
    printf("Podaj numer wiersza (0-2): ");
    scanf("%d", &nrWiersza);
    printf("Podaj numer kolumny (0-2): ");
    scanf("%d", &nrKolumny);
    
    sumWKP(3, 3, tab, nrWiersza, nrKolumny, suma);
    
    printf("Suma elementow wiersza %d: %g\n", nrWiersza, suma[0]);
    printf("Suma elementow kolumny %d: %g\n", nrKolumny, suma[1]);
    printf("Suma elementow na glownej przekatnej: %g\n", suma[2]);
    
    return 0;
}

void sumWKP(int n, int m, int x[n][m], int nrWiersza, int nrKolumny, double suma[]) {
    int i, j;
    suma[0] = 0; // suma wybranego wiersza
    suma[1] = 0; // suma wybranej kolumny
    suma[2] = 0; // suma elementów na głównej przekątnej
    
    // obliczenie sumy wybranego wiersza
    for (j = 0; j < m; j++) {
        suma[0] += x[nrWiersza][j];
    }
    
    // obliczenie sumy wybranej kolumny
    for (i = 0; i < n; i++) {
        suma[1] += x[i][nrKolumny];
    }
    
    // obliczenie sumy elementów na głównej przekątnej
    for (i = 0; i < n; i++) {
        if (i == nrKolumny) {
            suma[2] += x[i][i];
        }
    }
}