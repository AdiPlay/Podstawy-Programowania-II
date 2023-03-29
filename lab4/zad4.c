#include <stdio.h>

double srednia(double x[], int n);
double sredniaind(double x[], int poczatek, int koniec, double *min);
void wczyt1D(double x[], int n);

int main() {
    double w[5];
    int poczatek, koniec;
    wczyt1D(w, 5); 
    double min;
    printf("Podaj zakres 0-4: ");
    printf("\nPodaj poczatek: "); 
    scanf("%d", &poczatek);
    printf("Podaj koniec: ");
    scanf("%d", &koniec);
    printf("Średnia arytmetyczna całej tablicy: %.2f\n", srednia(w, 5));
    printf("Średnia arytmetyczna w zakresie %d-%d: %.2f\n", poczatek, koniec, sredniaind(w, poczatek, koniec, &min));
    printf("Minimalna wartość w zakresie %d-%d: %.2f\n", poczatek, koniec, min);
    return 0;
}

double srednia(double x[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += x[i];
    }
    return sum / n;
}

double sredniaind(double x[], int poczatek, int koniec, double *min) {
    double sum = 0.0;
    *min = x[poczatek];  
    for (int i = poczatek; i <= koniec; i++) {
        sum += x[i];
        if (x[i] < *min) {
            *min = x[i];
        }
    }
    return sum / (koniec - poczatek + 1);
}

void wczyt1D(double x[], int n){
    int i, k;
    for (i = 0; i < n; i++){
        do{
            printf("Podaj %d element: ", i);
            k = scanf("%lf", &x[i]);
            if (k == 0){
                printf("Błąd formatu, spróbuj ponownie: \n");
            }
            fflush(stdin);
        } while (k == 0);
    }
}