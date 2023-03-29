#include <stdio.h>

double average(double tab[], int n);
double sredniaind(double tab[], int start, int end, double *min);
void wczyt1D(double tab[], int n);

int main() {
    double w[5];
    wczyt1D(w, 5); 
    double avg = average(w, 5);  
    double min;
    double avg_range = sredniaind(w, 1, 3, &min);  
    printf("Średnia arytmetyczna elementów całej tablicy: %.2f\n", avg);
    printf("Średnia arytmetyczna elementów w zakresie 1-3: %.2f\n", avg_range);
    printf("Minimalna wartość w zakresie 1-3: %.2f\n", min);
    return 0;
}

double average(double tab[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += tab[i];
    }
    return sum / n;
}


double sredniaind(double tab[], int start, int end, double *min) {
    double sum = 0.0;
    *min = tab[start];  
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
    int i, k;
    for (i = 0; i < n; i++)
    {
        do
        {
            printf("Podaj %d element: ", i + 1);
            k = scanf("%lf", &tab[i]);
            if (k == 0)
            {
                printf("Błąd formatu, spróbuj ponownie: \n");
            }
            fflush(stdin);
        } while (k == 0);
    }
}