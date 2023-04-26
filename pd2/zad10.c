#include <stdio.h>
#include <stdlib.h>

void odwrElWierszy(int n, int m, int tab[n][m]);

int main(int argc, char const *argv[]){
    int arr[3][3] = {{1, 2, 3},
                     {4, 5, 6},
                     {7, 8, 9}};
    printf("Przed odwróceniem:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    odwrElWierszy(3, 3, arr);
    printf("Po odwróceniu:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void odwrElWierszy (int n, int m, int tab[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m / 2; j++) {
            int temp = tab[i][j];
            tab[i][j] = tab[i][m - j - 1];
            tab[i][m - j - 1] = temp;
        }
    }
}
