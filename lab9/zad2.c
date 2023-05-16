#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char s4[5], s5[5]="12345";
    char s6[5], s7[8]="Tekst";
    strcpy(s4, s5);
    printf("Tablica s4: %s\n", s4);
    strcpy(s6, s7 + 2);
    printf("Tablica s6: %s\n", s6);
    return 0;
}
