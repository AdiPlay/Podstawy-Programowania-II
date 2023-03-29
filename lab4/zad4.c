#include <stdio.h>

double average(double x[], int n);
double sredniaind(double x[], int poczatek, int koniec, double *min);
void wczyt1D(double x[], int n);

int main() {
    double w[5];
    wczyt1D(w, 5); 
    double avg = average(w, 5);  
    double min;
    double avg_range = sredniaind(w, 1, 3, &min);  
    printf("Średnia arytmetyczna całej tablicy: %.2f\n", avg);
    printf("Średnia arytmetyczna w zakresie 1-3: %.2f\n", avg_range);
    printf("Minimalna wartość w zakresie 1-3: %.2f\n", min);
    return 0;
}

double average(double x[], int n) {
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
            printf("Podaj %d element: ", i + 1);
            k = scanf("%lf", &x[i]);
            if (k == 0){
                printf("Błąd formatu, spróbuj ponownie: \n");
            }
            fflush(stdin);
        } while (k == 0);
    }
}