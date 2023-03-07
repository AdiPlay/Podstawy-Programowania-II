#include <stdio.h>

double dAdd(double a, double b);
double dSubtract(double a, double b);
double dMultiply(double a, double b);
double dDivide(double a, double b);

int main()
{

    double x1 = 2.5, y1 = 1.5;
    double x2 = 4.0, y2 = 2.0;

    printf("dAdd(%.2lf, %.2lf) = %.2lf\n", x1, y1, dAdd(x1, y1));
    printf("dAdd(%.2lf, %.2lf) = %.2lf\n", x2, y2, dAdd(x2, y2));
    printf("dSubtract(%.2lf, %.2lf) = %.2lf\n", x1, y1, dSubtract(x1, y1));
    printf("dSubtract(%.2lf, %.2lf) = %.2lf\n", x2, y2, dSubtract(x2, y2));
    printf("dMultiply(%.2lf, %.2lf) = %.2lf\n", x1, y1, dMultiply(x1, y1));
    printf("dMultiply(%.2lf, %.2lf) = %.2lf\n", x2, y2, dMultiply(x2, y2));
    printf("dDivide(%.2lf, %.2lf) = %.2lf\n", x1, y1, dDivide(x1, y1));
    printf("dDivide(%.2lf, %.2lf) = %.2lf\n", x2, y2, dDivide(x2, y2));

    return 0;
}

double dAdd(double a, double b)
{
    return a + b;
}

double dSubtract(double a, double b)
{
    return a - b;
}

double dMultiply(double a, double b)
{
    return a * b;
}

double dDivide(double a, double b)
{
    return a / b;
}