#include <iostream>
#include <stdlib.h>
#include <cmath>
#include "distribuciones.h"
#include "gapCandSample.h"

using namespace std;
void imprimeArreglo (int* A, int n);
void imprimeArreglo (int* A, int n){
    cout << "[";
    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    cout << "]" << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Debe ejecutarse como ./tarea <n> <semilla>" << endl;
        return EXIT_FAILURE;
    }

    int n = atoi(argv[1]); // Convertir argv[1] a entero
    int semilla = atoi(argv[2]);

    if (n <= 0) {
        cout << "El tamaño del arreglo debe ser un entero positivo." << endl;
        return 1;
    }

    srand(semilla); // Inicializar la semilla para rand()
    cout << "##################################################################################" << endl;

    int* A = new int[n];
    int* B = new int[n];
    int m = static_cast<int>(floor(log(n) / log(3))); // log base 3 de n
    int b = n / m; // piso de la división
    int* gapsA = new int[n];
    int* sampleA = new int[m];
    int* gapsB = new int[n];
    int* sampleB = new int[m];

    dLineal(n, 20, A);
    dNormal(n, 100000000, 1000, B, semilla);
    gapCoding(n, A, gapsA);
    createSample(n, A, sampleA, m ,b);
    cout << "Imprime el arreglo A " << endl;
    imprimeArreglo(A, n);
    imprimeArreglo(gapsA, n);
    imprimeArreglo(sampleA, m);
    cout << "Imprime el arreglo B " << endl;
    imprimeArreglo(B, n);
    imprimeArreglo(gapsB, n);
    imprimeArreglo(sampleB, m);

    delete[] A;
    delete[] B; // Liberar la memoria asignada

    cout << "##################################################################################" << endl;
    return 0;
}