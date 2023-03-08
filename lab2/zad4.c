#include <stdio.h>
#include <math.h>

double dAdd(double a, double b);
double dSubtract(double a, double b);
double dMultiply(double a, double b);
double dDivide(double a, double b);

int main()
{
    double a, b;
    char kod;
    
    do
    {
        printf("Wprowadź pierwszą liczbę: ");
        scanf("%lf", &a);
        printf("Wprowadź operator (+, -, *, /): ");        
        kod=getch();
        if(kod==27){
            printf("Zakończenie programu.\n");
            break;
        }
        printf("\n");
        printf("Wprowadź drugą liczbę: ");
        scanf("%lf", &b);

        switch (kod)
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
        getchar();
    } while (kod != 27);
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