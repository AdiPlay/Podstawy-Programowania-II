#include <stdio.h>

#define N 4

int main() {
    int tablica2d[N][N] = {{2, 1, 4, 3},
                           {8, 6, 7, 5},
                           {13, 10, 11, 12},
                           {16, 15, 14, 9}};
    int tablica1d[N*N];

    // przepisanie tablicy dwuwymiarowej do tablicy jednowymiarowej
    int k = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tablica1d[k++] = tablica2d[i][j];
        }
    }

    // sortowanie tablicy jednowymiarowej niemalejąco
    for (int i = 0; i < N*N-1; i++) {
        for (int j = 0; j < N*N-i-1; j++) {
            if (tablica1d[j] > tablica1d[j+1]) {
                int temp = tablica1d[j];
                tablica1d[j] = tablica1d[j+1];
                tablica1d[j+1] = temp;
            }
        }
    }

    // wydrukowanie posortowanej tablicy jednowymiarowej
    printf("Posortowana tablica:\n");
    for (int i = 0; i < N*N; i++) {
        printf("%d ", tablica1d[i]);
    }
    printf("\n");

    return 0;
}
