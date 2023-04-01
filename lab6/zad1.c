#include <stdio.h >
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *px;
    px = (int *)malloc(sizeof(int));
    printf_s("Podaj liczbe calkowita: ");
    scanf_s("%d", px);
    printf_s("Wartosc zmiennej: %d\n", *px);
    printf_s("Adres zmiennej: %p\n", px);
    free(px);
    return 0;
}
