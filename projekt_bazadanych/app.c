#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char firstName[20];
    char lastName[20];
    char team[20];
    int year;
    int wins;
    int points;
    char team_princ[20];
}F1_Cars;

void add(F1_Cars *cars, int n);
void edit(F1_Cars *cars, int n);
void delete(F1_Cars *cars, int n);
void sort(F1_Cars *cars, int n);
void print(F1_Cars *cars, int n);
void save(F1_Cars *cars, int n);
void load(F1_Cars *cars, int n);
void menu();

int main(int argc, char const *argv[])
{
    int n = 0;
    int wybor;
    F1_Cars *cars = malloc(sizeof(F1_Cars));
    load(cars, n);
    do
    {
        menu();
        scanf("%d", &wybor);
        switch (wybor)
        {
        case 1:
            add(cars, n);
            n++;
            break;
        case 2:
            edit(cars, n);
            break;
        case 3:
            delete(cars, n);
            n--;
            break;
        case 4:
            sort(cars, n);
            break;
        case 5:
            print(cars, n);
            break;
        case 6:
            save(cars, n);
            break;
        case 7:
            printf("Koniec programu\n");
            break;
        default:
            printf("Nie ma takiej opcji\n");
            break;
        }
    } while (wybor != 8);
    
    return 0;
}

void add(F1_Cars *cars, int n)
{
    printf("Podaj imie kierowcy: ");
    scanf("%s", cars[n].firstName);
    printf("Podaj nazwisko kierowcy: ");
    scanf("%s", cars[n].lastName);
    printf("Podaj nazwę zespołu: ");
    scanf("%s", cars[n].team);
    printf("Podaj rok debiutu: ");
    scanf("%d", &cars[n].year);
    printf("Podaj liczbę zwycięstw: ");
    scanf("%d", &cars[n].wins);
    printf("Podaj liczbę punktów: ");
    scanf("%d", &cars[n].points);
    printf("Podaj nazwisko szefa zespołu: ");
    scanf("%s", cars[n].team_princ);
    cars[n].id = n;
    save(cars, n);
}

void edit(F1_Cars *cars, int n)
{
    int id;
    printf("Podaj id kierowcy: ");
    scanf("%d", &id);
    printf("Podaj nazwisko kierowcy: ");
    scanf("%s", cars[id].firstName);
    printf("Podaj nazwisko kierowcy: ");
    scanf("%s", cars[id].lastName);
    printf("Podaj nazwę zespołu: ");
    scanf("%s", cars[id].team);
    printf("Podaj rok debiutu: ");
    scanf("%d", &cars[id].year);
    printf("Podaj liczbę zwycięstw: ");
    scanf("%d", &cars[id].wins);
    printf("Podaj liczbę punktów: ");
    scanf("%d", &cars[id].points);
    printf("Podaj nazwisko szefa zespołu: ");
    scanf("%s", cars[id].team_princ);
}

void delete(F1_Cars *cars, int n)
{
    int id;
    printf("Podaj id kierowcy: ");
    scanf("%d", &id);
    for(int i = id; i < n; i++)
    {
        cars[i] = cars[i+1];
    }
}

void sort(F1_Cars *cars, int n)
{
    F1_Cars temp;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n-1; j++)
        {
            if(cars[j].points < cars[j+1].points)
            {
                temp = cars[j];
                cars[j] = cars[j+1];
                cars[j+1] = temp;
            }
        }
    }
}

void print(F1_Cars *cars, int n)
{
    FILE *fp;
    fp = fopen("f1.txt", "r");
    fseek(fp, 0, SEEK_SET);
    F1_Cars readCars;
    while(fread(&readCars, sizeof(F1_Cars), 1, fp))
    {
        printf("%d\n", readCars.id);
        printf("%s\n", readCars.firstName);
        printf("%s\n", readCars.lastName);
        printf("%s\n", readCars.team);
        printf("%d\n", readCars.year);
        printf("%d\n", readCars.wins);
        printf("%d\n", readCars.points);
        printf("%s\n", readCars.team_princ);
    }
}

void save(F1_Cars *cars, int n)
{
    FILE *fp;
    fp = fopen("f1.txt", "w");
    fwrite(cars, sizeof(F1_Cars), n, fp);
    fclose(fp);
}

void load(F1_Cars *cars, int n)
{
    FILE *fp;
    fp = fopen("f1.txt", "r");
    fseek(fp, 0, SEEK_SET);
    F1_Cars readCars;
    while(fread(&readCars, sizeof(F1_Cars), 1, fp))
    {
        cars[n] = readCars;
        n++;
    }
    fclose(fp);
}

void menu()
{
    printf("1. Dodaj kierowcę\n");
    printf("2. Edytuj kierowcę\n");
    printf("3. Usuń kierowcę\n");
    printf("4. Sortuj kierowców\n");
    printf("5. Wyświetl kierowców\n");
    printf("6. Zapisz kierowców\n");
    printf("7. Wyjście\n");
}