#include <stdio.h>

int pierw_z_dokl(int n, int dokl);

int main() {
    int n = 16;
    int dokl = 10;
    int wynik = pierw_z_dokl(n * dokl * dokl, dokl);
    printf("sqrt(%d) = %d.%d\n", n, wynik / dokl, wynik % dokl);
    return 0;
}

int pierw_z_dokl(int n, int dokl) {
    int left = 0, right = n;
    int mid, wynik;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (mid * mid <= n) {
            wynik = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return wynik / dokl;
}