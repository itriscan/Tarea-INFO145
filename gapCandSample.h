#ifndef CODIFICACIONES_H
#define CODIFICACIONES_H

void gapCoding(int n, int* A, int* G);
void createSample(int n, int* A, int* sample, int m, int b);
void reconstruirArregloDesdeSample(int* gaps, int* sample, int ini, int fin, int* reconstruido, int b);


#endif