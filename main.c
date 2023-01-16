#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double getRandom1(int *k) {
    *k = ((75 * (*k + 45)) % 65537) - 1;
    return (double) *k / (pow(2, 16) + 1.0);

}

double getRandom2() {

    return (double) (rand() / (RAND_MAX + 1.0));

}

int main(int argc, char const *argv[]) {
    int hit = 0;

    int p = 1000;
    if (argc > 1) {
        p = atoi(argv[1]);
    }

    double r1, r2;
    int i = 0;

    int randint = 6543;
    int *n;
    n = &randint;

    for (i; i < 2 * p; i += 2) {

        r1 = getRandom2(n);
        r2 = getRandom2(n);

        if ((r1 * r1) + (r2 * r2) < 1) {
            hit += 1;
        }
    }
    printf("Liczba trafien: %d na %d prob \n", hit, p);
    double pi = 4 * (double) hit / p;
    printf("%f \n", pi);

    return 0;
}