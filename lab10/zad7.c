#include <stdio.h>
#include <string.h>

typedef struct Student{
    char imie[20];
    char nazwisko[20];
    int rokStudiow;
    char wydzial[20];
} Student;

void sortuj(Student *studenci, int n);

int main(int argc, char const *argv[])
{
    Student st[3] = {
        {"Jan", "Kowalski", 1, "Ekonomia"},
        {"Adam", "Nowak", 2, "Informatyka"},
        {"Piotr", "Bartkowiak", 3, "Mechanika"}
    };
    printf("Przed sortowaniem:\n");
    for(int i = 0; i < 3; i++){
        printf("%s %s, rok %d, wydzial %s\n", st[i].imie, st[i].nazwisko, st[i].rokStudiow, st[i].wydzial);
    }
    sortuj(st, 3);
    printf("\nPo sortowaniu:\n");
    for(int i = 0; i < 3; i++){
        printf("%s %s, rok %d, wydzial %s\n", st[i].imie, st[i].nazwisko, st[i].rokStudiow, st[i].wydzial);
    }
    return 0;
}

void sortuj(Student *studenci, int n){
    int i, j;
    Student temp;
    for(i = 0; i < n; i++){
        for(j = 0; j < n - 1; j++){
            if(strcmp(studenci[j].nazwisko, studenci[j + 1].nazwisko) > 0){
                temp = studenci[j];
                studenci[j] = studenci[j + 1];
                studenci[j + 1] = temp;
            }
        }
    }
}
