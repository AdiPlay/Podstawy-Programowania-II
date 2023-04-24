#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    double tab[6] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    int i;

    fp = fopen("liczby2.dat", "w+b");
    if (fp == NULL)
    {
        printf("Nie mogę otworzyć pliku liczby2.dat do zapisu!\n");
        exit(1);
    }

    fwrite(tab, sizeof(double), 6, fp);
    fclose(fp);

    fp = fopen("liczby2.dat", "rb");
    if (fp == NULL)
    {
        printf("Nie mogę otworzyć pliku liczby2.dat do odczytu!\n");
        exit(1);
    }

    fread(tab, sizeof(double), 6, fp);
    for (i = 0; i < 6; i++)
        printf("%f\n", tab[i]);

    fclose(fp);

    return 0;
}