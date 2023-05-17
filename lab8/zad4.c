#include <stdio.h>
#include <ctype.h>
int main() {
  char c;
  printf("Podaj znak: ");
  scanf("%c", &c);
  printf("Klasyfikacja znaku '%c':\n", c);
  if(isalnum(c)) printf("isalnum: %d\n", isalnum(c)); // isalnum - sprawdza czy znak jest literą lub cyfrą
  if(isalpha(c)) printf("isalpha: %d\n", isalpha(c)); // isalpha - sprawdza czy znak jest literą
  if(iscntrl(c)) printf("iscntrl: %d\n", iscntrl(c)); // iscntrl - sprawdza czy znak jest znakiem sterującym
  if(isdigit(c)) printf("isdigit: %d\n", isdigit(c)); // isdigit - sprawdza czy znak jest cyfrą
  if(isgraph(c)) printf("isgraph: %d\n", isgraph(c)); // isgraph - sprawdza czy znak jest znakiem drukowalnym oprócz spacji
  if(islower(c)) printf("islower: %d\n", islower(c)); // islower - sprawdza czy znak jest małą literą
  if(isprint(c)) printf("isprint: %d\n", isprint(c)); // isprint - sprawdza czy znak jest znakiem drukowalnym
  if(ispunct(c)) printf("ispunct: %d\n", ispunct(c)); // ispunct - sprawdza czy znak jest znakiem przestankowym
  if(isspace(c)) printf("isspace: %d\n", isspace(c)); // isspace - sprawdza czy znak jest białym znakiem
  if(isupper(c)) printf("isupper: %d\n", isupper(c)); // isupper - sprawdza czy znak jest wielką literą
  if(isxdigit(c)) printf("isxdigit: %d\n", isxdigit(c)); // isxdigit - sprawdza czy znak jest cyfrą szesnastkową
  return 0;
}
