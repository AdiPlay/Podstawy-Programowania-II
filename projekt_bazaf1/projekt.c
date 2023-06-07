#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>

#define ESC 27

struct F1
{
    int identyfikator;
    char imie[20];
    char nazwisko[20];
    int rokDebiutu;
    int liczbaMistrzostw;
    int liczbaZwyciestw;
    char narodowosc[20];
};

void gotoxy(short x, short y);
FILE *fp1, *fp2;
char *tryb1, *tryb2;
char menu(void);
void utworzBaze(void);
void usunBaze(void);
void przegladBaze(void);
void sortowanieBazy(void);
void drukujStrukt(struct F1 st);
struct F1 wczytajStrukt(void);
void drukujStatus(void);
int main(int argc, char *argv[])
{
    system("cls");
    menu();
    utworzBaze();
    getchar();
    return 0;
}

void utworzNowyPlik(char *nazwa, char *tryb)
{
    FILE *fp;
    if ((fp = fopen(nazwa, tryb)) == NULL)
    {
        printf("Nie moge otworzyc pliku %s.\n", nazwa);
        exit(1);
    }
}

void utworzBaze(void)
{ // Funkcja tworzaca
    char nazwaBazy[11], nazwa[5];
    int i, licz = 0, ok, ok1 = 0, ok2 = 0, ok3 = 0;
    int x = 20, y = 20;
    system("cls");
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
        printf("\n ok3=%d", ok3);
        ok = ok1 * ok2 * ok3;
        if (ok)
            printf("\n nazwa bazy jest prawidlowa");
        else
            printf("\n nazwa bazy nie jest prawidlowa");
        getchar();  
    } while (ok == 0);
    fp1 = fopen(nazwaBazy, "w+b");
    if (fp1 == NULL)
    {
        printf("\n Plik %s nie zostal utworzony", nazwa);

        getchar();
        exit(1);
    }
}

void otworzBaze(void)
{ // Funkcja otwierajaca baze
    char nazwaBazy[11], nazwa[5];
    int i, licz = 0, ok, ok1 = 0, ok2 = 0, ok3 = 0;
    int x = 20, y = 20;
    system("cls");
    gotoxy(x, y);
    printf(" Metoda otworzBaze");
    przegladBazy();
    getchar();
    return;
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
            printf("\n nazwa bazy jest prawidlowa");
        else
            printf("\n nazwa bazy nie jest prawidlowa");

    } while (ok == 0);
    fp1 = fopen(nazwaBazy, "a+b");
    if (fp1 == NULL)
    {
        printf("\n Plik %s nie zostal utworzony", nazwa);

        getchar();
        exit(1);
    }
    // przegladBazy();
}

void usunBaze(void)
{
    char nazwaBazy[11], nazwa[5];
    int i, licz = 0, ok, ok1 = 0, ok2 = 0, ok3 = 0;
    int x = 20, y = 20, wynik;
    system("cls");
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
        printf("\n ok2=%d", ok2);
        ok = ok1 * ok2 * ok3;
        if (ok)
            printf("\n nazwa bazy jest prawidlowa");
        else
            printf("\n nazwa bazy nie jest prawidlowa");
    } while (ok == 0);
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
    getchar();
    return;
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
        break;
    case '2':
        gotoxy(20, 18);
        printf(" Wybrano opcja 2 - Enter ");
        utworzBaze();
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
void gotoxy(short x, short y)
{ // definicja funkcji gotoxy
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void przegladBazy(void)
{
    struct F1 st;
    int x = 1, y = 24;
    char ch;
    system("cls");
    gotoxy(x, y);
    printf(" Metoda przegladBazy");
    drukujStatus();
    // gotoxy(1,24);
    // printf("Y-1 rec up B-1 rec down G-Home H -End R -read rec M-modify S - sort ESC -exit");
    while (1)
    {
        drukujStatus();
        do
        {
            fflush(stdin);
            ch = toupper(getch());
        } while (ch != 'Y' && ch != 'B' && ch != 'G' && ch != 'H' && ch != 'R' && ch != 'M' && ch != 'S' && ch != ESC);
        switch (ch)
        {
        case 'Y':
            gotoxy(20, 18);
            printf(" Wybrano opcja Y - Enter");
            getchar();
            otworzBaze();
            break;
        case 'B':
            gotoxy(20, 18);
            printf(" Wybrano opcja B - Enter ");
            utworzBaze();
            break;
        case 'G':
            gotoxy(20, 18);
            printf(" Wybrano opcja G - Enter ");
            usunBaze();
            break;
        case 'H':
            gotoxy(20, 18);
            printf(" Wybrano opcja H - Enter ");
            getchar();
            break;
        case 'R':
            gotoxy(20, 18);
            // printf(" Wybrano opcja R - Enter ");
            st = wczytajStrukt();
            drukujStrukt(st);
            drukujStatus();
            getchar();
            break;
        case 'M':
            gotoxy(20, 18);
            printf(" Wybrano opcja M - Enter ");
            getchar();
            break;
        case 'S':
            gotoxy(20, 18);
            printf(" Wybrano opcja S - Enter ");
            sortowanieBazy();
            // getchar();
            break;
        case ESC:
            gotoxy(20, 18);
            printf(" Wybrano opcja ESC - Enter ");
            getchar();
            exit(0);
            break;
        }
    }
    return;
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
// char imie[20];
// char nazwisko[20];
// int rokDebiutu;
// int liczbaMistrzostw;
// int liczbaZwyciestw;
// char narodowosc[20];
void drukujStrukt(struct F1 st)
{
    int x = 20, y = 8;
    system("cls");
    gotoxy(x, y);
    printf("Imie: %s", st.imie);
    gotoxy(x, y + 1);
    printf("Nazwisko: %s", st.nazwisko);
    gotoxy(x, y + 2);
    printf("Identyfikator: %d", st.identyfikator);
    gotoxy(x, y + 3);
    printf("Rok Debiutu: %d", st.rokDebiutu);
    gotoxy(x, y + 4);
    printf("Liczba Mistrzostw: %d", st.liczbaMistrzostw);
    gotoxy(x, y + 5);
    printf("Liczba Zwyciestw: %d", st.liczbaZwyciestw);
    gotoxy(x, y + 6);
    printf("Narodowosc: %s", st.narodowosc);
}
struct F1 wczytajStrukt(void)
{
    struct F1 st;
    fflush(stdin);
    int x = 20, y = 8;
    system("cls");
    gotoxy(x, y);
    fflush(stdin);
    printf("Imie: ");
    scanf("%s", st.imie);
    drukujStatus();
    fflush(stdin);
    gotoxy(x, y + 1);
    printf("Nazwisko: ");
    scanf("%s", st.nazwisko);
    fflush(stdin);
    gotoxy(x, y + 2);
    printf("Identyfikator: ");
    scanf("%d", &st.identyfikator);
    fflush(stdin);
    gotoxy(x, y + 3);
    printf("Rok Debiutu: ");
    scanf("%d", st.rokDebiutu);
    fflush(stdin);
    gotoxy(x, y + 4);
    printf("Liczba Mistrzostw: ");
    scanf("%d", st.liczbaMistrzostw);
    fflush(stdin);
    gotoxy(x, y + 5);
    printf("Liczba Zwyciestw: ");
    scanf("%d", &st.liczbaZwyciestw);
    gotoxy(x, y + 5);
    printf("Narodosc: ");
    scanf("%s", &st.narodowosc);
    return st;
}
void drukujStatus(void)
{
    gotoxy(1, 24);
    printf("Y-1 rec up B-1 rec down G-Home H-End R-read M-modify Ssort ESC-exit");
}