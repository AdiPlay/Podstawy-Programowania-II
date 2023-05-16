#include <stdio.h>
#include <string.h>

int main() {
    char s1[6], s2[8], s3[10];

    printf("Podaj tablice s1: ");
    scanf("%s", s1);
    printf("Tablica s1: %s\n", s1);
    fflush(stdin);

    printf("Podaj tablice s2: ");
    gets(s2);
    printf("Tablica s2: ");
    puts(s2);
    fflush(stdin);

    printf("Podaj tablice s3: ");
    fgets(s3, 10, stdin);
    printf("Tablica s3: ");
    fputs(s3, stdout);

    return 0;
}
