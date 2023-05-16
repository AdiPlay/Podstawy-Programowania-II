#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char s1[6], s2[6];
    printf("Podaj tablice s1: ");
    fgets(s1, 6, stdin);
    printf("Podaj tablice s2: ");
    fgets(s2, 6, stdin);
    int p = strcmp(s1, s2);
    if (p == 0) {
        printf("Tablice sa identyczne.\n");
    } else if (p < 0) {
        printf("Tablica s1 jest mniejsza od tablicy s2.\n");
    } else {
        printf("Tablica s1 jest wieksza od tablicy s2.\n");
    }
    return 0;
}
