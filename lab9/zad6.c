#include <stdlib.h>
#include <stdio.h>
void pdkt_a();
void pdkt_b();
void pdkt_c();
int main(){
    printf("Podpunkt a)\n");
    pdkt_a();
    printf("Podpunkt b)\n");
    pdkt_b();
    printf("Podpunkt c)\n");
    pdkt_c();
    return 0;
}
void pdkt_a(){
    char liczba[10];
    printf("Podaj liczbę całkowitą: ");
    scanf("%s", liczba);
    int wynik = atoi(liczba);
    printf("Wynik konwersji: %d\n", wynik);
}
void pdkt_b(){
    char liczba[10];
    printf("Podaj liczbę rzeczywistą: ");
    scanf("%s", liczba);
    double wynik = atof(liczba);
    printf("Wynik konwersji: %lf\n", wynik);
}
void pdkt_c(){
    int liczba;
    printf("Podaj liczbę całkowitą: ");
    scanf("%d", &liczba);
    char tablica1[10];
    char tablica2[10];
    char tablica3[10];
    itoa(liczba, tablica1, 10); // liczba dziesiętna
    itoa(liczba, tablica2, 2);  // liczba dwójkowa
    itoa(liczba, tablica3, 16); // liczba szesnastkowa
    printf("Liczba dziesiętna: %s\n", tablica1);
    printf("Liczba dwójkowa: %s\n", tablica2);
    printf("Liczba szesnastkowa: %s\n", tablica3);
}