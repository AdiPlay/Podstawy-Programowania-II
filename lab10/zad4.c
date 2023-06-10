#include <stdio.h>
#include <string.h>
struct Student{
    char imie[20];
    char nazwisko[20];
    int rokStudiow;
    char wydzial[20];
};
struct Student wczytStruct(){
    struct Student student;
    printf("Podaj imie studenta: ");
    scanf("%s", student.imie);
    printf("Podaj nazwisko studenta: ");
    scanf("%s", student.nazwisko);
    printf("Podaj rok studiow studenta: ");
    scanf("%d", &student.rokStudiow);
    printf("Podaj wydzial studenta: ");
    scanf("%s", student.wydzial);
    return student;
};
void drukStruct(struct Student student);
int main(int argc, char const *argv[]){
    struct Student studenciR1[2];
    for(int i = 0; i < 2; i++){
        studenciR1[i] = wczytStruct();
        printf("\n");
    }
    printf("\n");
    printf("Studenci roku 1:\n");
    for(int i = 0; i < 2; i++){
        drukStruct(studenciR1[i]);
        printf("\n");
    }
    return 0;
}
void drukStruct(struct Student student){
    printf("Imie: %s\n", student.imie);
    printf("Nazwisko: %s\n", student.nazwisko);
    printf("Rok studiow: %d\n", student.rokStudiow);
    printf("Wydzial: %s\n", student.wydzial);
};
