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
    sample[m] = A[n]; // asi nos aseguramos que se cubran todos los intervalos (menos eficiente por intervalo final mas grande)
}
void reconstruirArregloDesdeSample(int* gaps, int* sample, int ini, int fin, int* reconstruido, int b) {
    int sampleIdx = ini / b;  // Índice en el arreglo sample
    int val = sample[sampleIdx];  // Valor inicial basado en la muestra

    for (int i = 0; i < (fin - ini); ++i) {
        val += gaps[ini + i];  // Reconstruir el valor usando los gaps
        reconstruido[i] = val;
    }
}

