#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>
#include <unordered_map>

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
void printCodes(struct HuffmanNode* root, std::string str, std::unordered_map<int, std::string> &huffmanCode);

// Función para generar los códigos de Huffman
void HuffmanCodes(int data[], int freq[], int size, std::unordered_map<int, std::string> &huffmanCode);

#endif // HUFFMAN_H
