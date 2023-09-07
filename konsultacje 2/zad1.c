#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

struct Liczba
{
    int liczba1;
    int liczba2;
    char znak;
};

struct Liczba wczytajStrukture(void);
void utworzPlik(int n);

int main(int argc, char const *argv[])
{
    utworzPlik(1);
    FILE *fp = fopen("liczby.dat", "r+b");
    if (fp == NULL)
    {
        printf("Nie udalo sie otworzyc pliku liczby.dat\n");
        return 1;
    }
    struct Liczba st;
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    int n = size / sizeof(struct Liczba);
    fseek(fp, 0, 0);
    struct Liczba tab[n];
    fread(tab, sizeof(struct Liczba), n, fp);
    for (int i = 0; i < n; i++)
    {
        printf("Liczba 1 = %d\nLiczba 2 = %d\nZnak = %c\n", tab[i].liczba1, tab[i].liczba2, tab[i].znak);
    }
    printf("#############################################\n");
    //zamienia w kazdej strukturze liczba1 z liczba2 jesli znak jest rowny liczba dziesietna, zapisuje zmodifikowane struktury do pliku mod.dat
    FILE *fp2 = fopen("mod.dat", "w+b");
    if (fp2 == NULL)
    {
        printf("Nie udalo sie otworzyc pliku mod.dat\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (tab[i].znak >= '0' && tab[i].znak <= '9')
        {
            int temp = tab[i].liczba1;
            tab[i].liczba1 = tab[i].liczba2;
            tab[i].liczba2 = temp;
        }
        fwrite(&tab[i], sizeof(struct Liczba), 1, fp2);
    }
    //Odczyt mod.dat
    fseek(fp2, 0, 0);
    struct Liczba tab2[n];
    fread(tab2, sizeof(struct Liczba), n, fp2);
    for (int i = 0; i < n; i++)
    {
        printf("Mod liczba 1 = %d\nMod liczba 2 = %d\nMod znak = %c\n", tab2[i].liczba1, tab2[i].liczba2, tab2[i].znak);
    }
    fclose(fp2);
    fclose(fp);
    return 0;
}

void utworzPlik(int n)
{
    FILE *fp;
    fp = fopen("liczby.dat", "w+b");
    if (fp == NULL)
    {
        printf("Nie udalo sie otworzyc pliku liczby.dat\n");
        exit(1);
    }
    struct Liczba st;
    for (int i = 0; i < n; i++)
    {
        st = wczytajStrukture();
        fwrite(&st, sizeof(struct Liczba), 1, fp);
    }
    fclose(fp);
}

struct Liczba wczytajStrukture(void)
{
    struct Liczba st;
    printf("Podaj liczbe 1: ");
    scanf("%d", &st.liczba1);
    printf("Podaj liczbe 2: ");
    scanf("%d", &st.liczba2);
    printf("Podaj znak: ");
    fflush(stdin);
    st.znak = getchar();
    return st;
}