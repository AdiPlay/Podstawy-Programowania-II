#include <stdio.h>

#define N 4

int main() {
    // inicjalizacja tablicy 4x4
    int tablica[N][N] = {{1, 2, 3, 4},
                         {5, 6, 7, 8},
                         {9, 10, 11, 12},
                         {13, 14, 15, 16}};

    // wyświetlenie tablicy przed zamianą wierszy
    printf("Tablica przed zamianą wierszy:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", tablica[i][j]);
        }
        printf("\n");
    }

    // pobranie numerów wierszy do zamiany od użytkownika
    int wiersz1, wiersz2;
    printf("Podaj numer pierwszego wiersza do zamiany (1-4): ");
    scanf("%d", &wiersz1);
    printf("Podaj numer drugiego wiersza do zamiany (1-4): ");
    scanf("%d", &wiersz2);

    // zamiana wierszy
    for (int j = 0; j < N; j++) {
        int temp = tablica[wiersz1-1][j];
        tablica[wiersz1-1][j] = tablica[wiersz2-1][j];
        tablica[wiersz2-1][j] = temp;
    }

    // wyświetlenie tablicy po zamianie wierszy
    printf("Tablica po zamianie wierszy:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", tablica[i][j]);
        }
        printf("\n");
    }

    return 0;
}
