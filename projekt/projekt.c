#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Processor
{
    int cores;
    float clock_speed;
    float price;

};

void addProcessor(struct Processor *processors, int *count);
void saveProcessors(struct Processor *processors, int count);
void readProcessors(struct Processor *processors, int *count);
void displayProcessors(struct Processor *processors, int count);
void displayMenu();


int main()
{
    struct Processor processors[100];
    int count = 0;

    readProcessors(processors, &count);

    int choice;
    do
    {
        displayMenu();
        printf("Wybierz opcję: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addProcessor(processors, &count);
            break;
        case 2:
            saveProcessors(processors, count);
            break;
        case 3:
            readProcessors(processors, &count);
            break;
        case 4:
            break;
        case 5:
            displayProcessors(processors, count);
            break;
        default:
            printf("Nieznana opcja.\n");
            break;
        }
        printf("\n");
    } while (choice != 4);

    return 0;
}

void addProcessor(struct Processor *processors, int *count)
{
    printf("Podaj nazwę procesora: ");
    scanf("%s", processors[*count].name);
    printf("Podaj liczbę rdzeni: ");
    scanf("%d", &processors[*count].cores);
    printf("Podaj taktowanie procesora: ");
    scanf("%f", &processors[*count].clock_speed);
    (*count)++;

    saveProcessors(processors, *count);
}

void saveProcessors(struct Processor *processors, int count)
{
    FILE *file = fopen("processors.txt", "w");
    if (file == NULL)
    {
        printf("Nie udało się otworzyć pliku.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%s %d %.2f\n", processors[i].name, processors[i].cores, processors[i].clock_speed);
    }

    fclose(file);
}

void readProcessors(struct Processor *processors, int *count)
{
    FILE *file = fopen("processors.txt", "r");
    if (file == NULL)
    {
        printf("Nie udało się otworzyć pliku.\n");
        return;
    }

    while (!feof(file))
    {
        fscanf(file, "%s %d %f\n", processors[*count].name, &processors[*count].cores, &processors[*count].clock_speed);
        (*count)++;
    }

    fclose(file);
}

void displayProcessors(struct Processor *processors, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%s %d %.2f\n", processors[i].name, processors[i].cores, processors[i].clock_speed);
    }
}

void displayMenu()
{
    printf("1. Dodaj procesor\n");
    printf("2. Zapisz procesory do pliku\n");
    printf("3. Odczytaj procesory z pliku\n");
    printf("5. Wyświetl procesory\n");
    printf("4. Wyjście\n");
}