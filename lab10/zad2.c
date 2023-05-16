#include <stdio.h>
#include <string.h>

struct Student
{
    char imie[20];
    char nazwisko[20];
    int rokStudiow;
    char wydzial[20];
};
int main(int argc, char const *argv[])
{
    struct Student studenci[3];

    for (int i = 0; i < 3; i++){
        printf("Podaj imie studenta %d: ", i+1);
        scanf("%s", studenci[i].imie);
        printf("Podaj nazwisko studenta %d: ", i+1);
        scanf("%s", studenci[i].nazwisko);
        printf("Podaj rok studiow studenta %d: ", i+1);
        scanf("%d", &studenci[i].rokStudiow);
        printf("Podaj wydzial studenta %d: ", i+1);
        scanf("%s", studenci[i].wydzial);
        printf("\n");
    }

    for (int i = 0; i < 3; i++){
        printf("Student %d:\n", i+1);
        printf("Imie: %s\n", studenci[i].imie);
        printf("Nazwisko: %s\n", studenci[i].nazwisko);
        printf("Rok studiow: %d\n", studenci[i].rokStudiow);
        printf("Wydzial: %s\n", studenci[i].wydzial);
        printf("\n");
    }
    return 0;
}
