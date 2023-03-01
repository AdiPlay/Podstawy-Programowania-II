#include <stdio.h>

#define N 4

int main() {
    // inicjalizacja tablicy 4x4
    int tablica[N][N] = {{1, 2, 3, 4},
                         {5, 6, 7, 8},
                         {9, 10, 11, 12},
                         {13, 14, 15, 16}};

    // wyświetlenie tablicy przed zamianą kolumn
    printf("Tablica przed zamianą kolumn:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", tablica[i][j]);
        }
        printf("\n");
    }

    // pobranie numerów kolumn do zamiany od użytkownika
    int kolumna1, kolumna2;
    printf("Podaj numer pierwszej kolumny do zamiany (1-4): ");
    scanf("%d", &kolumna1);
    printf("Podaj numer drugiej kolumny do zamiany (1-4): ");
    scanf("%d", &kolumna2);

    // zamiana kolumn
    for (int i = 0; i < N; i++) {
        int temp = tablica[i][kolumna1-1];
        tablica[i][kolumna1-1] = tablica[i][kolumna2-1];
        tablica[i][kolumna2-1] = temp;
    }

    // wyświetlenie tablicy po zamianie kolumn
    printf("Tablica po zamianie kolumn:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", tablica[i][j]);
        }
        printf("\n");
    }

    return 0;
}
