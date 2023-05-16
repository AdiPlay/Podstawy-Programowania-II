#include <stdio.h>
#include <conio.h>
int main()
{
    int i;
    for (i = 32; i < 256; i++)
    {
        printf("\nZnak =%c kod dec=%3d hex =%x oct=%o", i, i, i, i);
        getchar();
    }
    return 0;
}