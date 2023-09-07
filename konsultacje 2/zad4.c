#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *GenerujTablice(int n);
int findMax(int *tab, int n);

int main()
{
    int n;
    printf("Podaj liczbe elementow: ");
    scanf("%d", &n);
    int *tab = GenerujTablice(n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
    int max = findMax(tab, n);
    printf("Max = %d\n", max);
    free(tab);
    return 0;
}

int *GenerujTablice(int n)
{
    int *tab = malloc(n * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            tab[i] = (rand() % 100) * (-1);
        else
            tab[i] = rand() % 100;
    }
    return tab;
}

int findMax(int *tab, int n)
{
    int max = tab[0];
    for (int i = 0; i < n; i++)
    {
        if (tab[i] > max)
            max = tab[i];
    }
    return max;
}