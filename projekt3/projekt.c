#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <stdbool.h>
#include <dirent.h>

#define ESC 27

struct F1
{
    int nrKierowcy;
    char imie[20];
    char nazwisko[20];
    int rokDebiutu;
    int liczbaMistrzostw;
    int liczbaZwyciestw;
    char narodowosc[20];
};

void sortowanie(struct F1 drivTab[]);
void gotoxy(short x, short y);
FILE *fp1, *fp2;
char *tryb1, *tryb2;
int drivers;
char nazwaBazy[11];
int ifExists = 0;
char menu(void);
void utworzBaze(void);
void usunBaze(void);
void przegladBazy(struct F1 drivTab[]);
void drukujStrukt(const char *fileName, int index, struct F1 drivTab[]);
struct F1 wczytajStrukt(void);
void drukujStatus(void);
void showDatFiles();

int main(int argc, char *argv[])
{
    menu();
    // utworzBaze();
    getchar();
    return 0;
}
bool checkFileExists(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file != NULL)
    {
        fclose(file);
        return true;
    }
    return false;
}

void modyfikacja(struct F1 st[], int numer, int ns)
{
    fflush(stdin);
    system("cls");
    if (numer == 0)
    {
        printf("Nr Kierowcy:");
        scanf("%d", &st[ns].nrKierowcy);
    }

    if (numer == 1)
    {
        printf("Imie:");
        scanf("%s", st[ns].imie);
    }

    if (numer == 2)
    {
        printf("Nazwisko:");
        scanf("%s", st[ns].nazwisko);
    }

    if (numer == 3)
    {
        printf("Rok Debiutu:");
        scanf("%d", &st[ns].rokDebiutu);
    }

    if (numer == 4)
    {
        printf("Liczba Mistrzostw:");
        scanf("%d", &st[ns].liczbaMistrzostw);
    }

    if (numer == 5)
    {
        printf("Liczba Zwyciestw:");
        scanf("%d", &st[ns].liczbaZwyciestw);
    }
    if (numer == 6)
    {
        printf("Narodowosc:");
        scanf("%s", st[ns].narodowosc);
    }
    printf("Zmodyfikowano strukture o indeksie %d.\n", ns);
    getchar();
    getchar();
    return;
}
void modify(struct F1 drivTab[], int ns)
{
    char ch;
    int ile = 0;

rewind:
    system("cls");
    printf("G - LEFT J - RIGHT U - UPDATE ESC - EXIT \n");
    printf("Nr Kierowcy: %d , Imie: %s, Nazwisko: %s, Rok Debiutu: %d, Liczba Mistrzostw: %d, Liczba Zwyciestw: %d Narodowsc: %s, \n",
           drivTab[ns].nrKierowcy, drivTab[ns].imie, drivTab[ns].nazwisko, drivTab[ns].rokDebiutu, drivTab[ns].liczbaMistrzostw, drivTab[ns].liczbaZwyciestw, drivTab[ns].narodowosc);

    if (ile == 0)
        gotoxy(0, 2);
    if (ile == 1)
        gotoxy(22, 2);
    if (ile == 2)
        gotoxy(39, 2);
    if (ile == 3)
        gotoxy(49, 2);
    if (ile == 4)
        gotoxy(74, 2);
    if (ile == 5)
        gotoxy(98, 2);
    if (ile == 6)
        gotoxy(118, 2);
    if (ile == 7)
        printf("^");
    printf("^");
    do
    {
        fflush(stdin);
        ch = toupper(getch());
    } while (ch != 'J' && ch != 'G' && ch != 'U' && ch != ESC);

    switch (ch)
    {
    case 'J':
        if (ile < 6)
            ile++;
        goto rewind;
        break;
    case 'G':
        if (ile >= 0)
            ile--;
        goto rewind;
        break;
    case 'U':
        modyfikacja(drivTab, ile, ns);
        goto rewind;
        break;
    case ESC:
        printf(" Wybrano opcja ESC - Enter ");
        getchar();
        return;
        break;
    }
    return;
}

