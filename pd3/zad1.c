#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char *argv[])
{
    int b[5][5], n = 5;
    unsigned int nrAlbumu = 19727; // Nalezy wstawić własny nr albumu
    unsigned int i, j, m, mod;
    srand(time(NULL));
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            m = nrAlbumu % (rand() % 10 + 1);
            b[i][j] = rand() % 10 + m;
        }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf(" %3d", b[i][j]);
        printf("\n");
    }
    getchar();
    return 0;
}