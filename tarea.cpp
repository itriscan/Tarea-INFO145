#include <iostream>
#include <stdlib.h>
#include <cstdlib> // Para usar rand
#include <random> // Para usar la desviación estandar
#include <ctime> // Para medir el tiempo
#include <algorithm> //Para usar sort


using namespace std;

int dLineal (int n, int e, int* A);
void dNormal(int n, int media, int desviacionEstandar, int* A, int semilla);
void gapCoding(int n, int* A, int* G);
void createSample(int n, int* A, int* sample, int m, int b);
void imprimeArreglo (int* A, int n);
int busquedaBinaria(int n, const int* A, int s);

int busquedaBinaria(int n, const int* A, int s){
    int l = 0;
    int r = n - 1;
    
    while (l <= r)
    {
        int mid = (l + r)/2;
        if(A[mid] == s){
            return mid;
        }
        if (A[mid] < s){
            
            l = mid+1;
        }else{
            r = mid - 1;
        }
    }
    return -1;
}

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
void gapCoding(int n, int* A, int* G){
    //int* gaps = new int[n];
    G[0] = A[0];
    for(int i = 1; i < n; i++){
        G[i] = A[i] - A[i-1];
    }
}

void createSample(int n, int* A, int* sample, int m, int b) {
    // Asignar el primer elemento del sample
    sample[0] = A[0];

    // Llenar el arreglo sample
    int acum = b;
    for (int i = 1; i < m; ++i) {
        sample[i] = A[acum];
        acum += b;
    }
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
    int m = static_cast<int>(floor(log(n) / log(3))); // log base 3 de n
    int b = n / m; // piso de la división
    int* gapsA = new int[n];
    int* sampleA = new int[m];
    int* gapsB = new int[n];
    int* sampleB = new int[m];
    //t0 = clock();
    dLineal(n, 20, A);
    //t1 = clock();
    //cout << "El tiempo de ejecución para dLineal es: " << double(t1-t0)/CLOCKS_PER_SEC << " seg."<< endl;
    //t0 = clock();
    dNormal(n,1000000,1000,B, semilla);
    //t1 = clock();
    //cout << "El tiempo de ejecución para dNormal es: " << double(t1-t0)/CLOCKS_PER_SEC << " seg."<< endl;
    gapCoding(n, A, gapsA);
    createSample(n, A, sampleA, m ,b);
    imprimeArreglo(A, n);
    imprimeArreglo(gapsA, n);
    imprimeArreglo(sampleA, m);
    

    delete[] A;
    delete[] B; // Liberar la memoria asignada
    cout << "##################################################################################" << endl;
    return 0;
}