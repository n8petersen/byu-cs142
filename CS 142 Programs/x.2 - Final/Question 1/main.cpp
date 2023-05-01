#include <iostream>

void PrintForward(int array[], int arraySize);
void PrintBackward(int array[], int arraySize);

int main() {
    const int ARRAY_SIZE = 12;
    int multiplier;
    int array[ARRAY_SIZE];
    int i;

    std::cin  >> multiplier; // Inputs the array multiplier

    for (i = 0; i < ARRAY_SIZE; i++) { // Multiplies each array element by the multiplier
        array[i] = i * multiplier;
    }

    PrintForward(array, ARRAY_SIZE);
    PrintBackward(array, ARRAY_SIZE);
}

void PrintForward(int array[], int arraySize) { // Prints the array in order
    int i;
    for (i = 0; i < arraySize; i++) {
        std::cout << array[i] << std::endl;
    }
}

void PrintBackward(int array[], int arraySize) { // Prints the array in reverse order
    int i;

    for (i = arraySize - 1; i >= 0 ; i--) {
        std::cout << array[i] << std::endl;
    }
}