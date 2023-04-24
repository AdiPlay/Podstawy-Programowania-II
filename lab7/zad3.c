#include <stdio.h>

int main() {
    FILE *f = fopen("liczby2.dat", "rb");
    int n = 6;
    double number;

    printf("Przed zamianą:\n");
    for (int i = 0; i < n; i++) {
        fread(&number, sizeof(double), 1, f);
        printf("%lf\n", number);
    }

    int first_index, second_index;
    double first_number, second_number;

    printf("\nPodaj indeks pierwszej liczby: ");
    scanf("%d", &first_index);
    printf("Podaj indeks drugiej liczby: ");
    scanf("%d", &second_index);

    if (first_index >= n || second_index >= n || first_index < 0 || second_index < 0) {
        printf("Niepoprawne indeksy.\n");
        return 1;
    }

    fseek(f, first_index * sizeof(double), SEEK_SET);
    fread(&first_number, sizeof(double), 1, f);

    fseek(f, second_index * sizeof(double), SEEK_SET);
    fread(&second_number, sizeof(double), 1, f);

    fseek(f, first_index * sizeof(double), SEEK_SET);
    fwrite(&second_number, sizeof(double), 1, f);

    fseek(f, second_index * sizeof(double), SEEK_SET);
    fwrite(&first_number, sizeof(double), 1, f);

    fseek(f, 0L, SEEK_SET);

    printf("\nPo zamianie:\n");
    for (int i = 0; i < n; i++) {
        fread(&number, sizeof(double), 1, f);
        printf("%lf\n", number);
    }

    fclose(f);
    return 0;
}