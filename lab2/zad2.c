#include <stdio.h>

float silnia();
float newton();

int main(int argc, char const *argv[])
{
    printf("Silnia: %.2f\n", silnia(6));
    printf("Symbol Newtona: %.2f\n", newton(5,3));
    return 0;
}

float silnia(int n)
{
    // Warunek końcowy
    if (n == 0 || n == 1)
        return 1;
    // Wywołanie rekurencyjne
    else
        return n * silnia(n - 1);
}

float newton(int n, int k)
{
    return silnia(n) / (silnia(k) * silnia(n - k));
}
