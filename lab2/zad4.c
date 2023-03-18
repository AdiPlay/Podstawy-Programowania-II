#include <stdio.h>
#include <math.h>
#define ESC 27

double dAdd(double a, double b);
double dSubtract(double a, double b);
double dMultiply(double a, double b);
double dDivide(double a, double b);

int main()
{
    
    double a, b;
    char ch;
    int k;

    do
    {

        printf("Wprowadź pierwszą liczbę: ");
        k = scanf("%lf", &a);
        if (k == 0)
            printf("Nieprawidłowy format.\n");
        fflush(stdin);
    } while (k == 0);
    do
    {
        printf("Wprowadź operator (+, -, *, /): \n");
        ch = getch();
        if (ch == 27)
        {
            printf("Zakończenie programu.\n");
            return 0;
        }

    } while (ch != '+' && ch != '-' && ch != '*' && ch != '/');
    printf("\n");
    do
    {
        printf("Wprowadź drugą liczbę: ");
        k = scanf("%lf", &b);
        if (k == 0)
            printf("Nieprawidłowy format.\n");
        fflush(stdin);
    } while (k == 0);

    if (ch == 27)
    {
        printf("Zakończenie programu.\n");
        return 0;
    }

    do
    {
        switch (ch)
        {
        case '+':
            dAdd(a, b);
            break;
        case '-':
            dSubtract(a, b);
            break;
        case '*':
            dMultiply(a, b);
            break;
        case '/':
            if (b == 0)
                printf("Nie można dzielić przez zero.\n");
            else
                dDivide(a, b);
            break;
        default:
            printf("Nieprawidłowy operator.\n");
        }
        ch = getch();
        getchar();
        fflush(stdin);
        
    } while (ch != 27);
    
    if (ch == 27)
    {
        printf("Zakończenie programu.\n");
        return 0;
    }
    return 0;
}

double dAdd(double a, double b)
{
    printf("%lf + %lf = %lf\n", a, b, a + b);
    return a + b;
}

double dSubtract(double a, double b)
{
    printf("%lf - %lf = %lf\n", a, b, a - b);
    return a - b;
}

double dMultiply(double a, double b)
{
    printf("%lf * %lf = %lf\n", a, b, a * b);
    return a * b;
}

double dDivide(double a, double b)
{
    printf("%lf / %lf = %lf\n", a, b, a / b);
    return a / b;
}