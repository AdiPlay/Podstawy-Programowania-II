#include <stdio.h>

int bezwzgledna(int n);

int main(int argc, char const *argv[])
{
    int n, k;
    do
    {
        printf("Podaj liczbę: ");
        k = scanf("%d", &n);
        if (k == 0)
        {
            printf("Błąd formatu, spróbuj ponownie \n");
        }
        fflush(stdin);
    } while (k == 0);
    printf("Wartość bezwzględna: %d\n", bezwzgledna(n));
    return 0;
}

int bezwzgledna(int n)
{
    if (n < 0)
        return -n;
    else
        return n;
}