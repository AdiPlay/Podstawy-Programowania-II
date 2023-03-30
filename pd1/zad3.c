#include <stdio.h>

int nwd(int n);

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
    printf("Największy dzielnik: %d\n", nwd(n));
    return 0;
}

int nwd(int n)
{
    int i;
    for (i = n - 1; i > 1; i--)
    {
        if (n % i == 0)
        {
            return i;
        }
    }
    return -1;
}