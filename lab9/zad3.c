#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[]){
    char nazwisko[10], imie[10], imie_nazwisko[20];
    printf("Podaj imie: ");
    scanf("%s", imie);
    printf("Podaj nazwisko: ");
    scanf("%s", nazwisko);
    strlwr(imie);
    strlwr(nazwisko);
    imie[0] = toupper(imie[0]);
    nazwisko[0] = toupper(nazwisko[0]);
    sprintf(imie_nazwisko, "%s %s", imie, nazwisko);
    printf("Imie i nazwisko: %s\n", imie_nazwisko);
    return 0;
}
