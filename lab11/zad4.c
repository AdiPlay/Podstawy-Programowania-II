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

int main(int argc, char const *argv[])
{
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
    fread(&silnik, sizeof(struct Silnik), 1, fp);
    fseek(fp, (pozycja-1)*sizeof(struct Silnik), SEEK_SET);
    fwrite(&silnik, sizeof(struct Silnik), 1, fp);
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