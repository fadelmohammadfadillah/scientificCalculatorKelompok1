#include <stdio.h>

double calculateLn(double x, int n) {
    double sum = 0.0;
    double term = x - 1.0;
	int i;
    for ( i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            term = -(x - 1.0) / i;
        } else {
            term = (x - 1.0) / i;
        }
        sum += term;
    }

    return sum;
}

int main() {
    double x;
    int n;

    printf("Masukkan nilai x: ");
    scanf("%lf", &x);

    printf("Masukkan jumlah iterasi: ");
    scanf("%d", &n);

    double ln = calculateLn(x, n);
    printf("ln(%g) = %.15g\n", x, ln);

    return 0;
}
