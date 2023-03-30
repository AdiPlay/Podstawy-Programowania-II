#include <stdio.h>

int pow2(int n);

int main(int argc, char const *argv[])
{
    int n, k;
    do
    {
        printf("Podaj liczbę: ");
        k = scanf("%d", &n);
        if (k == 0)
        {
            printf("Błąd formatu, spróbuj ponownie: \n");
        }
        fflush(stdin);
    } while (k == 0);
    printf("2 do potęgi %d: %d\n", n, pow2(n));
    return 0;
}

int pow2(int n)
{
    while (n > 0)
    {
        return 2 * pow2(n - 1);
    }
    return 1;
}