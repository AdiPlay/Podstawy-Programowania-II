#include <stdio.h>

#define N 4

int main() {
    // inicjalizacja macierzy 4x4
    int macierz[N][N] = {{1, 2, 3, 4},
                         {5, 6, 7, 8},
                         {9, 10, 11, 12},
                         {13, 14, 15, 16}};

    // wyświetlenie macierzy przed transpozycją
    printf("Macierz przed transpozycją:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", macierz[i][j]);
        }
        printf("\n");
    }

    // transpozycja macierzy
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            int temp = macierz[i][j];
            macierz[i][j] = macierz[j][i];
            macierz[j][i] = temp;
        }
    }

    // wyświetlenie macierzy po transpozycji
    printf("Macierz po transpozycji:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", macierz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
