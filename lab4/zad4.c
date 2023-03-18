#include <stdio.h>

double average(double tab[], int n);
double sredniaind(double tab[], int start, int end, double *min);
void wczyt1D(double tab[], int n);

int main() {
    double w[5];
    wczyt1D(w, 5);  // wczytanie tablicy
    double avg = average(w, 5);  // obliczenie średniej arytmetycznej
    double min;
    double avg_range = sredniaind(w, 1, 3, &min);  // obliczenie średniej arytmetycznej w zakresie 1-3 i wartości minimalnej
    printf("Średnia arytmetyczna elementów całej tablicy: %.2f\n", avg);
    printf("Średnia arytmetyczna elementów w zakresie 1-3: %.2f\n", avg_range);
    printf("Minimalna wartość w zakresie 1-3: %.2f\n", min);
    return 0;
}

// Funkcja obliczająca średnią arytmetyczną elementów tablicy
double average(double tab[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += tab[i];
    }
    return sum / n;
}

// Funkcja obliczająca średnią arytmetyczną elementów tablicy w wybranym zakresie indeksów
// oraz wartość minimalną w tym zakresie (zapisywaną do zmiennej wskazywanej przez wskaźnik min)
double sredniaind(double tab[], int start, int end, double *min) {
    double sum = 0.0;
    *min = tab[start];  // zakładamy, że wartość minimalna to pierwszy element w zakresie
    for (int i = start; i <= end; i++) {
        sum += tab[i];
        if (tab[i] < *min) {
            *min = tab[i];
        }
    }
    return sum / (end - start + 1);
}

void wczyt1D(double tab[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Podaj element [%d]: ", i);
        if (scanf("%lf", &tab[i]) != 1)
        {
            printf("Błąd: Niepoprawny format liczby!\n");
            return;
        }
    }
}