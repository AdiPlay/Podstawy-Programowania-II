#include <stdio.h>

int min(int* x, int* y);

int main() {
    int a = 10;
    int b = 5;
    int m = min(&a, &b);
    printf("Mniejsze jest %d\n", m); 
    return 0;
}

int min(int* x, int* y) {
    if (*x < *y) {
        return *x;
    } else {
        return *y;
    }
}
