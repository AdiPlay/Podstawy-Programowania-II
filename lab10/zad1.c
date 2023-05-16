#include <stdio.h>
#include <string.h>

struct Student{
    char imie[20];
    char nazwisko[20];
    int rokStudiow;
    char wydzial[20];
};

int main(int argc, char const *argv[])
{
    struct Student student1, student2;
    strcpy(student1.imie, "Adrian");
    strcpy(student1.nazwisko, "Kokoszka");
    student1.rokStudiow = 2;
    strcpy(student1.wydzial, "Informatyka - GKiM");

    printf("Podaj imie studenta 2: ");
    scanf("%s", student2.imie);
    printf("Podaj nazwisko studenta 2: ");
    scanf("%s", student2.nazwisko);
    printf("Podaj rok studiow studenta 2: ");
    scanf("%d", &student2.rokStudiow);
    printf("Podaj wydzial studenta 2: ");
    scanf("%s", student2.wydzial);

    printf("Student 1:\n");
    printf("Imie: %s\n", student1.imie);
    printf("Nazwisko: %s\n", student1.nazwisko);
    printf("Rok studiow: %d\n", student1.rokStudiow);
    printf("Wydzial: %s\n", student1.wydzial);
    printf("\n");
    printf("Student 2:\n");
    printf("Imie: %s\n", student2.imie);
    printf("Nazwisko: %s\n", student2.nazwisko);
    printf("Rok studiow: %d\n", student2.rokStudiow);
    printf("Wydzial: %s\n", student2.wydzial);

    return 0;
}


