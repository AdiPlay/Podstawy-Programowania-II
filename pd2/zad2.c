#include <stdio.h>
int czy_wzglednie_pierwsza(int a, int b);
int suma_wzglednie_pierwszych(int n);
int main() {
    int n;
    printf("Podaj liczbe nie ujemną: ");
    scanf("%d", &n);
    printf("Suma liczb mniejszych niż %d i względnie pierwszych %d wynosi: %d\n", n, n, suma_wzglednie_pierwszych(n));
    return 0;
}
int czy_wzglednie_pierwsza(int a, int b) {
    if (a == 1 || b == 1) {
        return 1;
    }
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return (a == 1);
}
int suma_wzglednie_pierwszych(int n) {
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (czy_wzglednie_pierwsza(i, n)) {
            sum += i;
        }
    }
    return sum;
}