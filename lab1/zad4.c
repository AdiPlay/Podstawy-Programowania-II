#include <stdio.h>

int main() {
    int n, m, i, j;
    printf("Podaj wymiary macierzy: \n");
    scanf("%d %d", &n, &m);

    int macierz[n][m];
	
	
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (i == j)
                macierz[i][j] = 1;
            else
                macierz[i][j] = 0;
        }
    }

    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", macierz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
