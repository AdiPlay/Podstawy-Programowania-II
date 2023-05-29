#include <stdio.h>

struct DaneTechniczne{
    int pojemnoscSkokowa;
    int moc;
    int momentObrotowy;
    char paliwo[10];
};

struct Silnik{
    char nazwa[25];
    char producent[25];
    double cenaNetto;
    struct DaneTechniczne daneSilnika;
    int VAT;
    float cenaBrutto;
};

void wczytajStrukt(struct Silnik* silnik);
void dodajDoPliku(struct Silnik* silnik, FILE* plik);
void odczytajDrukuj(FILE* plik);

int main(int argc, char const *argv[])
{
    FILE *fp = fopen("silniki.dat", "w+b");
    if(fp == NULL){
        printf("Nie udalo sie otworzyc pliku");
        exit(1);
    }
    struct Silnik silnik;
    wczytajStrukt(&silnik);
    dodajDoPliku(&silnik, fp);
    rewind(fp);
    printf("\nZawartość pliku:\n");
    odczytajDrukuj(fp);
    fclose(fp);
    return 0;
}

void wczytajStrukt(struct Silnik* silnik){
    printf("Podaj nazwe silnika: ");
    scanf("%s", silnik->nazwa);
    printf("Podaj producenta silnika: ");
    scanf("%s", silnik->producent);
    printf("Podaj cene netto silnika: ");
    scanf("%lf", &silnik->cenaNetto);
    printf("Podaj pojemnosc skokowa silnika: ");
    scanf("%d", &silnik->daneSilnika.pojemnoscSkokowa);
    printf("Podaj moc silnika: ");
    scanf("%d", &silnik->daneSilnika.moc);
    printf("Podaj moment obrotowy silnika: ");
    scanf("%d", &silnik->daneSilnika.momentObrotowy);
    printf("Podaj paliwo silnika: ");
    scanf("%s", silnik->daneSilnika.paliwo);
    printf("Podaj VAT silnika: ");
    scanf("%d", &silnik->VAT);
    silnik->cenaBrutto = silnik->cenaNetto * (1 + silnik->VAT/100.0);
}

void dodajDoPliku(struct Silnik* silnik, FILE* plik) {
    fwrite(silnik, sizeof(struct Silnik), 1, plik);
}

void odczytajDrukuj(FILE* plik) {
    struct Silnik silnik;

    printf("Zawartość pliku:\n");
    while (fread(&silnik, sizeof(struct Silnik), 1, plik) == 1) {
        printf("Nazwa: %s\n", silnik.nazwa);
        printf("Producent: %s\n", silnik.producent);
        printf("Cena Netto: %.2lf\n", silnik.cenaNetto);
        printf("Pojemność Skokowa: %d\n", silnik.daneSilnika.pojemnoscSkokowa);
        printf("Moc: %d\n", silnik.daneSilnika.moc);
        printf("Moment Obrotowy: %d\n", silnik.daneSilnika.momentObrotowy);
        printf("Paliwo: %s\n", silnik.daneSilnika.paliwo);
        printf("VAT: %d\n", silnik.VAT);
        printf("Cena Brutto: %.2lf\n\n", silnik.cenaBrutto);
    }
}