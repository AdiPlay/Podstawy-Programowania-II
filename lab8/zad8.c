#include <stdio.h>
#include <ctype.h>

int main() {
  char c;

  printf("Wpisz ciag znakow (ESC konczy): ");

  while ((c = getch()) != 27) {
    if (isalnum(c)) {
      if (isalpha(c)) {
        c = toupper(c);
      }
      putchar(c);
        printf("\n");
    }
  }

  printf("\nKoniec programu.\n");
  return 0;
}
