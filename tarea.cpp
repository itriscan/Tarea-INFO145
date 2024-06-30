#include <iostream>
#include <stdlib.h>
#include <cstdlib> // Para usar rand
#include <random> // Para usar la desviación estandar
#include <ctime> // Para medir el tiempo
#include <algorithm> //Para usar sort

using namespace std;

int dLineal (int n, int e, int* A);
void dNormal(int n, int media, int desviacionEstandar, int* A, int semilla);
void imprimeArreglo (int* A, int n);

int dLineal (int n, int e, int* A){
    A[0] = rand();
    for(int i = 1; i < n; i++){
        A[i] = A[i-1] + (rand()% e);
    }
    return 0;
}
void dNormal(int n, int media, int desviacionEstandar, int* A, int semilla){
    default_random_engine generador(semilla);
    normal_distribution<double> distribucion(media, desviacionEstandar);

    for (int i = 0; i < n; ++i) {
        A[i] = static_cast<int> (distribucion(generador));
    }
    sort(A, A + n); // Usa introsort

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

    srand(semilla); // Inicializar la semilla para rand()
    cout << "##################################################################################" << endl;
    unsigned long t0,t1;
    int* A = new int[n];
    int* B = new int[n];
    t0 = clock();
    dLineal(n, 20, A);
    t1 = clock();
    cout << "El tiempo de ejecución para dLineal es: " << double(t1-t0)/CLOCKS_PER_SEC << " seg."<< endl;
    t0 = clock();
    dNormal(n,1000000,1000,B, semilla);
    t1 = clock();
    cout << "El tiempo de ejecución para dNormal es: " << double(t1-t0)/CLOCKS_PER_SEC << " seg."<< endl;
    
    //imprimeArreglo(B, n);
    //cout << "El tamaño en memoria del arreglo que contiene " << n << " elementos es: "<< sizeof(A)*n << " bits."<< endl;
    delete[] B; // Liberar la memoria asignada
    cout << "##################################################################################" << endl;
    return 0;
}