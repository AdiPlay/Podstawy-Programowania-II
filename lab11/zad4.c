#include <stdio.h>
#include <string.h>
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
void zmienDaneTechniczne(struct Silnik* silnik);
int main(int argc, char const *argv[]){
    struct Silnik silnik;
    FILE* fp = fopen("silniki.dat", "r+b");
    if(fp == NULL){
        printf("Nie udalo sie otworzyc pliku");
        exit(1);
    }
    int pozycja;
    printf("Podaj pozycje do zmiany: ");
    scanf("%d", &pozycja);
    zmienDaneTechniczne(&silnik);
    fseek(fp, (pozycja-1)*sizeof(struct Silnik), SEEK_SET);
    fwrite(&silnik, sizeof(struct Silnik), 1, fp);
    // Wypisanie zawartosci pliku
    rewind(fp);
    while(fread(&silnik, sizeof(struct Silnik), 1, fp) == 1){
        printf("Nazwa: %s\n", silnik.nazwa);
        printf("Producent: %s\n", silnik.producent);
        printf("Cena netto: %.2lf\n", silnik.cenaNetto);
        printf("Pojemnosc skokowa: %d\n", silnik.daneSilnika.pojemnoscSkokowa);
        printf("Moc: %d\n", silnik.daneSilnika.moc);
        printf("Moment obrotowy: %d\n", silnik.daneSilnika.momentObrotowy);
        printf("Paliwo: %s\n", silnik.daneSilnika.paliwo);
        printf("VAT: %d\n", silnik.VAT);
        printf("Cena brutto: %.2lf\n", silnik.cenaBrutto);
        printf("\n");        
    }
    fclose(fp);
    return 0;
}
void zmienDaneTechniczne(struct Silnik* silnik){
    printf("Podaj nowa pojemnosc skokowa: ");
    scanf("%d", &silnik->daneSilnika.pojemnoscSkokowa);
    printf("Podaj nowa moc: ");
    scanf("%d", &silnik->daneSilnika.moc);
    printf("Podaj nowy moment obrotowy: ");
    scanf("%d", &silnik->daneSilnika.momentObrotowy);
    printf("Podaj nowe paliwo: ");
    scanf("%s", silnik->daneSilnika.paliwo);
}