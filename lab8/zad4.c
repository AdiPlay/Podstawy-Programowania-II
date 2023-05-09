#include <stdio.h>
#include <ctype.h>

int main() {
  char c;
  printf("Podaj znak: ");
  scanf("%c", &c);
  printf("Klasyfikacja znaku '%c':\n", c);
  printf("isalnum: %d\n", isalnum(c));
  printf("isalpha: %d\n", isalpha(c));
  printf("iscntrl: %d\n", iscntrl(c));
  printf("isdigit: %d\n", isdigit(c));
  printf("isgraph: %d\n", isgraph(c));
  printf("islower: %d\n", islower(c));
  printf("isprint: %d\n", isprint(c));
  printf("ispunct: %d\n", ispunct(c));
  printf("isspace: %d\n", isspace(c));
  printf("isupper: %d\n", isupper(c));
  printf("isxdigit: %d\n", isxdigit(c));

  return 0;
}
