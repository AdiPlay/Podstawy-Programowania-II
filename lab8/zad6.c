#include <stdio.h>
#include <string.h>

int main() {
  char haslo[6] = "abc";  // prawidłowe hasło to "abc"
  int proba = 1;
  char wpisane_haslo[6];

  while (proba <= 3) {
    printf("Podaj haslo (proba %d): ", proba);
    scanf("%s", wpisane_haslo);

    if (strcmp(haslo, wpisane_haslo) == 0) {
      printf("Haslo jest poprawne.\n");
      return 0;
    } else {
      printf("Haslo jest niepoprawne.\n");
      proba++;
    }
  }

  printf("Nie udalo sie podac poprawnego hasla w 3 probach.\n");
  return 0;
}
