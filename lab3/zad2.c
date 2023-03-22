#include <stdio.h>
#include <stdlib.h>

void zamien(double *pd1, double *pd2);

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    double x = rand() % 100;
    double y = rand() % 100;
    printf("Przed zamianą: a = %.2lf, b = %.2lf\n", x, y);
    zamien(&x, &y);
    printf("Po zamianie: a = %.2lf, b = %.2lf\n", x, y);
    return 0;
}

void zamien(double *pd1, double *pd2)
{
    double temp = *pd1;
    *pd1 = *pd2;
    *pd2 = temp;
}
