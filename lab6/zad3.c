#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *pa, i, minParzysta = -1, k;
    pa = (int *)calloc(5, sizeof(int));
    for (i = 0; i < 5; i++){
        do{
            printf("Podaj %d element: ", i + 1);
            k = scanf("%d", &pa[i]);
            if (k == 0)
            {
                printf("Błędne dane, wprowadź ponownie: \n");
            }
            fflush(stdin);
        } while (k == 0);
    }
    for (i = 0; i < 5; i++){
        if (pa[i] % 2 == 0 && (minParzysta == -1 || pa[i] < minParzysta))
        {
            minParzysta = pa[i];
        }
    }
    if (minParzysta == -1) {
        printf("W tablicy nie ma liczb parzystych.\n");
    }else{
        printf("Najmniejsza liczba parzysta w tablicy: %d\n", minParzysta);
    }
    for (i = 0; i < 5; i++){
        printf("%d ", pa[i]);
    }
    free(pa);
    return 0;
}
