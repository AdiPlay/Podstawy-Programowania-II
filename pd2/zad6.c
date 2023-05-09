#include <stdio.h>

void przepisz_odwrotnie(int n, int tab1[], int tab2[]);

int main() {
    int n = 5;
    int tab1[] = {1, 2, 3, 4, 5};
    int tab2[n];
    przepisz_odwrotnie(n, tab1, tab2);
    printf("tab1: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tab1[i]);
    }
    printf("\n");
    printf("tab2: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tab2[i]);
    }
    printf("\n");
    return 0;
}

void przepisz_odwrotnie(int n, int tab1[], int tab2[]) {
    for (int i = 0; i < n; i++) {
        tab2[i] = tab1[n - i - 1];
    }
}
