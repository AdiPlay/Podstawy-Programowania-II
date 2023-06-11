#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void przepisz43(int macierz[][4], int nrWiersza, int nrKolumny, int podmacierz[][3]);
void przepisz54(int macierz[][5], int nrWiersza, int nrKolumny, int podmacierz[][4]);
int sarrus(int macierz[][3]);
int laplace(int macierz[][4]);
void fillArray(int A[][5], int n, unsigned int nrAlbumu);
void printArray(int A[][5], int n);

