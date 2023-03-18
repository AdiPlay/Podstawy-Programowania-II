#include <stdio.h>
#include <math.h>

double sinusapprox(double x, int n);

int main()
{
    double x;
    printf("Podaj argument x: ");
    if (scanf("%lf", &x) != 1)
    {
        printf("Błąd: Niepoprawny format liczby!\n");
        return 1;
    }

    double sinusXn[3];
    int n;
    for (n = 4; n <= 6; n++)
    {
        sinusXn[n - 4] = sinusapprox(x, n);
    }

    printf("sin(x) dla x = %g:\n", x);
    printf("z funkcji math.h: %g\n", sin(x));
    printf("z funkcji sinusapprox:\n");
    int i;
    for (i = 0; i < 3; i++)
    {
        printf("n = %d: %g\n", i + 4, sinusXn[i]);
    }

    return 0;
}

double sinusapprox(double x, int n)
{
    double wynik = 0.0;
    int i;
    for (i = 0; i < n; i++)
    {
        double potega = pow(x, 2 * i + 1);
        double dzielnik = 1.0;
        int j;
        for (j = 1; j <= 2 * i + 1; j++)
        {
            dzielnik *= j;
        }
        double skladnik = potega / dzielnik;
        if (i % 2 == 1)
        {
            skladnik = -skladnik;
        }
        wynik += skladnik;
    }
    return wynik;
}
