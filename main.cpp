#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <unordered_map>
#include <vector>
#include "distribuciones.h"
#include "gapCandSample.h"
#include "huffman.h"
#include <bitset>

using namespace std;

void imprimeArreglo (int* A, int n);
unsigned int binaryStringToInt(const string &binaryString);

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
    dNormal(n, 100000000, 1000, B, semilla);
    gapCoding(n, A, gapsA);
    createSample(n, A, sampleA, m ,b);
    cout << "Imprime el arreglo A " << endl;
    //imprimeArreglo(A, n);
    imprimeArreglo(gapsA, n);
    imprimeArreglo(sampleA, m);
    
    unordered_map<int, int> freqMapA;
    int* data = nullptr;
    int* freq = nullptr;
    //Toma el arreglo gap-coding y llena data y freq, con el dato y su frecuencia respectivamente
    calculaFrecuenciasDataFreq(gapsA, n, freqMapA, data, freq);

    //Se asignan los códigos de Huffman a cada elemento y se crea el árbol de Huffman
    unordered_map<int,string> huffmanCode;
    HuffmanCodes(data, freq, freqMapA.size(), huffmanCode);

    // Imprimir los códigos de Huffman
    cout << "Imprimir los códigos de Huffman" << endl;
    for (auto& pair : huffmanCode) {
        cout << pair.first << " " << pair.second << endl;
    }



    // Aplicar la codificación a gapsA
    vector<unsigned int> datosComprimidosA;
    for (int i = 0; i < n; ++i) {
        datosComprimidosA.push_back(binaryStringToInt(huffmanCode[gapsA[i]]));
    }

    // Imprimir los datos comprimidos
    cout << "Imprimir los datos comprimidos" << endl;
    for (auto& code : datosComprimidosA) {
        cout << bitset<16>(code) << " ";
    }

    delete[] A;
    delete[] B;
    delete[] gapsA;
    delete[] sampleA;
    delete[] data;
    delete[] freq;

    cout << "##################################################################################" << endl;
    return 0;
}