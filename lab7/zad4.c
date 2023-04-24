#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    FILE *f1 = fopen("liczby3.dat", "wb");
    FILE *f2 = fopen("kopia.dat", "wb");
    FILE *f3 = fopen("liczby4.dat", "wb");

    int n = 10;
    int number;

    printf("a) Utworzenie plików liczby3.dat, kopia.dat i liczby4.dat w trybie \"w+b\".\n");

    printf("\nb) Generowanie 10 liczb pseudolosowych typu int (użyć rand()%%20) i zapisanie wygenerowanych liczb do pliku liczby3.dat.\n");
    for (int i = 0; i < n; i++) {
        number = rand() % 20;
        fwrite(&number, sizeof(int), 1, f1);
    }

    printf("\nc) Kopiowanie pliku liczby3.dat do pliku kopia.dat.\n");
    fseek(f1, 0L, SEEK_SET);
    while (fread(&number, sizeof(int), 1, f1)) {
        fwrite(&number, sizeof(int), 1, f2);
    }

    printf("\nd) Przepisywanie liczb parzystych z pliku kopia.dat do pliku liczby4.dat.\n");
    fseek(f2, 0L, SEEK_SET);
    while (fread(&number, sizeof(int), 1, f2)) {
        if (number % 2 == 0) {
            fwrite(&number, sizeof(int), 1, f3);
        }
    }

    printf("\ne) Drukowanie plików liczby3.dat, kopia.dat i liczby4.dat.\n");
    printf("\nliczby3.dat:\n");
    fseek(f1, 0L, SEEK_SET);
    while (fread(&number, sizeof(int), 1, f1)) {
        printf("%d\n", number);
    }

    printf("\nkopia.dat:\n");
    fseek(f2, 0L, SEEK_SET);
    while (fread(&number, sizeof(int), 1, f2)) {
        printf("%d\n", number);
    }

    printf("\nliczby4.dat:\n");
    fseek(f3, 0L, SEEK_SET);
    while (fread(&number, sizeof(int), 1, f3)) {
        printf("%d\n", number);
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);

    return 0;
}