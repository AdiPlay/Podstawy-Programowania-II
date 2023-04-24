#include <stdio.h>
int pow(int n, int m);
int main(int argc, char const *argv[])
{
    int n, m, k;
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
    do
    {
        printf("Podaj potęgę: ");
        k = scanf("%d", &m);
        if (k == 0)
        {
            printf("Błąd formatu, spróbuj ponownie: \n");
        }
        fflush(stdin);
    } while (k == 0);
    printf("%d do potęgi %d: %d\n", n, m, pow(n, m));
    return 0;
}
int pow(int n, int m)
{
    while (m > 0)
    {
        return n * pow(n, m - 1);
    }
    return 1;
}