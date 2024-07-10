#include <random>
#include <algorithm>
#include "distribuciones.h"

void dLineal(int n, int e, int *A) {
    A[0] = rand();
    for (int i = 1; i < n; i++) {
        A[i] = A[i - 1] + (rand() % e);
    }
}

void dNormal(int n, int media, int desviacionEstandar, int* A, int semilla) {
    std::default_random_engine generador(semilla);
    std::normal_distribution<double> distribucion(media, desviacionEstandar);

    for (int i = 0; i < n; ++i) {
        A[i] = static_cast<int>(distribucion(generador));
    }
    std::sort(A, A + n); // Usa introsort
}
