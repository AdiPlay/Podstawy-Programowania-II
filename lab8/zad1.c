#include <stdio.h>
#include <conio.h>

int main()
{
    char c;
    printf("Podaj znak metodą scanf: ");
    scanf("%c", &c);
    printf("Znak: %c\n", c);
    printf("Podaj znak metodą getchar: ");
    fflush(stdin);
    c = getchar();
    putchar(c);
    printf("\n");
    printf("Podaj znak metodą getch: ");
    fflush(stdin);
    c = getch();
    putc(c, stdout);
    printf("\n");
}