#include <stdio.h>
#include <stdlib.h>

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
    srand(time(NULL));
    printf("Podaj %d liczb do tablicy: \n", n);
    for (int i = 0; i < n; i++)
    {
        // printf("Podaj element [%d]: ", i);
        // scanf("%d", ptab + i);
        
        *(ptab + i) = rand() % 100;
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