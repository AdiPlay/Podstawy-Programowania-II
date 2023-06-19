#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struktura danych
struct Dane {
    char imie[20];
    char nazwisko[20];
    int wiek;
};

// deklaracje funkcji
void wczytajStrukt(void);
void drukujStrukt(void);
void utworzBaze(void);
void otworzBaze(void);
void usunBaze(void);
void przegladBazy(void);
void dopiszStrukt(void);
void usunStrukt(void);
void sortowanieBazy(void);
void modyfikujStrukt(void);
void drukujStatus(void);
void gotoxy(short x, short y);
char menu(void);
char* wczytajNazweBazy(void);

// zmienne globalne
struct Dane* baza = NULL;
int liczbaRekordow = 0;
char* nazwaBazy = NULL;

int main() {
    char wybor;

    // główne menu
    do {
        wybor = menu();

        switch (wybor) {
            case '1':
                wczytajStrukt();
                break;
            case '2':
                drukujStrukt();
                break;
            case '3':
                utworzBaze();
                break;
            case '4':
                otworzBaze();
                break;
            case '5':
                usunBaze();
                break;
            case '6':
                przegladBazy();
                break;
            case '7':
                dopiszStrukt();
                break;
            case '8':
                usunStrukt();
                break;
            case '9':
                sortowanieBazy();
                break;
            case '0':
                printf("Koniec programu.\n");
                break;
            default:
                printf("Nieprawidlowy wybor.\n");
                break;
        }
    } while (wybor != '0');

    // zwolnienie pamięci
    free(baza);
    free(nazwaBazy);

    return 0;
}

void wczytajStrukt() {
    // TODO: implementacja wczytywania struktury danych
}

void drukujStrukt() {
    // TODO: implementacja drukowania struktury danych
}

void utworzBaze() {
    char* nazwa = wczytajNazweBazy();

    if (nazwa != NULL) {
        // zwolnienie pamięci poprzedniej bazy
        free(baza);

        // utworzenie nowej bazy
        baza = (struct Dane*) malloc(sizeof(struct Dane));
        liczbaRekordow = 0;
        nazwaBazy = nazwa;

        printf("Utworzono baze danych o nazwie %s.\n", nazwaBazy);
    }
}

void otworzBaze() {
    char* nazwa = wczytajNazweBazy();

    if (nazwa != NULL) {
        // zwolnienie pamięci poprzedniej bazy
        free(baza);

        // otwarcie nowej bazy
        FILE* plik = fopen(nazwa, "rb");

        if (plik != NULL) {
            // odczytanie liczby rekordów
            fread(&liczbaRekordow, sizeof(int), 1, plik);

            // odczytanie danych
            baza = (struct Dane*) malloc(liczbaRekordow * sizeof(struct Dane));
            fread(baza, sizeof(struct Dane), liczbaRekordow, plik);

            // zapisanie nazwy bazy
            free(nazwaBazy);
            nazwaBazy = nazwa;

            printf("Otworzono baze danych o nazwie %s.\n", nazwaBazy);
        } else {
            printf("Nie udalo sie otworzyc pliku.\n");
            free(nazwa);
        }
    }
}

void usunBaze() {
    if (nazwaBazy != NULL) {
        // usunięcie pliku z danymi
        remove(nazwaBazy);

        // zwolnienie pamięci bazy
        free(baza);
        baza = NULL;
        liczbaRekordow = 0;

        // zwolnienie pamięci nazwy bazy
        free(nazwaBazy);
        nazwaBazy = NULL;

        printf("Usunieto baze danych.\n");
    } else {
        printf("Nie wybrano bazy danych.\n");
    }
}

void przegladBazy() {
    // TODO: implementacja przeglądania bazy danych
}

void dopiszStrukt() {
    // TODO: implementacja dodawania struktury danych
}

void usunStrukt() {
    // TODO: implementacja usuwania struktury danych
}

void sortowanieBazy() {
    // TODO: implementacja sortowania bazy danych
}

void modyfikujStrukt() {
    // TODO: implementacja modyfikacji struktury danych
}

void drukujStatus() {
    printf("1. Wczytaj strukture danych\n");
    printf("2. Drukuj strukture danych\n");
    printf("3. Utworz baze danych\n");
    printf("4. Otworz baze danych\n");
    printf("5. Usun baze danych\n");
    printf("6. Przegladaj baze danych\n");
    printf("7. Dopisz strukture danych\n");
    printf("8. Usun strukture danych\n");
    printf("9. Sortuj baze danych\n");
    printf("0. Wyjdz\n");
}

void gotoxy(short x, short y) {
    printf("\033[%d;%dH", y, x);
}

char menu() {
    char wybor;

    system("cls");
    printf("Menu\n");
    printf("----\n");
    drukujStatus();
    printf("Wybierz opcje: ");
    scanf(" %c", &wybor);

    return wybor;
}

char* wczytajNazweBazy() {
    char* nazwa = (char*) malloc(20 * sizeof(char));

    printf("Podaj nazwe bazy danych: ");
    scanf("%s", nazwa);

    return nazwa;
}