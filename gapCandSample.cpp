#include "gapCandSample.h"

void gapCoding(int n, int* A, int* G) {
    G[0] = A[0];
    for (int i = 1; i < n; i++) {
        G[i] = A[i] - A[i - 1];
    }
}

void createSample(int n, int* A, int* sample, int m, int b) {
    sample[0] = A[0];

    int acum = b;
    for (int i = 1; i < m; ++i) {
        sample[i] = A[acum];
        acum += b;
    }
}
