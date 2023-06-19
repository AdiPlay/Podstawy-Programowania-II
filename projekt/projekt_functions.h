
void clearScreen()
{
    printf("\033[2J\033[1;1H");
}

void gotoxy(int x, int y)
{
    printf("\033[%d;%dH", y, x);
}

void printMenu()
{
    clearScreen();
    gotoxy(20, 7);
    printf("!ZANIM ZACZNIESZ DODAWAC KIEROWCOW, MUSISZ WCZYTAC ODPOWIEDNI PLIK (GROZI NADPISANIEM)!");
    gotoxy(20, 8);
    printf("Menu");
    gotoxy(20, 9);
    printf("----");
    gotoxy(20, 11);
    printf("1. Dodaj kierowce");
    gotoxy(20, 12);
    printf("2. Edytuj kierowce");
    gotoxy(20, 13);
    printf("3. Usun kierowce");
    gotoxy(20, 14);
    printf("4. Sortuj kierowcow");
    gotoxy(20, 15);
    printf("5. Wyswietl liste kierowcow");
    gotoxy(20, 16);
    printf("6. Zapisz do pliku");
    gotoxy(20, 17);
    printf("7. Wczytaj z pliku");
    gotoxy(20, 18);
    printf("8. Utworz plik");
    gotoxy(20, 19);
    printf("9. Usun plik");
    gotoxy(20, 20);
    printf("0. Wyjdz");
    gotoxy(20, 22);
    printf("Wybierz opcje: ");
}

int readInt()
{
    int n;
    scanf("%d", &n);
    getchar();
    return n;
}

void addDriver(struct F1 *drivers, int *numDrivers)
{
    if (*numDrivers >= MAX_DRIVERS)
    {
        printf("Nie mozna dodac wiecej kierowcow!\n");
        return;
    }
    struct F1 st;
    int x = 20, y = 8;
    clearScreen();
    gotoxy(x, y);
    printf("Podaj imie: ");
    scanf("%s", st.imie);
    gotoxy(x, y + 1);
    printf("Podaj nazwisko: ");
    scanf("%s", st.nazwisko);
    gotoxy(x, y + 2);
    printf("Podaj identyfikator: ");
    scanf("%d", &st.identyfikator);
    gotoxy(x, y + 3);
    printf("Podaj rok debiutu: ");
    scanf("%d", &st.rokDebiutu);
    gotoxy(x, y + 4);
    printf("Podaj liczbe mistrzostw: ");
    scanf("%d", &st.liczbaMistrzostw);
    gotoxy(x, y + 5);
    printf("Podaj liczbe zwyciestw: ");
    scanf("%d", &st.liczbaZwyciestw);
    gotoxy(x, y + 6);
    printf("Podaj narodowosc: ");
    scanf("%s", st.narodowosc);
    drivers[*numDrivers] = st;
    (*numDrivers)++;
}

void editDriver(struct F1 *drivers, int numDrivers)
{
    int id;
    int i;
    clearScreen();
    gotoxy(20, 8);
    printf("Edytuj kierowce");
    gotoxy(20, 9);
    printf("----------------");
    gotoxy(20, 11);
    printf("Podaj identyfikator kierowcy: ");
    scanf("%d", &id);
    for (i = 0; i < numDrivers; i++)
    {
        if (drivers[i].identyfikator == id)
        {
            int x = 20, y = 13;
            clearScreen();
            gotoxy(x, y);
            printf("Imie: %s", drivers[i].imie);
            gotoxy(x, y + 1);
            printf("Nazwisko: %s", drivers[i].nazwisko);
            gotoxy(x, y + 2);
            printf("Identyfikator: %d", drivers[i].identyfikator);
            gotoxy(x, y + 3);
            printf("Rok debiutu: %d", drivers[i].rokDebiutu);
            gotoxy(x, y + 4);
            printf("Liczba mistrzostw: %d", drivers[i].liczbaMistrzostw);
            gotoxy(x, y + 5);
            printf("Liczba zwyciestw: %d", drivers[i].liczbaZwyciestw);
            gotoxy(x, y + 6);
            printf("Narodowosc: %s", drivers[i].narodowosc);
            gotoxy(x, y + 8);
            printf("Podaj nowe dane:");
            gotoxy(x, y + 9);
            printf("Imie: ");
            scanf("%s", drivers[i].imie);
            gotoxy(x, y + 10);
            printf("Nazwisko: ");
            scanf("%s", drivers[i].nazwisko);
            gotoxy(x, y + 11);
            printf("Identyfikator: ");
            scanf("%d", &drivers[i].identyfikator);
            gotoxy(x, y + 12);
            printf("Rok debiutu: ");
            scanf("%d", &drivers[i].rokDebiutu);
            gotoxy(x, y + 13);
            printf("Liczba mistrzostw: ");
            scanf("%d", &drivers[i].liczbaMistrzostw);
            gotoxy(x, y + 14);
            printf("Liczba zwyciestw: ");
            scanf("%d", &drivers[i].liczbaZwyciestw);
            gotoxy(x, y + 15);
            printf("Narodowosc: ");
            scanf("%s", drivers[i].narodowosc);
            return;
        }
    }
    printf("Nie znaleziono kierowcy o podanym identyfikatorze!\n");
}

