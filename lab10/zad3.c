#include <stdio.h>

typedef struct{
    char ulica[20];
    int nr_domu;
    char kod[8];
    char miasto[20];
} Adres;

typedef struct{
    char imie[20];
    char nazwisko[20];
    int staz_pracy;
    Adres adres;
} Pracownik;

int main(){
    Pracownik pracownicy[2];

    for(int i = 0; i < 2; i++){
        printf("Podaj imie pracownika %d: ", i+1);
        scanf("%s", pracownicy[i].imie);
        printf("Podaj nazwisko pracownika %d: ", i+1);
        scanf("%s", pracownicy[i].nazwisko);
        printf("Podaj staz pracy pracownika %d: ", i+1);
        scanf("%d", &pracownicy[i].staz_pracy);
        printf("Podaj ulice pracownika %d: ", i+1);
        scanf("%s", pracownicy[i].adres.ulica);
        printf("Podaj nr domu pracownika %d: ", i+1);
        scanf("%d", &pracownicy[i].adres.nr_domu);
        printf("Podaj kod pocztowy pracownika %d: ", i+1);
        scanf("%s", pracownicy[i].adres.kod);
        printf("Podaj miasto pracownika %d: ", i+1);
        scanf("%s", pracownicy[i].adres.miasto);
        printf("\n");
    }
    
    for(int i = 0; i < 2; i++){
        printf("Pracownik %d:\n", i+1);
        printf("Imie: %s\n", pracownicy[i].imie);
        printf("Nazwisko: %s\n", pracownicy[i].nazwisko);
        printf("Staz pracy: %d\n", pracownicy[i].staz_pracy);
        printf("--------------------\n")
        printf("Adres:\n");
        printf("Ulica: %s\n", pracownicy[i].adres.ulica);
        printf("Nr domu: %d\n", pracownicy[i].adres.nr_domu);
        printf("Kod pocztowy: %s\n", pracownicy[i].adres.kod);
        printf("Miasto: %s\n", pracownicy[i].adres.miasto);
        printf("\n");
    }
}