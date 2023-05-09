#include <stdio.h>
#include <ctype.h>

int main() {
  char c;
  printf("Podaj litere: ");
  scanf("%c", &c);
  if (islower(c)) {
    printf("Litera '%c' zamieniona na '%c'\n", c, toupper(c));
  } else if (isupper(c)) {
    printf("Litera '%c' zamieniona na '%c'\n", c, tolower(c));
  } else {
    printf("Podany znak nie jest literą.\n");
  }

  return 0;
}