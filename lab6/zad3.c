#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{

    int *pa, i;
    pa = (int *)calloc(5, sizeof(int));
    // zastosować przy wczytywaniu tablicy sposób 2
    for (i = 0; i < 5; i++)
    {
        printf("\n Podaj element [%d]=", i);
        scanf("%d", pa++); // wczytywanie sposób 1
        // scanf( "%d",pa+i); //wczytywanie sposób 2
        // scanf( "%d",&pa[i]);//wczytywanie sposób 3
    }
    // Drukowanie użyć sposobu 1 lub 2
    // Jeśli sposób 1, to trzeba cofnąć wskaźnik pa=pa-5;
    for (i = 0; i < 5; i++)
    {
        printf("\n %d", *pa++); // drukowanie sposób 1
    } 
    // printf("\n %d", *(pa+i));// drukowanie sposób 2
    // printf("\n %d", pa[i]);// drukowanie sposób 3
    return 0;
}
