#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <dirent.h>

#define MAX_DRIVERS 100

struct F1 {
    char imie[20];
    char nazwisko[20];
    int identyfikator;
    int rokDebiutu;
    int liczbaMistrzostw;
    int liczbaZwyciestw;
    char narodowosc[20];
};

void clearScreen();
void gotoxy(int x, int y);
void printMenu();
int readInt();
void addDriver(struct F1 *drivers, int *numDrivers);
void editDriver(struct F1 *drivers, int numDrivers);
void deleteDriver(struct F1 *drivers, int *numDrivers);
void sortDrivers(struct F1 *drivers, int numDrivers);
void printDrivers(struct F1 *drivers, int numDrivers);
void zapiszDoPliku(struct F1 *drivers, int numDrivers);
void wczytajZPliku(struct F1 *drivers, int *numDrivers);
void utworzPlik();
void usunPlik();
void showDatFiles();