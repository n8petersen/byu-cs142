#include <iostream>
#include <vector>
using namespace std;

void RemoveEvenNums(vector<int>& numbers);

int main() {
    vector<int> numbers = { 2, 4, 6, 8, 10 };
    unsigned int i ;
    int n;

    cout << "starting vector: " << endl;
    cout << "size: " << numbers.size() << endl;
    for (i = 0; i < numbers.size(); i++) {
        n = numbers.at(i);
        cout << i << ": " << n << endl;
    }
    cout << endl;

    cout << "removing values: " << endl;
    RemoveEvenNums(numbers);

    std::cout << std::endl << "new vector: " << endl;
    cout << "size: " << numbers.size() << endl;
    for (i = 0; i < numbers.size(); i++) {
        std::cout << numbers.at(i) << std::endl;
    }

    return 0;
}

void RemoveEvenNums(vector<int>& numbers) {
    unsigned int i;
    int n;

    for (i = 0; i < numbers.size(); i++) {
        n = numbers.at(i);
        if (n % 2 == 0) {
            numbers.erase(numbers.begin() + i);
            i = i - 1;
        }
    }
}