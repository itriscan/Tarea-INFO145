#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <unordered_map>
#include <vector>
#include "distribuciones.h"
#include "gapCandSample.h"
#include "huffman.h"

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
    //imprimeArreglo(A, n);
    imprimeArreglo(gapsA, n);
    imprimeArreglo(sampleA, m);
    // Calcular frecuencias
    std::unordered_map<int, int> freqMap;
    for (int i = 0; i < n; ++i) {
        freqMap[gapsA[i]]++;
    }

    // Crear arreglos de datos y frecuencias
    int* data = new int[freqMap.size()];
    int* freq = new int[freqMap.size()];
    int index = 0;
    for (auto& pair : freqMap) {
        data[index] = pair.first;
        freq[index] = pair.second;
        index++;
    }

    std::unordered_map<int, std::string> huffmanCode;
    HuffmanCodes(data, freq, freqMap.size(), huffmanCode);

    // Imprimir los códigos de Huffman
    for (auto& pair : huffmanCode) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    // Aplicar la codificación a gapsA
    std::vector<std::string> compressedData;
    for (int i = 0; i < n; ++i) {
        compressedData.push_back(huffmanCode[gapsA[i]]);
    }

    // Imprimir los datos comprimidos
    for (auto& code : compressedData) {
        std::cout << code << " ";
    }
    std::cout << std::endl;

    delete[] A;
    delete[] B;
    delete[] gapsA;
    delete[] sampleA;
    delete[] data;
    delete[] freq;

    std::cout << "##################################################################################" << std::endl;
    return 0;
}