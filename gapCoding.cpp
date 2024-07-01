#include <iostream>
#include <array>
#include <vector>

std::vector<int> calculateGapCoding(const std::vector<int>& arr) {
    std::vector<int> gapCoding;
    gapCoding.push_back(arr[0]);

    for (int i = 1; i < arr.size(); i++) {
        int gap = arr[i] - arr[i - 1];
        gapCoding.push_back(gap);
    }

    return gapCoding;
}

int main() {
    std::array<int, 7> myArray = {1, 5, 9, 16, 19, 24, 34}; 
    // Declaración e inicialización

    // Imprimir los elementos del arreglo
    for (int i = 0; i < myArray.size(); i++) {
        std::cout << "Elemento " << i << ": " << myArray[i] << std::endl;
    }
    
    // Convertir std::array a std::vector
    std::vector<int> myVector(myArray.begin(), myArray.end());
    
    // Calcular el gap coding
    std::vector<int> GPCoding = calculateGapCoding(myVector);
    
    // Imprimir los elementos del gap coding
    for (int i = 0; i < GPCoding.size(); i++) {
        std::cout << "Gap coding " << i << ": " << GPCoding[i] << std::endl;
    }

    return 0;
}