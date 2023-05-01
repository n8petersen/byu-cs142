#include <iostream>
using namespace std;

int main() {
    const int NUM_ELEMENTS = 10;
    int array[NUM_ELEMENTS];
    int i;
    int tempVal;

    for (i = 0; i < NUM_ELEMENTS; ++i) {         // Inputs values to array
        cin  >> array[i];
    }

    for (i = 0; i < NUM_ELEMENTS; ++i) {         // Converts array to show if divisible by 2
        if (array[i] % 2 == 1 || array[i] % 2 == -1 ) {                 // 1 = divisible by 2
            array[i] = 0;                                               // 0 = not divisible by 2
        }
        else {
            array[i] = 1;
        }
    }

    for (i = 0; i < (NUM_ELEMENTS / 2); ++i) {  // Reverses array
        tempVal = array[i];                           // Temp for swap
        array[i] = array[NUM_ELEMENTS - 1 - i];       // First part of swap
        array[NUM_ELEMENTS - 1 - i] = tempVal;        // Second complete
    }

    for (i = 0; i < NUM_ELEMENTS; ++i) {    // Outputs array
        cout << array[i] << endl;
    }

    return 0;
}
