#include <stdio.h>

void polacztablice(int n, int tab1[], int tab2[], int tab3[]);

int main(int argc, char const *argv[]){
    int n = 5;
    int tab1[] = {1, 2, 3, 4, 5};
    int tab2[] = {6, 7, 8, 9, 10};
    int tab3[2 * n];
    polacztablice(n, tab1, tab2, tab3);
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
    printf("tab3: ");
    for (int i = 0; i < 2 * n; i++) {
        printf("%d ", tab3[i]);
    }
    printf("\n");  
    return 0;
}
void polacztablice(int n, int tab1[], int tab2[], int tab3[]) {
    for (int i = 0; i < n; i++) {
        tab3[i] = tab1[i];
    }
    for (int i = 0; i < n; i++) {
        tab3[i + n] = tab2[i];
    }
}