#include <stdio.h>

int floorSqrt(int x);

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
    printf("Zaokrąglony w dół pierwiastek z %d: %d\n", n, floorSqrt(n));  
    return 0;
}

int floorSqrt(int x)
{
    if (x == 0 || x == 1)
        return x;
    int i = 1, result = 1;
    while (result <= x)
    {
        i++;
        result = i * i;
    }
    return i - 1;
}