#include <iostream>
using namespace std;

const int MIN_LAT = 31;    // Defines boundaries and center lines
const int MID_LAT = 37;
const int MAX_LAT = 41;
const int MIN_LONG = 102;
const int MID_LONG = 109;
const int MAX_LONG = 114;

int main() {
    double latitude;
    double longitude;
    string state;

    cout << "Please enter the latitude of the position: ";  // Gets latitude of coordinate from user
    cin  >> latitude;
    cout << endl;

    cout << "Please enter the longitude of the position: "; // Gets longitude of coordinate from user
    cin  >> longitude;
    cout << endl;

    if (latitude > MAX_LAT) {                  // Checks if Latitude is outside of latitude boundaries
        state = "the North";
    }
    else if (latitude < MIN_LAT) {             //  ^^^
        state = "the South";
    }
    else if (latitude > MID_LAT) {             // Checks if latitude is outside of longitude boundaries
        if (longitude > MAX_LONG) {
            state = "the West";
        }
        else if (longitude < MIN_LONG) {       // ^^^
            state = "the East";
        }
        else if (longitude > MID_LONG) {       // If coordinate falls in top right, set state to Utah
            state = "Utah";
        }
        else if (longitude < MID_LONG) {       // If coordinate falls in top right, set state to Colorado
            state = "Colorado";
        }
    }
    else if (latitude < MID_LAT ) {             // Checks if latitude is outside of longitude boundaries
        if (longitude > MAX_LONG) {
            state = "the West";
        }
        else if (longitude < MIN_LONG) {        // ^^^
            state = "the East";
        }
        else if (longitude > MID_LONG) {        // If coordinate falls in top right, set state to Arizona
            state = "Arizona";
        }
        else if (longitude < MID_LONG) {        // If coordinate falls in top right, set state to New Mexico
            state = "New Mexico";
        }
    }

    cout << "The position is found in " << state << endl; // Output the coordinate location

    return 0;
}
