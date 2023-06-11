#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Produkt
{ // definicja struktury Produkt
    char nazwa[25];
    int identyfikator;
    char typ[25];
    char producent[25];
    double cenaNetto;
    int VAT;
    double cenaBrutto;
};
FILE *utworzNowyPlik(char *nazwa, char *tryb)
{ // Funkcja tworząca
    // nowy plik
    FILE *fp;
    fp = fopen(nazwa, tryb);
    if (fp == NULL)
    {
        printf("\n Plik %s nie zostal utworzony", nazwa);
        getchar();
        exit(1);
    }
    else
        printf("\n Nowy plik %s zostal utworzony", nazwa);
    return fp;
}
FILE *otworzPlik(char *nazwa, char *tryb)
{
    // funkcja otwierajaca istniejacy plik
    FILE *fp;
    printf(" Otwieranie pliku");
    fp = fopen(nazwa, tryb);
    if (fp == NULL)
    {
        printf("\n Plik nie zostal otwarty");
        getchar();
        exit(1);
    }
    else
        printf("\n Plik zostal otwarty");
}
void drukujStrukt(struct Produkt st)
{
    printf("\n nazwa:%s", st.nazwa);
    printf("\n Identyfikator:%d", st.identyfikator);
    printf("\n Typ: %s", st.typ);
    printf("\n Producent:%s", st.producent);
    printf("\n Cena netto:%f", st.cenaNetto);
    printf("\n VAT:%d", st.VAT);
    printf("\n Cena brutto:%f", st.cenaBrutto);
}
struct Produkt wczytajStrukt(void)
{
    struct Produkt st;
    fflush(stdin);
    printf("\nNazwa:");
    scanf("%s", st.nazwa);
    printf("\nIdentyfikator:");
    scanf("%d", &st.identyfikator);
    fflush(stdin);
    printf("\nProducent:");
    scanf("%s", st.producent);
    fflush(stdin);
    printf("\nTyp:");
    scanf("%s", st.typ);
    fflush(stdin);
    printf("\nCena netto:");
    scanf("%lf", &st.cenaNetto);
    printf("\nVAT:");
    scanf("%d", &st.VAT);
    st.cenaBrutto = st.cenaNetto * (1 + st.VAT / 100.0);
    return st;
};
int main()
{

    // Program tworzy nowy plik smartfony.dat w katalogu bieżącym i
    // zapisuje dane z tablicy struktur do pliku, następnie odczytuje plik
    struct Produkt smartfony[4] =
        {{"smartfon", 101, "RedmiNote8T", "Xiaomi", 568.29, 23, 699},
         {"smartfon", 102, "MiNote10", "Xiaomi", 1625.20, 23, 1999},
         {"smartfon", 103, "SamsungGalaxyA71", "Samsung", 1625.21, 23, 1999},
         {"smartfon", 104, "ApplePhoneSE", "Apple", 1991.06, 23, 2449}};
    FILE *fp1;
    int i;
    struct Produkt bufs;
    fp1 = utworzNowyPlik("Smartfony1.dat", "w+b");

    printf("\n Zapis tablicy struktur do pliku");
    for (i = 0; i < 4; i++)
        fwrite(&smartfony[i], sizeof(struct Produkt), 1, fp1);
    printf("\n Zapis ukonczony");
    getchar();
    i = 1;
    fseek(fp1, 0, SEEK_SET); // Ustawienie wskaźnika pliku na początku
                             // aby moc odczytać plik
    // Odczyt pliku
    while (fread(&bufs, sizeof(struct Produkt), 1, fp1))
    {
        printf("\n Dane smartfonu %d", i++);
        drukujStrukt(bufs);
        // getchar();
        printf("\n");
    }
    getchar();
    system("cls");
    // W tej czesci programu wczytywana jest nowa struktura i dopisywana
    // na koncu pliku
    printf("\n Wczytywanie struktury i zapis do pliku");
    fflush(stdin);
    bufs = wczytajStrukt();
    fseek(fp1, 0, SEEK_END);                       // ustawienie wskaźnika pliku na końcu pliku
    fwrite(&bufs, sizeof(struct Produkt), 1, fp1); // dopisanie struktury na
    // końcu pliku
    printf("\n Wydruk pliku po dopisaniu struktury");
    fseek(fp1, 0, SEEK_SET);
    i = 1;
    while (fread(&bufs, sizeof(struct Produkt), 1, fp1))
    {
        printf("\n Dane smartfonu %d", i++);
        drukujStrukt(bufs);
        getchar();
        printf("\n");
    }
    printf("\n Wyszukiwanie struktury o zadanej wartosci pola producent");
    printf("\n Przykladowym zadanym polem będzie pole, w ktorym zapisana jest nazwa firmy Samsung");
    fseek(fp1, 0, SEEK_SET);
    i = 1;
    printf("\n Wynik wyszukiwania producenta Samsung ");
    fseek(fp1, 0, SEEK_SET);
    // Wyszukiwanie polega na odczycie kolejnych struktur z pliku
    // i porownywaniu pola producent w tych strukturach z lancuchem znakow
    // "Samsung"). Poniewaz pole producent jest tablica znakowa, stosowana
    // jest do porownania funkcja strcmp porownujaca tablice znakowe.
    i = 1;
    printf("\n Wynik wyszukiwania producenta Samsung ");
    while (fread(&bufs, sizeof(struct Produkt), 1, fp1))
    {
        if (strcmp(bufs.producent, "Samsung") == 0)
            printf("\n Producenta znaleziono na pozycji %d", i);
        i++;
    }
    printf("\n \n \n");
    printf("\n Zmiana wartosci pola w wybranej strukturze, ");
    printf("\n jako przyklad zostanie zrealizowana zmiana typu smartfona Samsung na typ Y7");
    printf("\n zakladamy dla uproszczenia, ze zmiana będzie wykonana dla trzeciej struktury");
    fseek(fp1, 2 * sizeof(struct Produkt), SEEK_SET); // ustawienie
                                                      // wskaźnika pliku przed trzecia struktura aby ja odczytac ");
    fread(&bufs, sizeof(struct Produkt), 1, fp1);     // odczyt trzeciej struktury
    strcpy(bufs.typ, "Samsung Y7");
    fseek(fp1, -1 * sizeof(struct Produkt), SEEK_CUR);
    // Jest to cofnięcie wskaznika pliku o jedna pozycje do tylu wzgledem
    // pozycji biezacej - dlatego SEEK_CUR
    //--------------------------------------------------------------------
    // Zapis zmodyfikowanej struktury do pliku
    fwrite(&bufs, sizeof(struct Produkt), 1, fp1);
    //-------------------------------------------------------------------
    // Odczyt pliku po modyfikacji
    fseek(fp1, 0, SEEK_SET);
    i = 1;
    while (fread(&bufs, sizeof(struct Produkt), 1, fp1))
    {
        printf("\n Dane smartfonu %d", i++);
        drukujStrukt(bufs);
        getchar();
        printf("\n\n\n");
    }
    //----------------------------------------------------------------------------------
    // Sortowanie pliku wzgledem pola producent
    struct Produkt bufs1, bufs2;
    int n = 6, zam;
    fseek(fp1, 0, SEEK_SET);
    do
    {
        zam = 0;
        for (i = 0; i < n - 1; i++)
        {
            fseek(fp1, i * sizeof(struct Produkt), SEEK_SET);
            fread(&bufs1, sizeof(struct Produkt), 1, fp1);
            fread(&bufs2, sizeof(struct Produkt), 1, fp1);
            if (strcmp(bufs1.producent, bufs2.producent) > 0)
            {
                fseek(fp1, i * sizeof(struct Produkt), SEEK_SET);
                fwrite(&bufs2, sizeof(struct Produkt), 1, fp1);
                fwrite(&bufs1, sizeof(struct Produkt), 1, fp1);
                zam = 1;
            } // if
        }     // for
    } while (zam);
    printf("\n Wydruk pliku posortowanego");
    fseek(fp1, 0, SEEK_SET);
    i = 1;
    while (fread(&bufs, sizeof(struct Produkt), 1, fp1))
    {
        printf("\n Dane smartfonu %d", i++);
        drukujStrukt(bufs);
        getchar();
        printf("\n\n\n");
    }
    getchar();
    fclose(fp1);
    return 0;
}