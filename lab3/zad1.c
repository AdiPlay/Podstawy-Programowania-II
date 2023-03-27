#include <stdio.h>

int main(int argc, char const *argv[])
{
    /*a) zdefiniować zmienne x typu int oraz y typu double i zmienne wskaźnikowe px typu
     wskaźnik do int oraz py typu wskaźnik do double*/
    int x;
    double y;
    int *px;
    double *py;
    // b) przypisać zmiennym wskaźnikowym px i py wskaźniki do x i y
    px = &x;
    py = &y;
    // c)wczytać z klawiatury zmienne x i y przy użyciu wskaźników, następnie je przy użyciu wskaźników
    printf("Podaj dwie liczby: \n");
    scanf("%d", px);
    scanf("%lf", py);
    printf("Wypisanie zmiennych: \n");
    printf("%d\n", *px);
    printf("%lf\n", *py);
    // d)
    double tab[5];
    double *pa;
    pa = tab;
    printf("Wpisz liczby do tablicy: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("Podaj %d element: ", i + 1);
        scanf("%lf", pa + i);
    }
    printf("Drukowanie tablicy: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("%lf\n", *(pa + i));
    }

    return 0;
}
