#include <stdio.h>

double min(double* x, double* y);

int main() {
    double a = 20;
    double b = 77;
    double m = min(&a, &b);
    printf("Mniejsze jest %.2lf\n", m); 
    return 0;
}

double min(double* x, double* y) {
    if (*x < *y) {
        return *x;
    } else {
        return *y;
    }
}
