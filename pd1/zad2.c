#include <stdio.h>

int silnia(int n);

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
    printf("Silnia: %d\n", silnia(n));
    return 0;
}

int silnia(int n)
{
    if (n == 0)
        return 1;
    else
        return n * silnia(n - 1);
}