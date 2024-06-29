#include <iostream>
#include <stdlib.h>
#include <cstdlib> // Para usar rand
#include <ctime> // Para medir el tiempo

using namespace std;

int DLineal (int n, int e, int* A);
void imprimeArreglo (int* A, int n);

int DLineal (int n, int e, int* A){
    A[0] = rand();
    for(int i = 1; i < n; i++){
        A[i] = A[i-1] + (rand()% e);
    }
    return 0;
}
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

    srand(time(0)); // Inicializar la semilla para rand(), debo ver el tipo de dato que recibe

    int* A = new int[n];

    DLineal(n, 3, A);
    imprimeArreglo(A, n);

    delete[] A; // Liberar la memoria asignada

    return 0;
}