#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
void utworzNowyPlik();
void drukujStruktSil(struct Silnik silnik);
int main(int argc, char const *argv[]){
    struct Silnik silniki[4] = {
        {"1.9TDI", "VW", 1000, {100, 100, 100, "Benzyna"}, 23, 1230},
        {"Boxer", "Subaru", 2000, {200, 200, 200, "Diesel"}, 23, 2460},
        {"V12", "BWM", 3000, {300, 300, 300, "Benzyna"}, 23, 3690},
        {"AMG", "Mercedes", 4000, {400, 400, 400, "Diesel"}, 23, 4920}
    };
    utworzNowyPlik();
    FILE *fp = fopen("silniki.dat", "w+b");
    if(fp == NULL){
        printf("Nie udalo sie otworzyc pliku");
        exit(1);
    }
    fwrite(silniki, sizeof(struct Silnik), 4, fp);
    fclose(fp);
    fp = fopen("silniki.dat", "r+b");
    if(fp == NULL){
        printf("Nie udalo sie otworzyc pliku");
        exit(1);
    }
    struct Silnik odczytaneSilniki[4];
    fread(odczytaneSilniki, sizeof(struct Silnik), 4, fp);
    printf("\nWczytane dane:\n");
    for(int i = 0; i < 4; i++){
        drukujStruktSil(odczytaneSilniki[i]);
        printf("\n");
    }
    fclose(fp);
    //zmienDaneTechniczne();
    return 0;
}
void utworzNowyPlik(){
    FILE *fp = fopen("silniki.dat", "w+b");
    if(fp == NULL){
        printf("Nie udalo sie utworzyc pliku");
        exit(1);
    }
}
void drukujStruktSil(struct Silnik silnik){
    printf("Nazwa: %s\n", silnik.nazwa);
    printf("Producent: %s\n", silnik.producent);
    printf("Pojemnosc skokowa: %d\n", silnik.daneSilnika.pojemnoscSkokowa);
    printf("Moc: %d\n", silnik.daneSilnika.moc);
    printf("Moment obrotowy: %d\n", silnik.daneSilnika.momentObrotowy);
    printf("Paliwo: %s\n", silnik.daneSilnika.paliwo);
    printf("Cena netto: %lf\n", silnik.cenaNetto);
    printf("VAT: %d\n", silnik.VAT);
    printf("Cena brutto: %lf\n", silnik.cenaBrutto);
}

