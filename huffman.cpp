#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

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

void printCodes(struct HuffmanNode* root, std::string str, std::unordered_map<int, std::string> &huffmanCode) {
    if (!root)
        return;
    if (root->data != -1)
        huffmanCode[root->data] = str;
    printCodes(root->left, str + "0", huffmanCode);
    printCodes(root->right, str + "1", huffmanCode);
}

void HuffmanCodes(int data[], int freq[], int size, std::unordered_map<int, std::string> &huffmanCode) {
    struct HuffmanNode *left, *right, *top;

    // Crear una cola de prioridad (mínima)
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, compare> minHeap;

    for (int i = 0; i < size; ++i)
        minHeap.push(new HuffmanNode(data[i], freq[i]));

    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new HuffmanNode(-1, left->freq + right->freq);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    printCodes(minHeap.top(), "", huffmanCode);
}

