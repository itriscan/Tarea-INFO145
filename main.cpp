#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <unordered_map>
#include <vector>
#include <bitset>
#include "distribuciones.h"
#include "gapCandSample.h"
#include "huffman.h"
#include "binarySearch.h"


using namespace std;

void imprimeArreglo (int* A, int n);
unsigned int binaryStringToInt(const string &binaryString);
void buscarElementoSampleYGaps(int n, int* A, int* gapsA, int* sampleA, int m, int b, int elementoBuscado);

void buscarElementoSampleYGaps(int n, int* A, int* gapsA, int* sampleA, int m, int b, int elementoBuscado) {
    // Encontrar el intervalo en el que se puede encontrar el elemento
    int i = 0;
    int ini, fin;
    while (i < m && elementoBuscado > sampleA[i]) {
        i++;
    }

    if (i == 0) {
        ini = 0;
        fin = b;
    } else {
        ini = (i - 1) * b;
        fin = (i < m) ? i * b : n; 
    }
    cout << "ini= " << ini << " fin= " << fin << endl;
    cout << "Intervalo de búsqueda en gapsA: [" << ini << ", " << fin << "]" << endl;

    // Reconstruir el arreglo dentro del intervalo
    int* reconstruido = new int[fin - ini];
    reconstruirArregloDesdeSample(gapsA, sampleA, ini, fin, reconstruido, b);

    // Imprimir el arreglo reconstruido
    cout << "Arreglo reconstruido... \n";
    //imprimeArreglo(reconstruido, fin - ini);

    // Aplicar la búsqueda binaria en el arreglo reconstruido
    cout << "\nAplicando busqueda binaria en el arreglo reconstruido...\n ";
    int posGaps = busquedaBinaria(fin - ini, reconstruido, elementoBuscado);

    if (posGaps != -1 && reconstruido[posGaps] == elementoBuscado) {
        cout << "Elemento encontrado en la posición reconstruida: " << posGaps << endl;
        cout << "Posición original en gapsA: " << ini + posGaps << endl;
    } else {
        cout << "Elemento no encontrado en la porción reconstruida de gapsA." << endl;
    }

    delete[] reconstruido;
}
 


unsigned int binaryStringToInt(const string &binaryString) {
    unsigned int num = 0;
    for (char bit : binaryString) {
        num = (num << 1) | (bit - '0');
    }
    return num;
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

    int* A = new int[n];
    int* B = new int[n];
    int m = static_cast<int>(floor(log(n) / log(3))); // log base 3 de n
    int b = n / m; // piso de la división
    int* gapsA = new int[n];
    int* sampleA = new int[m];
    int* gapsB = new int[n];
    int* sampleB = new int[m];

    dLineal(n, 20, A);
    dNormal(n, 1000000000, 1000, B, semilla);
    gapCoding(n, A, gapsA);
    createSample(n, A, sampleA, m ,b);
    gapCoding(n, B, gapsB);
    createSample(n, B, sampleB, m ,b);
    double t0,t1;
    // Supongamos que queremos encontrar un elemento en A
    int elementoBuscado = A[8]; // por ejemplo, buscamos el elemento en la mitad del arreglo original
    cout << "Elemento buscado:" << elementoBuscado << endl;
    t0 = (double) clock();
    buscarElementoSampleYGaps(n, A, gapsA, sampleA, m, b, elementoBuscado);
    t1 = (double) clock();
    cout << "El tiempo fue de : " << (double)(t1 -t0)/ CLOCKS_PER_SEC << " seg."<< endl;

    //imprimeArreglo(A, n);
    //imprimeArreglo(sampleB, m);
    
    

    delete[] A;
    delete[] B;
    delete[] gapsA;
    delete[] sampleA;
    delete[] gapsB;
    delete[] sampleB;
    

    cout << "##################################################################################" << endl;
    return 0;
}