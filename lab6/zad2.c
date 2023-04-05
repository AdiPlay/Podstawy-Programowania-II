#include <stdio.h >
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    double *px;
    px = (double *)malloc(sizeof(double));
    printf_s("Podaj liczbe calkowita: ");
    scanf_s("%lf", px);
    printf_s("Wartosc zmiennej: %lf\n", *px);
    printf_s("Adres zmiennej: %p\n", px);
    free(px);
    return 0;
}
