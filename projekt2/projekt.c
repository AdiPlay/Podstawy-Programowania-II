/*Prototyp minibazy ver. 2
 Wprowadzone modyfikacje:
– zmienione menu główne
– funkcja wczytywanie nazwy pliku,
 wczytywanieNazwyBazy()
– zmodyfikowane sortowanie
– funkcja usuwania struktury
 ( dokładniejsza ilustracja działania jest w
 pliku testu usuwania struktury)
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <fcntl.h>
#include <io.h>
#define ESC 27
#define MAX_DRIVERS 100
struct F1 {
    int nrKierowcy;
    char imie[20];
    char nazwisko[20];
    int rokDebiutu;
    int liczbaZwyciestw;
    int liczbaMistrzostw;
    char narodowosc[20];
};
struct F1 st[MAX_DRIVERS];
void gotoxy(short x, short y);
FILE *fp1 = NULL, *fp2 = NULL;
char *tryb1, *tryb2;
char nazwaBazy[11] = "";
char nazwaBazyotwartej[11] = "";
char menu(void);
void gotoxy(short x, short y);
void utworzBaze(void);
void otworzBaze(void);
void usunBaze(void);
void przegladBazy(int);
void sortowanieBazy();
void drukujStrukt(struct F1 st);
struct F1 wczytajStrukt(void);
void wczytywanieNazwyBazy(void);
void drukujStatus(void);
double zwrocPoleStruktDouble(int nrPola, struct F1 st);
void zwrocPoleStruktLan(int nrPola, struct F1 st, char s[]);
int main(int argc, char *argv[])
{
    while (1)
    {
        system("cls");
        menu();
    }

    if (fp1)
        fclose(fp1);
    if (fp2)
        fclose(fp2);
    printf("\n Zakonczenie programu");
    getchar();
    return 0;
}
char menu(void)
{
    // funkcja wyswietla glówne menu i zwraca numer wybranej opcji
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
    printf("3. Usun baze");
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
        otworzBaze();
        przegladBazy(1);
        break;
    case '2':
        gotoxy(20, 18);
        printf(" Wybrano opcja 2 - Enter ");
        utworzBaze();
        przegladBazy(2);
        break;
    case '3':
        gotoxy(20, 18);
        printf(" Wybrano opcja 3 - Enter ");
        usunBaze();
        break;
    case '4':
        gotoxy(20, 18);
        printf(" Wybrano opcja 4 - Enter ");
        getchar();
        exit(0);
    }
}
void przegladBazy(int wybor)
{
    // Funkcję należy uzupełnić o działania konieczne do wykonania
    // przy wyborze danej opcji
    struct F1 st;
    int x = 1, y = 24;
    int liczbaKierowcow = 0;
    char ch;
    system("cls");
    gotoxy(x, y);
    printf("Metoda przegladBazy");
    drukujStatus();

    while (1)
    {
        drukujStatus();
        do
        {
            fflush(stdin);
            ch = toupper(getch());
        } while (ch != 'Y' && ch != 'B' && ch != 'G' && ch != 'H' && ch != 'R' && ch != 'M' && ch != 'S' && ch != 'D' && ch!= 'P' && ch != ESC);
        switch (ch)
        {
        case 'Y':
            gotoxy(20, 18);
            printf(" Wybrano opcja Y - Enter");
            // getchar();
            break;
        case 'B':
            gotoxy(20, 18);
            printf(" Wybrano opcja B - Enter ");
            break;
        case 'G':
            gotoxy(20, 18);
            printf(" Wybrano opcja G - Enter ");
            break;
        case 'H':
            gotoxy(20, 18);
            printf(" Wybrano opcja H - Enter ");
            // getchar();
            break;
        case 'S':
            gotoxy(20, 18);
            printf(" Wybrano opcja S - sortowanie Enter ");
            // getchar();
            break;
        case 'R':
            gotoxy(20, 18);
            // printf(" Wybrano opcja R - Enter ");
            st = wczytajStrukt();
            drukujStrukt(st);
            // drukujStatus();
            getchar();
            break;
        case 'M':
            gotoxy(20, 18);
            printf(" Wybrano opcja M - Enter ");
            // getchar();
            break;
        case 'D': // opcja usuwania aktualnie
            // wyświetlanej struktury
            gotoxy(20, 18);
            printf(" Wybrano opcja D - Enter ");
            break;
        case 'P':
            gotoxy(20, 18);
            printf(" Wybrano opcja P - Enter ");
            zapiszDoPliku(drivers, liczbaKierowcow);
            break;
        case ESC:
            gotoxy(20, 18);
            printf(" Wybrano opcja ESC - Menu ");
            return; // powrót do głównego menu
        }
    }
    return;
}
void utworzBaze(void)
{ // Funkcja tworzaca nowy plik bazy
    char nazwa[5];
    int i, licz = 0, ok, ok1 = 0, ok2 = 0, ok3 = 0;
    int x = 20, y = 20;
    system("cls");
    gotoxy(x, y);
    printf(" Metoda utworzBaze - enter");
    wczytywanieNazwyBazy();
    if (fp1 != NULL)
    {
        printf("\n Nowego pliku minibazy %s nie mozna utworzyc ",
               nazwaBazy);
        printf("\njesli inny plik minibazy jest otwarty");
        getchar();
        return;
    }
    fp1 = fopen(nazwaBazy, "w+b");

    if (fp1 == NULL)
        printf("\n Plik %s nie zostal utworzony", nazwaBazy);
    else
        printf("\n Nowy plik %s zostal utworzony", nazwaBazy);
    getchar();
    return;
}
void otworzBaze(void)
{ // Funkcja otwierajaca baze
    char nazwaBazy[11];
    int i, licz = 0, ok, ok1 = 0, ok2 = 0, ok3 = 0;
    int x = 20, y = 20;
    system("cls");
    gotoxy(x, y);
    printf(" Metoda otworzBaze");
    wczytywanieNazwyBazy();
    if (fp1 != NULL)
    {
        printf("\n Pliku minibazy %s nie mozna otworzyc ",
               nazwaBazy);
        printf("\njesli inny plik minibazy jest otwarty");
        getchar();
        return;
    }
    fp1 = fopen(nazwaBazy, "a+b");
    if (fp1 == NULL)
        printf("\n Plik %s nie zostal utworzony", nazwaBazy);
    else
        printf("\n Nowy plik %s zostal utworzony", nazwaBazy);
    getchar();
}
void usunBaze(void)
{
    char nazwa[5];
    int x = 20, y = 20, wynik;
    system("cls");
    gotoxy(x, y);
    printf(" Metoda usunBaze");
    wczytywanieNazwyBazy();
    gotoxy(x, 22);
    fp1 = fopen(nazwaBazy, "rb");
    if (fp1 == NULL)
        printf("\n Plik %s nie moze byc usuniety", nazwaBazy);
    else
    {
        fclose(fp1);
        wynik = remove(nazwaBazy);
        if (wynik)
            printf(" Plik zostal usuniety");
        else
            printf(" Plik nie zostal usuniety");
    }

    return;
}

void gotoxy(short x, short y)
{ // definicja funkcji gotoxy
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void sortowanieBazy(void)
{
    int x = 20, y = 20;
    system("cls");
    gotoxy(x, y);
    printf(" Metoda sortujBaze");
    getchar();
    return;
}

void drukujStrukt(struct F1 st)
{
    int x = 20, y = 8;
    system("cls");
    gotoxy(x, y);
    printf("Nr Kierowcy:%d", st.nrKierowcy);
    gotoxy(x, y + 1);
    printf("Imie:%s", st.imie);
    gotoxy(x, y + 2);
    printf("Nazwisko:%s", st.nazwisko);
    gotoxy(x, y + 3);
    printf("Rok Debiutu" , st.rokDebiutu);
    gotoxy(x, y + 4);
    printf("Liczba Zwyciestw:%d", st.liczbaZwyciestw);
    gotoxy(x, y + 5);
    printf("Liczba Mistrzostw:%d", st.liczbaMistrzostw);
    gotoxy(x, y + 6);
    printf("Narodowosc:%s", st.narodowosc);
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
    drukujStatus();
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
    printf("Liczba Zwyciestw:");
    scanf("%d", &st.liczbaZwyciestw);
    fflush(stdin);
    gotoxy(x, y + 5);
    printf("Liczba Mistrzostw:");
    scanf("%d", &st.liczbaMistrzostw);
    fflush(stdin);
    gotoxy(x, y + 6);
    printf("Narodowosc:");
    scanf("%s", st.narodowosc);
    return st;
}
void drukujStatus(void)
{
    gotoxy(1, 24);
    printf("Y-up B-down G-Home H-End R-read M-modify S-sort D-del ESC-exit P-Save");
}
void wczytywanieNazwyBazy(void)
{
    char nazwa[5];
    int ok, ok1, ok2, ok3;
    int i, licz = 0;
    do
    {
        printf("\n Podaj nazwe bazy format XXXXdd.dat:");
        scanf("%11s", nazwaBazy);
        strcpy(nazwa, nazwaBazy + 6);
        // printf("\n nazwa:%s", nazwa);
        if (strcmp(nazwa, ".dat") == 0)
            ok1 = 1;
        // printf("\n ok1=%d",ok1);
        fflush(stdin);
        for (i = 0; i < 4; i++)
            if (isalpha(nazwaBazy[i]))
                licz++;
        if (licz == 4)
            ok2 = 1;
        // printf("\n ok2=%d",ok2);
        fflush(stdin);
        for (i = 4, licz = 0; i <= 5; i++)
            if (isdigit(nazwaBazy[i]))
                licz++;
        if (licz == 2)
            ok3 = 1;
        ok = ok1 * ok2 * ok3;
        if (ok)
            printf("\n nazwa bazy jest prawidlowa");
        else
            printf("\n nazwa bazy nie jest prawidlowa");

    } while (ok == 0);
}

void sortuj(FILE *fp, int nrPola)
{
    printf("\n Sortowanie");
    struct F1 bufs1, bufs2;
    int i, n = 4, zam;
    char s1[20], s2[20];
    char nazwa[25];
    int nrKierowcy;
    char typ[25];
    char producent[25];
    double cenaNetto;
    int VAT;
    double cenaBrutto;
    switch (nrPola)
    {
    case 1:
        printf("\n Sortowanie wg nazwy"); // char *
        break;
    case 2:
        printf("\n Sortowanie wg nrKierowcya"); // int
        break;
    case 3:
        printf("\n wg typu"); // char *
        break;
    case 4:
        printf("\n wg producenta"); // char *
        break;
    case 5:
        printf("\n Sortowanie wg ceny netto"); // double
        break;
    case 6:
        printf("\n Sortowanie wg VAT"); // int
        break;
    case 7:
        printf("\n Sortowanie wg ceny brutto"); // double
    }
    if (nrPola == 1 || nrPola == 3 || nrPola == 4)
    {
        do
        {
            zam = 0;
            for (i = 0; i < n - 1; i++)
            {
                fseek(fp, i * sizeof(struct F1), SEEK_SET);
                fread(&bufs1, sizeof(struct F1), 1, fp);
                fread(&bufs2, sizeof(struct F1), 1, fp);
                zwrocPoleStruktLan(nrPola, bufs1, s1);
                zwrocPoleStruktLan(nrPola, bufs1, s2);
                if (strcmp(s1, s2) > 0)
                {
                    fseek(fp, i * sizeof(struct F1), SEEK_SET);
                    fwrite(&bufs2, sizeof(struct F1), 1, fp);
                    fwrite(&bufs1, sizeof(struct F1), 1, fp);
                    zam = 1;
                } // if2
            }     // for
        }         // do
        while (zam);
    } // if1
    int p1, p2;
    if (nrPola == 2 || nrPola == 6)
    {
        do
        {
            zam = 0;
            for (i = 0; i < n - 1; i++)
            {
                fseek(fp, i * sizeof(struct F1), SEEK_SET);
                fread(&bufs1, sizeof(struct F1), 1, fp);
                fread(&bufs2, sizeof(struct F1), 1, fp);
                p1 = zwrocPoleStruktInt(nrPola, bufs1);
                p2 = zwrocPoleStruktInt(nrPola, bufs2);
                if (p1 > p2)
                {
                    fseek(fp, i * sizeof(struct F1), SEEK_SET);
                    fwrite(&bufs2, sizeof(struct F1), 1, fp);
                    fwrite(&bufs1, sizeof(struct F1), 1, fp);
                    zam = 1;
                } // if2
            }     // for
            // do
        } while (zam);
    }
    return;
}
void zwrocPoleStruktLan(int nrPola, struct F1 st, char s[])
{
    if (nrPola == 2)
        strcpy(s, st.imie);
    if (nrPola == 3)
        strcpy(s, st.nazwisko);
    if (nrPola == 4)
        strcpy(s, st.narodowosc);
}
int zwrocPoleStruktInt(int nrPola, struct F1 st)
{
    if (nrPola == 6)
        return st.liczbaZwyciestw;
    if (nrPola == 1)
        return st.nrKierowcy;
    if (nrPola == 7)
        return st.liczbaMistrzostw;
    
}

void usuwanieStrukturyZbazy(void)
{
    struct F1 bufs; // definicja pomocniczej struktury bufs
    fpos_t nrRek;
    int aktPozycjaWskaznikaPliku;
    int rozmiarPlikBajty;
    fgetpos(fp1, &nrRek); // zapis aktualnej pozycji wskaźnika plikuprzed
    // ustawieniem wskaźnika pliku przed ostatnią strukturą w pliku
    //-------------------------------------------------------

    fseek(fp1, -1 * sizeof(struct F1), SEEK_END); // ustawieniewskaźnika pliku
                                                       // przed ostatniąstrukturą w pliku

    fread(&bufs, sizeof(struct F1), 1, fp1); // odczyt ostatniejstruktury

    fsetpos(fp1, &nrRek);                          // ustawienie wskaźnika pliku po usuwanejstrukturze
    fseek(fp1, -sizeof(struct F1), SEEK_CUR); // cofnięciewskaźnika
    fwrite(&bufs, sizeof(struct F1), 1, fp1); // zapis ostatniejstruktury
    // w miejsce usuwanejaktPozycjaWskaznikaPliku = ftell(fp1);
    // Wyznaczenie aktualnego rozmiaru pliku
    fseek(fp1, 0, SEEK_END);
    rozmiarPlikBajty = ftell(fp1);
    fclose(fp1);
    int handle;
    handle = open(nazwaBazyotwartej, O_RDWR);
    if (handle != -1)
        printf("\n Plik zostal otwarty ");
    else
    {
        printf("\n Plik nie zostal otwarty");
        chsize(handle, rozmiarPlikBajty - sizeof(struct F1));
        close(handle);
    }
    // Funkcja chsize obcina plik do zadanej długości w bajtach.
    fp1 = fopen(nazwaBazyotwartej, "r+b");
    fseek(fp1, aktPozycjaWskaznikaPliku, SEEK_SET);
}

void zapiszDoPliku(struct F1 *drivers, int numDrivers)
{
    char filename[100];
    int x = 20, y = 8;
    //clearScreen();
    //showDatFiles();
    gotoxy(x, y - 2);
    printf("Zapisz dane do pliku");
    gotoxy(x, y);
    printf("Podaj nazwe pliku: ");
    scanf("%s", filename);
    if (strstr(filename, ".dat") == NULL)
    {
        strcat(filename, ".dat");
    }
    FILE *fp1;
    fp1 = fopen(filename, "wb");
    if (fp1 == NULL)
    {
        printf("Nie moge otworzyc pliku do zapisu!\n");
        exit(1);
    }
    fwrite(drivers, sizeof(struct F1), numDrivers, fp1);
    fclose(fp1);
    printf("Dane zostaly zapisane do pliku %s!\n", filename);
}