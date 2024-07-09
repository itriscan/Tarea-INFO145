#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <unordered_map>
#include <string>
#include <vector>
#include <queue>

// Estructura del nodo de Huffman
struct HuffmanNode {
    int data;
    unsigned freq;
    HuffmanNode *left, *right;

    HuffmanNode(int data, unsigned freq) {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

// Comparador para la cola de prioridad
struct compare {
    bool operator()(HuffmanNode* l, HuffmanNode* r) {
        return (l->freq > r->freq);
    }
};

// Función para imprimir los códigos de Huffman
void printCodes(HuffmanNode* root, std::string str, std::unordered_map<int, std::string> &huffmanCode);

// Función para generar los códigos de Huffman
void HuffmanCodes(int data[], int freq[], int size, std::unordered_map<int, std::string> &huffmanCode);

// Función para construir el árbol de Huffman
HuffmanNode* buildHuffmanTree(std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, compare> &Q);

void printHuffmanTree(HuffmanNode* root, int prof = 0);

void calculaFrecuenciasDataFreq (int* inputArray, int size, std::unordered_map<int, int>& freqMap, int*& data, int*& freq);

#endif // HUFFMAN_H
