#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    double tab[6] = {12.0, 77.0, 45.0, 87.0, 36.0, 28.0};
    double suma = 0;
    // for (int i = 0; i < 6; i++)
    //     suma += tab[i];
    // printf("Suma elementow w tablicy: %.2lf\n",suma);
    int i;
    fp = fopen("liczby2.dat", "w+b");
    if (fp == NULL)   {
        printf("Brak pliku!\n");
        exit(1);
    }
    fwrite(tab, sizeof(double), 6, fp);
    fclose(fp);
    fp = fopen("liczby2.dat", "rb");
    if (fp == NULL)    {
        printf("Brak pliku!\n");
        exit(1);
    }   
    fread(tab, sizeof(double), 6, fp);
    for (i = 0; i < 6; i++)
        printf("%.2lf\n", tab[i]);
    fclose(fp);
    return 0;
}