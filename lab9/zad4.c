#include <stdio.h>
#include <string.h>

int main() {
    char lan1[100], znak, lan2[4];

    // wczytanie danych
    printf("Podaj lancuch znakow lan1: ");
    fgets(lan1, 100, stdin);
    lan1[strcspn(lan1, "\n")] = '\0'; // usuwanie znaku nowej linii

    printf("Podaj pojedynczy znak: ");
    scanf(" %c", &znak);

    printf("Podaj lancuch znakow lan2: ");
    scanf("%3s", lan2);

    // sprawdzenie czy znak i lancuch znakow lan2 wystepuja w lan1
    if (strchr(lan1, znak) != NULL) {
        printf("Podany znak wystepuje w lan1.\n");
    } else {
        printf("Podany znak nie wystepuje w lan1.\n");
    }

    if (strstr(lan1, lan2) != NULL) {
        printf("Podany lancuch znakow lan2 wystepuje w lan1.\n");
    } else {
        printf("Podany lancuch znakow lan2 nie wystepuje w lan1.\n");
    }

    return 0;
}
