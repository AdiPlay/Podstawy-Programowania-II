#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 3, m = 3, i, j;
    int (*pa)[m]; 
    pa = (int (*)[m])calloc(n*m, sizeof(int)); 

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("Podaj element[%d][%d] = ", i, j); 
            scanf("%d", &pa[i][j]); 
        } 
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf(" %d ", pa[i][j]); 
        }
        printf("\n");
    } 

    free(pa); 
    system("pause"); 
    return 0;
}
