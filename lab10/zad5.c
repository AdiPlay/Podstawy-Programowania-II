#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student {
  char nazwisko[20];
  char imie[20];
  int rokStudiow;
  char wydzial[20];
};
void wczytajStudenta(struct Student *s);
void drukujStudenta(struct Student *s);
int main(int argc, char const *argv[])
{
    struct Student *student;
    student = (struct Student*)malloc(sizeof(struct Student));
    wczytajStudenta(student);
    printf("\n");
    drukujStudenta(student);
    free(student);
    return 0;
}
void wczytajStudenta(struct Student *s) {
  printf("Podaj imie: ");
  scanf("%s", s->imie);
  printf("Podaj nazwisko: ");
  scanf("%s", s->nazwisko);
  printf("Podaj rok studiow: ");
  scanf("%d", &s->rokStudiow);
  printf("Podaj wydzial: ");
  scanf("%s", s->wydzial);
}
void drukujStudenta(struct Student *s) {
  printf("Imie: %s\n", s->imie);
  printf("Nazwisko: %s\n", s->nazwisko);
  printf("Rok studiow: %d\n", s->rokStudiow);
  printf("Wydzial: %s\n", s->wydzial);
}