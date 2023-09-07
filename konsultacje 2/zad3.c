#include <stdio.h>

struct Monitor
{
    char nazwa[20];
    char typ[20];
    double cena;
};

int main(int argc, char const *argv[])
{
    FILE *fp, *fp2, *fp3;
    int liczbaStruktur;
    fp = fopen("monitory.dat", "w+b");
    if (fp == NULL)
    {
        printf("Nie udalo sie otworzyc pliku\n");
        return 1;
    }
    printf("Podaj liczbe monitorow: ");
    scanf("%d", &liczbaStruktur);
    struct Monitor monitory[liczbaStruktur];
    for (int i = 0; i < liczbaStruktur; i++)
    {
        printf("Podaj nazwe monitora: ");
        scanf("%s", monitory[i].nazwa);
        printf("Podaj typ monitora: ");
        scanf("%s", monitory[i].typ);
        printf("Podaj cene monitora: ");
        scanf("%lf", &monitory[i].cena);
    }
    fwrite(monitory, sizeof(struct Monitor), liczbaStruktur, fp);
    fp2 = fopen("monitory2.dat", "w+b");
    fp3 = fopen("monitory500.dat", "w+b");
    if (fp2 == NULL || fp3 == NULL)
    {
        printf("Nie udalo sie otworzyc pliku\n");
        return 1;
    }
    rewind(fp);
    struct Monitor monitor;
    while (fread(&monitor, sizeof(struct Monitor), 1, fp) == 1)
    {
        if (monitor.cena < 500)
        {
            fwrite(&monitor, sizeof(struct Monitor), 1, fp3);
        }
        fwrite(&monitor, sizeof(struct Monitor), 1, fp2);
    }

    rewind(fp);
    printf("####################\n");
    printf("Zawartosc pliku monitory.dat:\n");
    while (fread(&monitor, sizeof(struct Monitor), 1, fp) == 1)
    {
        printf("Nazwa: %s\nTyp: %s\nCena: %lf\n\n", monitor.nazwa, monitor.typ, monitor.cena);
    }
    rewind(fp2);
    printf("####################\n");
    printf("Zawartosc pliku monitory2.dat:\n");
    while (fread(&monitor, sizeof(struct Monitor), 1, fp2) == 1)
    {
        printf("Nazwa: %s\nTyp: %s\nCena: %lf\n\n", monitor.nazwa, monitor.typ, monitor.cena);
    }
    rewind(fp3);
    printf("####################\n");
    printf("Zawartosc pliku monitory500.dat:\n");
    while (fread(&monitor, sizeof(struct Monitor), 1, fp3) == 1)
    {
        printf("Nazwa: %s\nTyp: %s\nCena: %lf\n\n", monitor.nazwa, monitor.typ, monitor.cena);
    }
    fclose(fp2);
    fclose(fp3);
    fclose(fp);
    return 0;
}
