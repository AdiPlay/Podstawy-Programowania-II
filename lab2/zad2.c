#include <stdio.h>

double silnia();
double newton();

int main(int argc, char const *argv[])
{
    printf("Silnia: %.2lf\n", silnia(6));
    printf("Symbol Newtona: %.2lf\n", newton(3, 2));
    return 0;
}

double silnia(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * silnia(n - 1);
}

double newton(int n, int k)
{
    return silnia(n) / (silnia(k) * silnia(n - k));
}
