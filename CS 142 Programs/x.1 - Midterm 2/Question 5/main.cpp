#include <iostream>
#include <vector>

using namespace std;

void PrintVector(const vector<int> ctrlVector);
void ReverseVector(vector<int>& ctrlVector);

int main() {
    int vectorSize;
    int multiplier;
    unsigned int i;

    cin  >> vectorSize;                             // Sets size of user vector
    cin  >> multiplier;                             // Sets the multiplying factor

    vector<int> userVector(vectorSize);             // Declares a vector of size determined by user

    for (i = 0; i < userVector.size(); i++) {       // Multiplies all values in vector by the user set multiplying factor.
        userVector.at(i) = i * multiplier;
    }

    PrintVector(userVector);                        // Prints vector
    ReverseVector(userVector);                      // Reverses vector
    PrintVector(userVector);                        // Prints new vector

    return 0;
}

void PrintVector(const vector<int> ctrlVector) {    // Prints the current vector
    unsigned int i;
    for (i = 0; i < ctrlVector.size(); i++) {
        cout << ctrlVector.at(i) << endl;
    }
}

void ReverseVector(vector<int>& ctrlVector) {       // Reverses the order of the vector elements
    int tmpValue;
    unsigned int i;

    for (i = 0; i < (ctrlVector.size() / 2); ++i) {
        tmpValue = ctrlVector.at(i);                                    // sets the temp value to the vector value at element i
        ctrlVector.at(i) = ctrlVector.at(ctrlVector.size() - 1 - i);    // sets the vector value at element i to the equivalent value on 'other side' of the vector
        ctrlVector.at(ctrlVector.size() - 1 - i) = tmpValue;            // sets the value on 'other side' of vector to temp value
    }
}