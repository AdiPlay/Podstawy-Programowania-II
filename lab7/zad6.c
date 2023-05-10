#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 0;
    FILE *fp, *fp2;
    fp = fopen("liczby4.dat", "r+b");
    if (fp == NULL)
    {
        printf("Nie mozna otworzyc pliku\n");
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    int n = size / sizeof(int);
    int *tab;
    tab = calloc(n, sizeof(int));
    fseek(fp, 0, SEEK_SET);
    fread(tab, sizeof(int), n, fp);
    printf("Odczytano %d liczb\n", n);
    printf("Oto one: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
    fclose(fp);
    getchar();
    fp2 = fopen("liczby5.dat", "w+b");
    if (fp2 == NULL)
    {
        printf("Nie mozna otworzyc pliku\n");
        return 1;
    }
    for (i = n - 1; i >= 0; i--)
    {
        fwrite(&tab[i], sizeof(int), 1, fp);
    }
    fseek(fp2, 0, SEEK_SET);
    fread(tab, sizeof(int), n, fp);
    printf("Liczby z pliku liczby5.dat: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
    int j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (tab[j] > tab[j + 1])
            {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
    fseek(fp2, 0, SEEK_SET);
    getchar();
    printf("Posortowane liczby: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
    fclose(fp2);
    return 0;
}