void usunStrukture(struct F1 tab[], int index, int *size)
{
    for (int i = index; i < *size - 1; i++)
    {
        tab[i] = tab[i + 1];
    }
    (*size)--;
    printf("Usunieto element o indeksie %d.\n", index);
    getchar();
}
void utworzBaze(void)
{ // Funkcja tworzaca
    char nazwaBazy[11], nazwa[5];
    int i, licz = 0, ok, ok1 = 0, ok2 = 0, ok3 = 0;
    int x = 20, y = 20;
    system("cls");
    gotoxy(x - 5, y - 5);
    showDatFiles();
    gotoxy(x, y);
    printf(" Metoda utworzBaze");
    getchar();
    do
    { // nowy plik
        printf("\n Podaj nazwe bazy format XXXXdd.dat:");
        scanf("%11s", nazwaBazy);
        strcpy(nazwa, nazwaBazy + 6);
        printf("\n nazwa:%s", nazwa);
        if (strcmp(nazwa, ".dat") == 0)
            ok1 = 1;
        printf("\n ok1=%d", ok1);
        fflush(stdin);
        getchar();
        for (i = 0; i < 4; i++)
            if (isalpha(nazwaBazy[i]))
                licz++;
        if (licz == 4)
            ok2 = 1;
        printf("\n ok2=%d", ok2);
        fflush(stdin);
        getchar();
        for (i = 4, licz = 0; i <= 5; i++)
            if (isdigit(nazwaBazy[i]))
                licz++;
        if (licz == 2)
            ok3 = 1;
        printf("\n ok2=%d", ok2);
        ok = ok1 * ok2 * ok3;
        if (ok)
        {
            printf("\n nazwa bazy jest prawidlowa");
            getchar();
        }
        else
            printf("\n nazwa bazy nie jest prawidlowa");
        getchar();
    }

    while (ok == 0);

    if (checkFileExists(nazwaBazy))
    {
        printf("\nPlik istnieje.\n");
        getchar();
    }
    else
    {
        fp1 = fopen(nazwaBazy, "w+b");
    }

    if (fp1 == NULL)
    {
        printf("\n Plik %s nie zostal utworzony", nazwa);

        getchar();
        system("cls");
        menu();
    }
    else
    {
        printf("\n Plik %s zostal utworzony poprawnie", nazwa);
        getchar();
        system("cls");
        menu();
    }
}

int saveQuit(struct F1 drivTab[])
{
    char ch;
    printf("Czy chcesz zapisac? \n T - TAK | N - NIE");
    do
    {
        fflush(stdin);
        ch = toupper(getch());
    } while (ch != 'T' && ch != 'N');
    switch (ch)
    {
    case 'T':
        printf("\nZapisywanie...");
        fclose(fp1);
        fp1 = fopen(nazwaBazy, "wb");
        fwrite(drivTab, sizeof(struct F1), drivers, fp1);
        fclose(fp1);
        fp1 = fopen(nazwaBazy, "a+b");
        getchar();
        break;
    case 'N':
        printf("\nOdmowa zapisu");
        getchar();
        break;
    }

    printf("Zamknac baze? \n T - TAK | N - NIE");
    do
    {
        fflush(stdin);
        ch = toupper(getch());
    } while (ch != 'T' && ch != 'N');
    switch (ch)
    {
    case 'T':
        printf("\nZamykam");
        fclose(fp1);
        for (int i = 0; i < drivers; i++)
        {
            memset(&drivTab[i], 0, sizeof(struct F1));
        }
        ifExists = 0;
        getchar();
        return 1;
        break;
    case 'N':
        printf("\nNie zamykam");
        getchar();
        return 0;
        break;
    }
}

