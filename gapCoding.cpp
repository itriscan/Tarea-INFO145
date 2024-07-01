#include <iostream>
#include <array>

// Definición de una plantilla de función para calcular el gap coding de un std::array
template <std::size_t N>
std::array<int, N> calculateGapCoding(const std::array<int, N>& arr) {
    std::array<int, N> gapCoding;
    gapCoding[0] = arr[0];

    for (std::size_t i = 1; i < N; i++) {
        int gap = arr[i] - arr[i - 1];
        gapCoding[i] = gap;
    }

    return gapCoding;
}

int main() {
    std::array<int, 7> myArray = {2, 5, 9, 16, 19, 24, 34}; 
    // Declaración e inicialización

    // Imprimir los elementos del arreglo
    for (std::size_t i = 0; i < myArray.size(); i++) {
        std::cout << "Elemento " << i << ": " << myArray[i] << std::endl;
    }
    
    // Calcular el gap coding
    std::array<int, 7> GPCoding = calculateGapCoding(myArray);
    
    // Imprimir los elementos del gap coding
    for (std::size_t i = 0; i < GPCoding.size(); i++) {
        std::cout << "Gap coding " << i << ": " << GPCoding[i] << std::endl;
    }

    return 0;
}
