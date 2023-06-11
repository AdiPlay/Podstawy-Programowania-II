#include <stdio.h>
#include <stdlib.h>
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
int porownajSilniki(const void* a, const void* b);
void sortujPlik();
int main(int argc, char const *argv[]){
    sortujPlik();
    FILE *fp = fopen("silniki.dat", "rb");
    if(fp == NULL){
        printf("Nie udalo sie otworzyc pliku");
        exit(1);
    }
    struct Silnik silnik;
    while(fread(&silnik, sizeof(struct Silnik), 1, fp) == 1){
        printf("Nazwa: %s\n", silnik.nazwa);
        printf("Producent: %s\n", silnik.producent);
        printf("Cena Netto: %.2lf\n", silnik.cenaNetto);
        printf("Pojemność Skokowa: %d\n", silnik.daneSilnika.pojemnoscSkokowa);
        printf("Moc: %d\n", silnik.daneSilnika.moc);
        printf("Moment Obrotowy: %d\n", silnik.daneSilnika.momentObrotowy);
        printf("Paliwo: %s\n", silnik.daneSilnika.paliwo);
        printf("VAT: %d\n", silnik.VAT);
        printf("Cena Brutto: %.2f\n", silnik.cenaBrutto);
        printf("-----------------------\n");
    }
    fclose(fp);
    return 0;
}
int porownajSilniki(const void* a, const void* b){
    const struct Silnik* silnikA = (struct Silnik*)a;
    const struct Silnik* silnikB = (struct Silnik*)b;
    return silnikA->daneSilnika.pojemnoscSkokowa - silnikB->daneSilnika.pojemnoscSkokowa;
}
void sortujPlik(){
    FILE* fp = fopen("silniki.dat", "r+b");
    if(fp == NULL){
        printf("Nie udalo sie otworzyc pliku");
        exit(1);
    }
    struct Silnik silnik;
    int i = 0;
    while(fread(&silnik, sizeof(struct Silnik), 1, fp) == 1){
        i++;
    }
    rewind(fp);
    struct Silnik* silniki = malloc(i*sizeof(struct Silnik));
    i = 0;
    while(fread(&silnik, sizeof(struct Silnik), 1, fp) == 1){
        silniki[i] = silnik;
        i++;
    }
    qsort(silniki, i, sizeof(struct Silnik), porownajSilniki);
    rewind(fp);
    for(int j = 0; j < i; j++){
        fwrite(&silniki[j], sizeof(struct Silnik), 1, fp);
    }
    fclose(fp);
    free(silniki);
}