void otworzBaze(struct F1 drivTab[])
{ // Funkcja otwierajaca baze
    char nazwa[5];
    int i, licz = 0, ok, ok1 = 0, ok2 = 0, ok3 = 0;
    int x = 20, y = 20;
    system("cls");
    gotoxy(x - 5, y - 5);
    showDatFiles();
    gotoxy(x, y);
    printf(" Metoda otworzBaze");
    do
    { // nowy plik
        printf("\n Podaj nazwe bazy format XXXXdd.dat:");
        scanf("%11s", nazwaBazy);
        strcpy(nazwa, nazwaBazy + 6);
        printf("\n nazwa:%s", nazwa);
        if (strcmp(nazwa, ".dat") == 0)
            ok1 = 1;
        printf("\n ok1=%d", ok1);
        fflush(stdin);
        getchar();
        for (i = 0; i < 4; i++)
            if (isalpha(nazwaBazy[i]))
                licz++;
        if (licz == 4)
            ok2 = 1;
        printf("\n ok2=%d", ok2);
        fflush(stdin);
        getchar();
        for (i = 4, licz = 0; i <= 5; i++)
            if (isdigit(nazwaBazy[i]))
                licz++;
        if (licz == 2)
            ok3 = 1;
        printf("\n ok3=%d", ok2);
        ok = ok1 * ok2 * ok3;
        if (ok)
            printf("\n nazwa bazy jest prawidlowa");
        else
            printf("\n nazwa bazy nie jest prawidlowa");
    } while (ok == 0);
    fp1 = fopen(nazwaBazy, "a+b");

    if (fp1 == NULL)
    {
        printf("\n Plik %s nie zostal otworzony", nazwa);
        getchar();
        system("cls");
        menu();
    }
    else
    {
        printf("\n Otworzono plik %s", nazwa);
        drivers = 0;
        ifExists = 1;
        while (drivers < 1000 && fread(&drivTab[drivers], sizeof(struct F1), 1, fp1) == 1)
        {
            drivers++;
        }
        getchar();
        przegladBazy(drivTab);
    }
}

void usunBaze(void)
{
    char nazwaBazy[11], nazwa[5];
    int i, licz = 0, ok, ok1 = 0, ok2 = 0, ok3 = 0;
    int x = 20, y = 20, wynik;
    system("cls");
    gotoxy(x - 5, y - 5);
    showDatFiles();
    gotoxy(x, y);
    printf(" Metoda usunBaze");
    do
    { // nowy plik

        printf("\n Podaj nazwe bazy format XXXXdd.dat:");
        scanf("%11s", nazwaBazy);
        strcpy(nazwa, nazwaBazy + 6);
        printf("\n nazwa:%s", nazwa);
        if (strcmp(nazwa, ".dat") == 0)
            ok1 = 1;
        printf("\n ok1=%d", ok1);
        fflush(stdin);
        getchar();
        for (i = 0; i < 4; i++)
            if (isalpha(nazwaBazy[i]))
                licz++;
        if (licz == 4)
            ok2 = 1;
        printf("\n ok2=%d", ok2);
        fflush(stdin);
        getchar();
        for (i = 4, licz = 0; i <= 5; i++)
            if (isdigit(nazwaBazy[i]))
                licz++;
        if (licz == 2)
            ok3 = 1;
        printf("\n ok3=%d", ok2);
        ok = ok1 * ok2 * ok3;
        if (ok)
            printf("\n nazwa bazy jest prawidlowa");
        else
            printf("\n nazwa bazy nie jest prawidlowa");

    } while (ok == 0);

    gotoxy(x, 22);
    fclose(fp1);
    fp1 = fopen(nazwaBazy, "rb");
    if (fp1 == NULL)
        printf("\n Plik %s nie moze byc usuniety", nazwaBazy);
    else
    {
        fclose(fp1);
        wynik = remove(nazwaBazy);
        if (wynik == 0)
            printf(" Plik zostal usuniety");
        else
            printf(" Plik nie zostal usuniety");
    }
    getchar();
    return;
}

