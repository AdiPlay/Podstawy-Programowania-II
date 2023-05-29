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

void wyszukajStruktSil(FILE* plik, int pojemnosc);

int main(int argc, char const *argv[])
{
    FILE* fp = fopen("silniki.dat", "r+b");
    if(fp == NULL){
        printf("Nie udalo sie otworzyc pliku");
        exit(1);
    }
    int pojemnosc;
    printf("Podaj pojemnosc skokowa: ");
    scanf("%d", &pojemnosc); 
    fseek(fp, 0, SEEK_SET);
    wyszukajStruktSil(fp, pojemnosc);
    fclose(fp);
    return 0;
}

void wyszukajStruktSil(FILE* plik, int pojemnosc){
    struct Silnik silnik;
    printf("Wyniki wyszukiwania:\n");
    while(fread(&silnik, sizeof(struct Silnik), 1, plik) == 1){
        if(silnik.daneSilnika.pojemnoscSkokowa == pojemnosc){
            printf("Nazwa: %s\n", silnik.nazwa);
            printf("Producent: %s\n", silnik.producent);
            printf("Cena netto: %lf\n", silnik.cenaNetto);
            printf("Pojemnosc skokowa: %d\n", silnik.daneSilnika.pojemnoscSkokowa);
            printf("Moc: %d\n", silnik.daneSilnika.moc);
            printf("Moment obrotowy: %d\n", silnik.daneSilnika.momentObrotowy);
            printf("Paliwo: %s\n", silnik.daneSilnika.paliwo);
            printf("VAT: %d\n", silnik.VAT);
            printf("Cena brutto: %f\n", silnik.cenaBrutto);
        }
    }
    
}
