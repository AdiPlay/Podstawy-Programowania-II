#include <stdio.h>
#include <conio.h>

int main() {
    char c;

    printf("Wpisz ciag znakow (ESC konczy): ");

    while ((c = getch()) != 27) {
        putchar(c);
        printf("\n");
    }

    printf("\nKoniec programu.\n");
    return 0;
}