char menu(void)
{
    struct F1 drivTab[1000];
    while (1)
    {
    menu:
        system("cls");

        char ch;
        int x, y;
        x = 20;
        y = 8;
        gotoxy(x, y);
        printf("============================");
        gotoxy(x, y + 1);
        printf("1.Otworz baze danych");
        gotoxy(x, y + 2);
        printf("2.Utworz nowa baze");
        gotoxy(x, y + 3);
        printf("3.Usun baze");
        gotoxy(x, y + 4);
        printf("4.Zakoncz program");
        gotoxy(x, y + 5);
        printf(" Wybierz opcje :");
        fflush(stdin);
        do
        {
            fflush(stdin);
            ch = getch();
        } while (ch != '1' && ch != '2' && ch != '3' && ch != '4');
        switch (ch)
        {
        case '1':
            gotoxy(20, 18);
            printf(" Wybrano opcja 1 - Enter");
            getchar();
            if (ifExists == 1)
            {
                if (saveQuit(drivTab) == 0)
                    goto menu;
            }
            otworzBaze(drivTab);
            break;
        case '2':
            gotoxy(20, 18);
            printf(" Wybrano opcja 2 - Enter ");
            if (ifExists == 1)
            {
                if (saveQuit(drivTab) == 0)
                    goto menu;
            }
            utworzBaze();
            break;
        case '3':
            gotoxy(20, 18);
            printf(" Wybrano opcja 3 - Enter ");
            if (ifExists == 1)
            {
                if (saveQuit(drivTab) == 0)
                    goto menu;
            }
            usunBaze();
            break;
        case '4':
            gotoxy(20, 18);
            printf(" Wybrano opcja 4 - Enter ");
            getchar();
            if (ifExists == 1)
            {
                if (saveQuit(drivTab) == 0)
                    goto menu;
            }
            exit(0);
        }
    }
}
void gotoxy(short x, short y)
{ // definicja funkcji gotoxy
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void przegladBazy(struct F1 drivTab[])
{
    int numer = 0;
    struct F1 st;
    int x = 1, y = 24;
    char ch;
baseMenu:
    system("cls");
    gotoxy(x, y);
    drukujStrukt((FILE *)fp1, numer, drivTab);
    printf("Y - UP | B- DOWN | G - HOME | H - END | D - ADD | U - DELETE | M - MODIFY | S - SORT | ESC - EXIT");
    do
    {
        fflush(stdin);
        ch = toupper(getch());
    } while (ch != 'B' && ch != 'Y' && ch != 'G' && ch != 'H' && ch != 'D' && ch != 'U' && ch != 'M' && ch != 'S' && ch != ESC);
    switch (ch)
    {
    case 'Y':
        printf(" Wybrano opcja Y - Enter");
        if (numer != 0)
            numer--;
        goto baseMenu;
        getchar();
        break;
    case 'B':
        printf(" Wybrano opcja B - Enter");
        if (numer <= drivers)
            numer++;
        goto baseMenu;
        getchar();
        break;
    case 'G':
        gotoxy(20, 18);
        printf(" Wybrano opcja G - Enter ");
        numer = 0;
        goto baseMenu;
        break;
    case 'H':
        gotoxy(20, 18);
        printf(" Wybrano opcja H - Enter ");
        numer = drivers - 1;
        goto baseMenu;
        getchar();
        break;
    case 'D':
        gotoxy(20, 18);
        printf(" Wybrano opcja D - Enter ");
        drivTab[drivers] = wczytajStrukt();
        drivers++;
        goto baseMenu;
        getchar();
        break;
    case 'U':
        gotoxy(20, 18);
        printf(" Wybrano opcja U - Enter ");
        usunStrukture(drivTab, numer, &drivers);
        goto baseMenu;
        break;
    case 'M':
        gotoxy(20, 18);
        printf(" Wybrano opcja M - Enter ");
        modify(drivTab, numer);
        goto baseMenu;
        break;
    case 'S':
        gotoxy(20, 18);
        printf(" Wybrano opcja S - Enter ");
        sortowanie(drivTab);
        goto baseMenu;
        // getchar();
        break;
    case ESC:
        gotoxy(20, 18);
        printf(" Wybrano opcja ESC - Enter ");
        getchar();
        return;
        break;
    }

    return;
}

void sortowanie(struct F1 drivTab[])
{
    int nrKierowcy;
    char imie[20];
    char nazwisko[20];
    int identyfikator;
    int rokDebiutu;
    int liczbaMistrzostw;
    int liczbaZwyciestw;
    char narodowosc[20];
    char ch;
    system("cls");
    int i;
    printf("\n Pola bazy");
    printf("\n 1. Nr kierowcy");
    printf("\n 2. Imie");
    printf("\n 3. Nazwisko");
    printf("\n 4. Rok debiutu");
    printf("\n 5. Liczba mistrzostw");
    printf("\n 6. Liczba zwyciestw ");
    printf("\n 7. Narodowosc");
    printf("\n Podaj numer pola, wg ktorego baza bedzie sortowana: ");
    do
    {
        ch = getch();
    }

    while (ch != '1' && ch != '2' && ch != '3' && ch != '4' && ch != '5' && ch != '6' && ch != '7');

    if (ch == '1')
    {
        printf("\n Wybrano sortowanie wg nr kierowcy - opcja 1");
        // Sortowanie wg nrKierowcy
        for (i = 0; i < drivers - 1; i++)
        {
            for (int j = 0; j < drivers - i - 1; j++)
            {
                if (drivTab[j].nrKierowcy > drivTab[j + 1].nrKierowcy)
                {
                    struct F1 temp = drivTab[j];
                    drivTab[j] = drivTab[j + 1];
                    drivTab[j + 1] = temp;
                }
            }
        }
    }

    if (ch == '2')
    {
        printf("\n Wybrano sortowanie wg imienia - opcja 2");
        // Sortowanie wg imie
        for (i = 0; i < drivers - 1; i++)
        {
            for (int j = 0; j < drivers - i - 1; j++)
            {
                if (strcmp(drivTab[j].imie, drivTab[j + 1].imie) > 0)
                {
                    struct F1 temp = drivTab[j];
                    drivTab[j] = drivTab[j + 1];
                    drivTab[j + 1] = temp;
                }
            }
        }
    }

    if (ch == '3')
    {
        printf("\n Wybrano sortowanie wg nazwiska - opcja 3");
        // Sortowanie wg nazwisko
        for (i = 0; i < drivers - 1; i++)
        {
            for (int j = 0; j < drivers - i - 1; j++)
            {
                if (strcmp(drivTab[j].nazwisko, drivTab[j + 1].nazwisko) > 0)
                {
                    struct F1 temp = drivTab[j];
                    drivTab[j] = drivTab[j + 1];
                    drivTab[j + 1] = temp;
                }
            }
        }
    }

    if (ch == '4')
    {
        printf("\n Wybrano sortowanie wg roku debiutu - opcja 4");
        // Sortowanie wg rokDebiutu
        for (i = 0; i < drivers - 1; i++)
        {
            for (int j = 0; j < drivers - i - 1; j++)
            {
                if (drivTab[j].rokDebiutu > drivTab[j + 1].rokDebiutu)
                {
                    struct F1 temp = drivTab[j];
                    drivTab[j] = drivTab[j + 1];
                    drivTab[j + 1] = temp;
                }
            }
        }
    }

    if (ch == '5')
    {
        printf("\n Wybrano sortowanie wg liczby mistrzostw - opcja 5");
        // Sortowanie wg liczbaMistrzostw
        for (i = 0; i < drivers - 1; i++)
        {
            for (int j = 0; j < drivers - i - 1; j++)
            {
                if (drivTab[j].liczbaMistrzostw > drivTab[j + 1].liczbaMistrzostw)
                {
                    struct F1 temp = drivTab[j];
                    drivTab[j] = drivTab[j + 1];
                    drivTab[j + 1] = temp;
                }
            }
        }
    }

    if (ch == '6')
    {
        printf("\n Wybrano sortowanie wg liczby zwyciestw - opcja 6");
        // Sortowanie wg liczbaZwyciestw
        for (i = 0; i < drivers - 1; i++)
        {
            for (int j = 0; j < drivers - i - 1; j++)
            {
                if (drivTab[j].liczbaZwyciestw > drivTab[j + 1].liczbaZwyciestw)
                {
                    struct F1 temp = drivTab[j];
                    drivTab[j] = drivTab[j + 1];
                    drivTab[j + 1] = temp;
                }
            }
        }
    }

    if (ch == '7')
    {
        printf("\n Wybrano sortowanie wg narodowosci - opcja 7");
        // Sortowanie wg narodowosc
        for (i = 0; i < drivers - 1; i++)
        {
            for (int j = 0; j < drivers - i - 1; j++)
            {
                if (strcmp(drivTab[j].narodowosc, drivTab[j + 1].narodowosc) > 0)
                {
                    struct F1 temp = drivTab[j];
                    drivTab[j] = drivTab[j + 1];
                    drivTab[j + 1] = temp;
                }
            }
        }
    }

    getchar();
    system("cls");
}

void drukujStrukt(const char *fileName, int index, struct F1 drivTab[])
{
    struct F1 rekord;
    int liczbaRekordow = 0;
    int numerRekordow = index;

    for (int i = index; i < index + 5; i++)
    {
        if (i < drivers)
        {

            printf("\n");
            if (i == index)
                printf("[\n");
            printf("Element: %d\nNr Kierowcy: %d\nImie: %s\nNazwisko: %s\nRok debiutu: %d\nLiczba mistrzostw: %d\nLiczba zwyciestw: %d\nNarodowosc: %s\n",
                   numerRekordow, drivTab[i].nrKierowcy, drivTab[i].imie, drivTab[i].nazwisko, drivTab[i].rokDebiutu, drivTab[i].liczbaMistrzostw, drivTab[i].liczbaZwyciestw, drivTab[i].narodowosc);
            if (i == index)
                printf("	]");
            printf("\n");
            numerRekordow++;
        }
    }
}

struct F1 wczytajStrukt(void)
{
    struct F1 st;
    fflush(stdin);
    int x = 20, y = 8;
    system("cls");
    gotoxy(x, y);
    fflush(stdin);
    printf("Nr Kierowcy:");
    scanf("%d", &st.nrKierowcy);
    gotoxy(x, y + 1);
    printf("Imie:");
    scanf("%s", st.imie);
    fflush(stdin);
    gotoxy(x, y + 2);
    printf("Nazwisko:");
    scanf("%s", st.nazwisko);
    fflush(stdin);
    gotoxy(x, y + 3);
    printf("Rok Debiutu:");
    scanf("%d", &st.rokDebiutu);
    fflush(stdin);
    gotoxy(x, y + 4);
    printf("Liczba Mistrzostw:");
    scanf("%d", &st.liczbaMistrzostw);
    gotoxy(x, y + 5);
    printf("Liczba Zwyciestw:");
    scanf("%d", &st.liczbaZwyciestw);
    fflush(stdin);
    gotoxy(x, y + 6);
    printf("Narodowosc:");
    scanf("%s", &st.narodowosc);
    return st;
}
void drukujStatus(void)
{
    gotoxy(1, 24);
    printf("Y-1 rec up B-1 rec down G-Home H-End R-read M-modify S - sort ESC-exit");
}

void dopiszDoBazy(const char *fileName, const struct F1 *rekord)
{
    FILE *plik = fopen(fileName, "a");
    if (plik == NULL)
    {
        printf("Nie można otworzyc pliku.\n");
        return;
    }

    fwrite(rekord, sizeof(struct F1), 1, plik);
    fclose(plik);
    printf("Dopisano!");
    getchar();
}

void showDatFiles()
{
    DIR *dir;
    struct dirent *ent;
    char *ext;
    dir = opendir(".");
    if (dir == NULL)
    {
        printf("Nie moge otworzyc katalogu!\n");
        return;
    }
    printf("Lista plikow .dat:\n");
    while ((ent = readdir(dir)) != NULL)
    {
        ext = strrchr(ent->d_name, '.');
        if (ext != NULL && strcmp(ext, ".dat") == 0)
        {
            printf("%s\n", ent->d_name);
        }
    }
    closedir(dir);
}
