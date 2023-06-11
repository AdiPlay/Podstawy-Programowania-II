#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <io.h>

struct DaneTechniczne {
    int pojemnoscSkokowa;
    int moc;
    int momentObrotowy;
    char paliwo[10];
};

struct Silnik {
    char nazwa[25];
    char producent[25];
    double cenaNetto;
    struct DaneTechniczne daneSilnika;
    int VAT;
    double cenaBrutto;
};

int main(int argc, char const *argv[]){
    struct Silnik silniki[4] = {
        {"Silnik 1", "Producent 1", 1000.0, {1000, 100, 100, "Benzyna"}, 23, 1230.0},
        {"Silnik 2", "Producent 2", 2000.0, {2000, 200, 200, "Diesel"}, 23, 2460.0},
        {"Silnik 3", "Producent 3", 3000.0, {3000, 300, 300, "Benzyna"}, 23, 3690.0},
        {"Silnik 4", "Producent 4", 4000.0, {4000, 400, 400, "Diesel"}, 23, 4920.0}
    };

    FILE* fp = fopen("deletetest.dat", "w+b");
    if(fp == NULL){
        printf("Nie udalo sie otworzyc pliku");
        exit(1);
    }

    fwrite(&silniki, sizeof(struct Silnik), 4, fp);
    fclose(fp);

    fp = fopen("deletetest.dat", "rb");
    if(fp == NULL){
        printf("Nie udalo sie otworzyc pliku");
        exit(1);
    }

    struct Silnik silnik;
    int i = 1;
    while(fread(&silnik, sizeof(struct Silnik), 1, fp) == 1){
        printf("Silnik %d:\n", i++);
        printf("Nazwa: %s\n", silnik.nazwa);
        printf("Producent: %s\n", silnik.producent);
        printf("Cena netto: %f\n", silnik.cenaNetto);
        printf("Pojemnosc skokowa: %d\n", silnik.daneSilnika.pojemnoscSkokowa);
        printf("Moc: %d\n", silnik.daneSilnika.moc);
        printf("Moment obrotowy: %d\n", silnik.daneSilnika.momentObrotowy);
        printf("Paliwo: %s\n", silnik.daneSilnika.paliwo);
        printf("VAT: %d\n", silnik.VAT);
        printf("Cena brutto: %f\n", silnik.cenaBrutto);
        printf("\n");
    }

    fseek(fp, sizeof(struct Silnik), SEEK_SET);
    fread(&silnik, sizeof(struct Silnik), 1, fp);
    fseek(fp, -2*sizeof(struct Silnik), SEEK_CUR);
    fwrite(&silnik, sizeof(struct Silnik), 1, fp);
    fclose(fp);

    int handle;
    handle = open("deletetest.dat", O_RDWR);
    if (handle != -1) printf("\nPlik zostal otwarty");
    else printf("\nPlik nie zostal otwarty");

    truncate("deletetest.dat", 3*sizeof(struct Silnik));

    close(handle);

    fp = fopen("deletetest.dat", "rb");
    if(fp == NULL){
        printf("Nie udalo sie otworzyc pliku");
        exit(1);
    }

    i = 1;
    while(fread(&silnik, sizeof(struct Silnik), 1, fp) == 1){
        printf("Silnik %d:\n", i++);
        printf("Nazwa: %s\n", silnik.nazwa);
        printf("Producent: %s\n", silnik.producent);
        printf("Cena netto: %f\n", silnik.cenaNetto);
        printf("Pojemnosc skokowa: %d\n", silnik.daneSilnika.pojemnoscSkokowa);
        printf("Moc: %d\n", silnik.daneSilnika.moc);
        printf("Moment obrotowy: %d\n", silnik.daneSilnika.momentObrotowy);
        printf("Paliwo: %s\n", silnik.daneSilnika.paliwo);
        printf("VAT: %d\n", silnik.VAT);
        printf("Cena brutto: %f\n", silnik.cenaBrutto);
        printf("\n");
    }

    fclose(fp);

    return 0;
}