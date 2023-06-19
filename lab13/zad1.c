#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <io.h>
#include <string.h>
#include <unistd.h>

struct Produkt {
    char nazwa[20];
    float cena;
    int ilosc;
};

int main() {
    FILE *fp;
    int handle;
    long dlugoscBajty;
    struct Produkt produkty[4] = {
        {"Chleb", 2.5, 10},
        {"Mleko", 1.8, 20},
        {"Jajka", 0.3, 30},
        {"Ser", 3.2, 5}
    };

    FILE* plik = fopen("deletetest.dat", "wb");

    if (plik == NULL) {
        printf("Nie udalo sie otworzyc pliku.\n");
        return 1;
    }

    fwrite(produkty, sizeof(struct Produkt), 4, plik);
    fclose(plik);

    printf("Zawartosc pliku przed usunieciem:\n");

    plik = fopen("deletetest.dat", "rb");

    if (plik == NULL) {
        printf("Nie udalo sie otworzyc pliku.\n");
        return 1;
    }

    struct Produkt produkt;
    while (fread(&produkt, sizeof(struct Produkt), 1, plik) == 1) {
        printf("%s %.2f %d\n", produkt.nazwa, produkt.cena, produkt.ilosc);
    }

    fclose(plik);

    // zamiana drugiej struktury z czwartą
    plik = fopen("deletetest.dat", "r+b");

    if (plik == NULL) {
        printf("Nie udalo sie otworzyc pliku.\n");
        return 1;
    }

    struct Produkt temp;
    fseek(plik, sizeof(struct Produkt), SEEK_SET);
    fread(&temp, sizeof(struct Produkt), 1, plik);
    fseek(plik, -2 * sizeof(struct Produkt), SEEK_END);
    fwrite(&temp, sizeof(struct Produkt), 1, plik);
    fseek(plik, sizeof(struct Produkt), SEEK_SET);
    fwrite(&produkty[3], sizeof(struct Produkt), 1, plik);

    fclose(plik);

    // obciecie pliku
    int nowaDlugoscPlikBajty = 3 * sizeof(struct Produkt);
    int handle = open("deletetest.dat", O_RDWR);
    if (handle != -1) {
        printf("Plik zostal utworzony.\n");
    } else {
        printf("Nie udalo sie otworzyc pliku.\n");
        return 1;
    }
    truncate("deletetest.dat", nowaDlugoscPlikBajty);
    close(handle);

    // wyswietlenie zawartosci pliku po usunieciu
    printf("Zawartosc pliku po usunieciu:\n");

    plik = fopen("deletetest.dat", "rb");

    if (plik == NULL) {
        printf("Nie udalo sie otworzyc pliku.\n");
        return 1;
    }

    while (fread(&produkt, sizeof(struct Produkt), 1, plik) == 1) {
        printf("%s %.2f %d\n", produkt.nazwa, produkt.cena, produkt.ilosc);
    }

    fclose(plik);

    // sprawdzenie dlugosci pliku w bajtach
    FILE *fp = fopen("deletetest.dat", "rb");
    fseek(fp, 0, SEEK_END);
    dlugoscBajty = ftell(fp);
    printf("Nowa dlugosc = %ld\n", dlugoscBajty);
    fclose(fp);

    return 0;
}