void deleteDriver(struct F1 *drivers, int *numDrivers)
{
    int id;
    int i, j;
    clearScreen();
    gotoxy(20, 8);
    printf("Usun kierowce");
    gotoxy(20, 9);
    printf("--------------");
    gotoxy(20, 11);
    printf("Podaj identyfikator kierowcy: ");
    scanf("%d", &id);
    for (i = 0; i < *numDrivers; i++)
    {
        if (drivers[i].identyfikator == id)
        {
            for (j = i; j < *numDrivers - 1; j++)
            {
                drivers[j] = drivers[j + 1];
            }
            (*numDrivers)--;
            printf("Kierowca zostal usuniety!\n");
            return;
        }
    }
    printf("Nie znaleziono kierowcy o podanym identyfikatorze!\n");
}

int compareDrivers(const void *a, const void *b)
{
    struct F1 *driverA = (struct F1 *)a;
    struct F1 *driverB = (struct F1 *)b;
    if (driverA->nazwisko == NULL && driverB->nazwisko == NULL)
    {
        return 0;
    }
    else if (driverA->nazwisko == NULL)
    {
        return -1;
    }
    else if (driverB->nazwisko == NULL)
    {
        return 1;
    }
    else
    {
        return strcmp(driverA->nazwisko, driverB->nazwisko);
    }
}

void sortDrivers(struct F1 *drivers, int numDrivers)
{
    qsort(drivers, numDrivers, sizeof(struct F1), compareDrivers);
}

void printDrivers(struct F1 *drivers, int numDrivers)
{
    clearScreen();
    gotoxy(20, 8);
    printf("Lista kierowcow");
    gotoxy(20, 9);
    printf("----------------");
    int i;
    for (i = 0; i < numDrivers; i++)
    {
        gotoxy(20, 11 + i * 2);
        printf("%s %s (%s), ID: %d, debiut: %d, mistrzostwa: %d, zwyciestwa: %d",
               drivers[i].imie, drivers[i].nazwisko, drivers[i].narodowosc,
               drivers[i].identyfikator, drivers[i].rokDebiutu,
               drivers[i].liczbaMistrzostw, drivers[i].liczbaZwyciestw);
    }
    gotoxy(20, 11 + numDrivers * 2);
    printf("Nacisnij dowolny klawisz, aby powrocic do menu...");
    getchar();
}

void zapiszDoPliku(struct F1 *drivers, int numDrivers)
{
    char filename[100];
    int x = 20, y = 8;
    clearScreen();
    showDatFiles();
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

void wczytajZPliku(struct F1 *drivers, int *numDrivers)
{
    char filename[100];
    int x = 20, y = 8;
    clearScreen();
    showDatFiles();
    gotoxy(x, y - 2);
    printf("Wczytaj dane z pliku");
    gotoxy(x, y);
    printf("Podaj nazwe pliku: ");
    scanf("%s", filename);
    if (strstr(filename, ".dat") == NULL)
    {
        strcat(filename, ".dat");
    }
    FILE *fp1;
    fp1 = fopen(filename, "rb");
    if (fp1 == NULL)
    {
        printf("Nie moge otworzyc pliku do odczytu!\n");
        exit(1);
    }
    fseek(fp1, 0L, SEEK_END);
    int fileSize = ftell(fp1);
    fseek(fp1, 0L, SEEK_SET);
    *numDrivers = fileSize / sizeof(struct F1);
    fread(drivers, sizeof(struct F1), *numDrivers, fp1);
    fclose(fp1);
    printf("Dane zostaly wczytane z pliku %s!\n", filename);
    getchar();
}

void utworzPlik()
{
    char filename[100];
    int x = 20, y = 8;
    clearScreen();
    showDatFiles();
    gotoxy(x, y - 2);
    printf("Utworz plik");
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
        printf("Nie moge utworzyc pliku!\n");
        exit(1);
    }
    fclose(fp1);
    gotoxy(x, y + 2);
    printf("Plik %s zostal utworzony!\n", filename);
}

void usunPlik()
{
    char filename[100];
    int x = 20, y = 8;
    clearScreen();
    showDatFiles();
    gotoxy(x, y - 2);
    printf("Usun plik");
    gotoxy(x, y);
    printf("Podaj nazwe pliku: ");
    scanf("%s", filename);
    getchar(); // consume newline character
    if (strstr(filename, ".dat") == NULL)
    {
        strcat(filename, ".dat");
    }
    if (access(filename, F_OK) != -1)
    {
        int x = 20, y = 10;
        clearScreen();
        gotoxy(x, y);
        printf("Czy na pewno chcesz usunac plik %s? (T/N) ", filename);
        char c = getchar();
        if (toupper(c) == 'T')
        {
            remove(filename);
            printf("Plik %s zostal usuniety!\n", filename);
        }
        else
        {
            printf("Plik %s nie zostal usuniety!\n", filename);
        }
    }
    else
    {
        printf("Plik %s nie istnieje!\n", filename);
    }
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
