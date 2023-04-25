#include <stdio.h>

void zamien(double* a, double* b);

int main() {
    double x = 5.0;
    double y = 3.0;
    printf("Przed zamianą: x = %f, y = %f\n", x, y);
    zamien(&x, &y);
    printf("Po zamianie: x = %f, y = %f\n", x, y);
    return 0;
}

void zamien(double* a, double* b) {
    if (*b < *a) {
        double temp = *a;
        *a = *b;
        *b = temp;
    }
}