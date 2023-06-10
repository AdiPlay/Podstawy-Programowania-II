#include <stdio.h>
#include <string.h>
struct Student{
    char imie[20];
    char nazwisko[20];
    int rokStudiow;
    char wydzial[20];
};
int main(int argc, char const *argv[]){
    FILE *file = fopen("studenci.txt", "w");
    //metoda 1 - strcpy
    struct Student student1, student2;
    strcpy(student1.imie, "Adrian");
    strcpy(student1.nazwisko, "Kokoszka");
    student1.rokStudiow = 3;
    strcpy(student1.wydzial, "Informatyka - GKiM");
    //metoda 2 - scanf
    printf("Podaj imie studenta 2: ");
    scanf("%s", student2.imie);
    fflush(stdin);
    printf("Podaj nazwisko studenta 2: ");
    scanf("%s", student2.nazwisko);
    printf("Podaj rok studiow studenta 2: ");
    scanf("%d", &student2.rokStudiow);
    fflush(stdin);
    printf("Podaj wydzial studenta 2: ");
    scanf("%s", student2.wydzial);
    //zapis do pliku
    fwrite(&student1, sizeof(struct Student), 1, file);
    fwrite(&student2, sizeof(struct Student), 1, file);
    fclose(file);
    fopen("studenci.txt", "r");
    //odczyt z pliku
    printf("\nZawartosc pliku:\n");
    struct Student buf;
    fseek(file, 0, SEEK_SET);
    while(fread(&buf, sizeof(struct Student), 1, file) == 1){
        printf("Imie: %s\n", buf.imie);
        printf("Nazwisko: %s\n", buf.nazwisko);
        printf("Rok studiow: %d\n", buf.rokStudiow);
        printf("Wydzial: %s\n", buf.wydzial);
        printf("\n");
    }
    fclose(file);
    return 0;
}


