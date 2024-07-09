#include "huffman.h"
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

// Función para imprimir los códigos de Huffman
void printCodes(HuffmanNode* root, string str, unordered_map<int, string> &huffmanCode) {
    if (!root)
        return;

    if (root->data != -1)
        huffmanCode[root->data] = str;

    printCodes(root->left, str + "0", huffmanCode);
    printCodes(root->right, str + "1", huffmanCode);
}

// Función para construir el árbol de Huffman
HuffmanNode* buildHuffmanTree(priority_queue<HuffmanNode*, vector<HuffmanNode*>, compare> &Q) {
    while (Q.size() >= 2) {
        HuffmanNode *z = new HuffmanNode(-1, 0); // Crear un nuevo nodo z
        z->left = Q.top(); // Extraer el nodo con la menor frecuencia
        Q.pop();
        z->right = Q.top(); // Extraer el siguiente nodo con la menor frecuencia
        Q.pop();
        z->freq = z->left->freq + z->right->freq; // Sumar las frecuencias
        Q.push(z); // Insertar el nuevo nodo z en la cola de prioridad
    }
    return Q.top(); // Devolver el nodo raíz del árbol de Huffman
}

// Función para generar los códigos de Huffman
void HuffmanCodes(int data[], int freq[], int size, unordered_map<int, string> &huffmanCode) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, compare> Q;

    for (int i = 0; i < size; ++i){
        //cout << "Dato: " << data[i] <<" Frecuencia: " << freq[i] << endl;
        Q.push(new HuffmanNode(data[i], freq[i]));
        
    }
    HuffmanNode* root = buildHuffmanTree(Q);

    printCodes(root, "", huffmanCode);
}

void printHuffmanTree(HuffmanNode* root, int prof) {
    if (root == nullptr)
        return;

    for (int i = 0; i < prof; ++i)
        cout << "  ";
    
    cout << root->freq;
    
    if (root->data != -1)
        cout << " (" << root->data << ")";
    
    cout << endl;

    printHuffmanTree(root->left, prof + 1);
    printHuffmanTree(root->right, prof + 1);
}

void calculaFrecuenciasDataFreq (int* arreglo, int size, unordered_map<int, int>& freqMap, int*& data, int*& freq){
    for (int i = 0; i < size; ++i) {
        freqMap[arreglo[i]]++;
    }

    data = new int[freqMap.size()];
    freq = new int[freqMap.size()];

    int index = 0;
    for (auto& pair : freqMap) {
        data[index] = pair.first;
        freq[index] = pair.second;
        index++;
    }


}