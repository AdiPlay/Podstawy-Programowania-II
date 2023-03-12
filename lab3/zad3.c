#include <stdio.h>

void wczytTab(int *ptab, int n);
void minTab(int *pi, int n, int *pmin);

int main(int argc, char const *argv[])
{
    int x[5];
    int min;
    wczytTab(x, 5);
    minTab(x, 5, &min);
    printf("Wczytana tablica: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("Element [%d] = %d\n", i, *(x + i));
    }
    printf("Najmniejsza liczba: %d\n", min);
    return 0;
}

void wczytTab(int *ptab, int n)
{
    printf_s("Podaj %d liczb do tablicy: \n", n);
    for (int i = 0; i < n; i++)
    {
        printf_s("Podaj element [%d]: ", i);
        scanf("%d", ptab + i);
    }
}

void minTab(int *pi, int n, int *pmin)
{
    *pmin = *pi;
    for (int i = 0; i < n; i++)
    {
        if (*(pi + i) < *pmin)
        {
            *pmin = *(pi + i);
        }
    }
}