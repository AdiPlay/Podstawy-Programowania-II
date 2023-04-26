#include <stdio.h>

int main()
{
    FILE *f = fopen("liczby2.dat", "rb");
    fseek(f, 0, SEEK_END);
    double sum = 0;
    double buf;
    int ilosc = ftell(f) / sizeof(double);
    printf("Ilosc elementow w tablicy: %d", ilosc);
    fseek(f, 0, SEEK_SET);
    for (int i = 0; i < ilosc; i++){
    fread(&buf, sizeof(double), 1, f);
        sum += buf;
    }
    printf("\nSuma elementow w tablicy: %.2lf", sum);
    fclose(f);
    return 0;
}