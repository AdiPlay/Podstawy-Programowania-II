#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct{
    int id;
    char tytul[40];
    char autor[40];
    int rokWydania;
    char gatunek[40];
    float cena;
}Gra;

Gra gry[MAX];

void wczytaj(Gra *gry, int n);
void wypisz(Gra *gry, int n);
void sortuj(Gra *gry, int n);
void zapisz(Gra *gry, int n); //
void usun(Gra *gry, int n); //
void dodaj(Gra *gry, int n); //
void edytuj(Gra *gry, int n); //
void menu();

int main(int argc, char const *argv[])
{
    int n = 0;
    int wybor;
    wczytaj(gry, n);
    do{
        menu();
        scanf("%d", &wybor);
        switch(wybor){
            case 1:
                dodaj(gry, n);
                n++;
                break;
            case 2:
                edytuj(gry, n);
                break;
            case 3:
                usun(gry, n);
                n--;
                break;
            case 4:
                sortuj(gry, n);
                break;
            case 5:
                wypisz(gry, n);
                break;
            case 6:
                zapisz(gry, n);
                break;
            case 7:
                wczytaj(gry, n);
                break;
            case 8:
                printf("Koniec programu\n");
                break;
            default:
                printf("Nie ma takiej opcji\n");
                break;
        }
    }while(wybor != 8);
    
    return 0;
}

void dodaj(Gra *gry, int n){
    printf("Podaj id: ");
    scanf("%d", &gry[n].id);
    printf("Podaj tytul: ");
    scanf("%s", gry[n].tytul);
    printf("Podaj autora: ");
    scanf("%s", gry[n].autor);
    printf("Podaj rok wydania: ");
    scanf("%d", &gry[n].rokWydania);
    printf("Podaj gatunek: ");
    scanf("%s", gry[n].gatunek);
    printf("Podaj cene: ");
    scanf("%f", &gry[n].cena);
}
void zapisz(Gra *gry, int n){
    FILE *fp;
    fp = fopen("gry.txt", "w");
    if(fp == NULL){
        printf("Nie udalo sie otworzyc pliku\n");
        exit(1);
    }
    for(int i = 0; i < n; i++){
        fprintf(fp, "%d %s %s %d %s %f\n", gry[i].id, gry[i].tytul, gry[i].autor, gry[i].rokWydania, gry[i].gatunek, gry[i].cena);
    }
    fclose(fp);
}
void usun(Gra *gry, int n){
    int id;
    printf("Podaj id gry do usuniecia: ");
    scanf("%d", &id);
    for(int i = 0; i < n; i++){
        if(gry[i].id == id){
            for(int j = i; j < n; j++){
                gry[j] = gry[j+1];
            }
            n--;
        }
    }
}
void edytuj(Gra *gry, int n){
    int id;
    printf("Podaj id gry do edycji: ");
    scanf("%d", &id);
    for(int i = 0; i < n; i++){
        if(gry[i].id == id){
            printf("Podaj nowy tytul: ");
            scanf("%s", gry[i].tytul);
            printf("Podaj nowego autora: ");
            scanf("%s", gry[i].autor);
            printf("Podaj nowy rok wydania: ");
            scanf("%d", &gry[i].rokWydania);
            printf("Podaj nowy gatunek: ");
            scanf("%s", gry[i].gatunek);
            printf("Podaj nowa cene: ");
            scanf("%f", &gry[i].cena);
        }
    }
}
void wczytaj(Gra *gry, int n){
    FILE *fp;
    fp = fopen("gry.txt", "r");
    if(fp == NULL){
        printf("Nie udalo sie otworzyc pliku\n");
        exit(1);
    }
    for(int i = 0; i < n; i++){
        fscanf(fp, "%d %s %s %d %s %f\n", &gry[i].id, gry[i].tytul, gry[i].autor, &gry[i].rokWydania, gry[i].gatunek, &gry[i].cena);
    }
    fclose(fp);
}

void sortuj(Gra *gry, int n){
    Gra temp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if(strcmp(gry[j].tytul, gry[j+1].tytul) > 0){
                temp = gry[j];
                gry[j] = gry[j+1];
                gry[j+1] = temp;
            }
        }
    }
}

void wypisz(Gra *gry, int n){
    //wypisz graficznie
    printf("id\ttytul\tautor\trok wydania\tgatunek\tcena\n");
    for(int i = 0; i < n; i++){
        printf("%d\t%s\t%s\t%d\t%s\t%f\n", gry[i].id, gry[i].tytul, gry[i].autor, gry[i].rokWydania, gry[i].gatunek, gry[i].cena);
    }
    
}

void menu(){
    printf("1. Dodaj dane\n");
    printf("2. Edytuj dane\n");
    printf("3. Usun dane\n");
    printf("4. Sortuj dane\n");
    printf("5. Wydrukuj dane\n");
    printf("6. Zapisz dane\n");
    printf("7. Wczytaj dane\n");
    printf("8. Koniec programu\n");
}