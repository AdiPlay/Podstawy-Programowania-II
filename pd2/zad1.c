#include <stdio.h>

int sqrt_with_precision(int n, int precision);

int main() {
    int n = 16;
    int precision = 10;
    int res = sqrt_with_precision(n * precision * precision, precision);
    printf("sqrt(%d) = %d.%d\n", n, res / precision, res % precision);
    return 0;
}

int sqrt_with_precision(int n, int precision) {
    int left = 0, right = n;
    int mid, res;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (mid * mid <= n) {
            res = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return res / precision;
}