#include <stdio.h>
#include <ctype.h>

int main() {
  char c;
  int n;
  while((n = getchar()) != 27) {
    if (islower(n)) {
      printf("%c", toupper(n));
    } else if (isupper(n)) {
      printf("%c", tolower(n));
    } else {
      printf("%c", n);
    }
  }
}