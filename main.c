#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define R_MAX 65535
#define N 100000000 // Liczba punktów


void firstAttempt() {
    int Rn = 432; // Początkowa wartość Rn
    int Rn1; // Następna wartość Rn
    int k = 0; // Liczba trafień we wnętrze koła

    // Generowanie N punktów
    for (int i = 0; i < N; i++) {
        Rn1 = 75 * (Rn + 1) % 65537 - 1;
        double x = (double) Rn / (R_MAX + 1.0);
        Rn = Rn1;

        Rn1 = 75 * (Rn + 1) % 65537 - 1;
        double y = (double) Rn / (R_MAX + 1.0);
        Rn = Rn1;

        if (x * x + y * y < 1) {
            k++;
        }
    }

    double pi = 4.0 * (double) k / (double) N;
    printf("Przybliżona wartość liczby pi: %lf\n", pi);

    double uncertainty = sqrt(((double) k * (double) (N - k)) / ((double) N * (double) N));
    printf("Niepewność przybliżenia: %lf\n", uncertainty);
}

void secondAttempt() {
    int seed = 432;
    int k = 0;

    srand(seed);

    for (int i = 0; i < N; i++) {
        double x = (double) rand() / (double) RAND_MAX;
        double y = (double) rand() / (double) RAND_MAX;
        if (x * x + y * y < 1) {
            k++;
        }
    }
    double pi = 4.0 * (double) k / (double) N;
    printf("Przybliżona wartość liczby pi: %lf\n", pi);

    double uncertainty = sqrt(((double) k * (double) (N - k)) / ((double) N * (double) N));
    printf("Niepewność przybliżenia: %lf\n", uncertainty);

}

int main(void) {
    firstAttempt();
    secondAttempt();
}