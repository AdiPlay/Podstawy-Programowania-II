#include <stdio.h>

void zamien(double *pd1, double *pd2);

int main(int argc, char const *argv[])
{
    double x = 3.1;
    double y = 1.77;
    printf("Przed zamianą: a = %f, b = %f\n", x, y);
    zamien(&x, &y);
    printf("Po zamianie: a = %f, b = %f\n", x, y);
    return 0;
}

void zamien(double *pd1, double *pd2)
{
    double temp = *pd1;
    *pd1 = *pd2;
    *pd2 = temp;
}
