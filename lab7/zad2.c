#include <stdio.h>

int main() {
    FILE *f = fopen("liczby2.dat", "rb");
    double sum = 0;
    double number;
    while (fread(&number, sizeof(double), 1, f)) {
        sum += number;
    }
    fclose(f);
    printf("%lf", sum);
    return 0;
}