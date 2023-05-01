#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int PLATE_SIZE = 10;
const int LAST_ROW_INDEX = PLATE_SIZE - 1;
const int PRECISION = 3;
const int WIDTH = 9;

// Given a plate array, updates each non-border cell by taking the average of the former cell's neighbors.
// Returns true if steady plate reached.
bool UpdatePlate(double plate[PLATE_SIZE][PLATE_SIZE])
{
    double tempPlate[PLATE_SIZE][PLATE_SIZE];
    double maxChange = 0.0;

    // Copy plate to tempPlate
    for (int i = 0; i < PLATE_SIZE; i++)
    {
        for (int j = 0; j < PLATE_SIZE; j++)
        {
            tempPlate[i][j] = plate[i][j];
        }
    }

    // Updates the values of plate by taking average of neighboring cells.
    for (int i = 1; i < PLATE_SIZE - 1; i++)
    {
        for (int j = 1; j < PLATE_SIZE - 1; j++)
        {
            plate[i][j] = (tempPlate[i - 1][j] + tempPlate[i][j + 1] + tempPlate[i + 1][j] + tempPlate[i][j - 1]) / 4.0;
        }
    }

    // Checks for the max change between the new and previous iterations.
    for (int i = 1; i < PLATE_SIZE - 1; i++)
    {
        for (int j = 1; j < PLATE_SIZE - 1; j++)
        {
            if ((plate[i][j] - tempPlate[i][j]) > maxChange)
            {
                maxChange = plate[i][j] - tempPlate[i][j];
            }
        }

    }
    if (maxChange < 0.1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Given a plate array, outputs the array to the console.
void OutputPlate(double plate[PLATE_SIZE][PLATE_SIZE])
{
    for (int i = 0; i < PLATE_SIZE; i++)
    {
        for (int j = 0; j < PLATE_SIZE; j++)
        {
            cout << setw(WIDTH) << plate[i][j];
            if (j != PLATE_SIZE - 1)
            {
                cout << ',';
            }
        }
        cout << endl;
    }
}

// main function
int main()
{
    ofstream outFS;
    ifstream inFS;
    double hotPlate[PLATE_SIZE][PLATE_SIZE];
    bool isFinalPlate;

    cout << fixed << setprecision(PRECISION);

    // Set all values to 0.0
    for (int i = 0; i < PLATE_SIZE; i++)
    {
        for (int j = 0; j < PLATE_SIZE; j++)
        {
            hotPlate[i][j] = 0.0;
        }
    }

    // Set middle top columns to 100.0
    for (int j = 1; j < PLATE_SIZE - 1; j++)
    {
        hotPlate[0][j] = 100.0;
    }

    // Set middle bottom columns to 100.0
    for (int j = 1; j < PLATE_SIZE - 1; j++)
    {
        hotPlate[LAST_ROW_INDEX][j] = 100.0;
    }

    cout << "Hotplate simulator" << endl << endl;
    cout << "Printing the initial plate values..." << endl;
    OutputPlate(hotPlate);
    cout << endl;

    cout << "Printing plate after one iteration..." << endl;
    UpdatePlate(hotPlate);
    OutputPlate(hotPlate);
    cout << endl;

    // Update the plate array until each cell changes by less than 0.1
    do
    {
        isFinalPlate = UpdatePlate(hotPlate);
    } while (!isFinalPlate);

    cout << "Printing final plate..." << endl;
    OutputPlate(hotPlate);
    cout << endl;

    // Open output file
    outFS.open("Hotplate.csv");

    // Checks if file opens
    if (!outFS.is_open())
    {
        cout << "Could not open file Hotplate.csv" << endl;
        return 1;
    }

    // Write array to output file
    cout << "Writing final plate to \"Hotplate.csv\"..." << endl << endl;
    outFS << fixed << setprecision(PRECISION);
    for (int i = 0; i < PLATE_SIZE; i++)
    {
        for (int j = 0; j < PLATE_SIZE; j++)
        {
            outFS << setw(WIDTH) << hotPlate[i][j];
            if (j != PLATE_SIZE - 1)
            {
                outFS << ',';
            }
        }
        outFS << endl;
    }

    // Close output file
    outFS.close();

    // Open input file
    inFS.open("Inputplate.txt");

    // Checks if file opens
    if (!inFS.is_open())
    {
        cout << "Could not open file \"Inputplate.txt\"" << endl;
        return 1;
    }

    // Inputs hotPlate array from file
    for (int i = 0; i < PLATE_SIZE; i++)
    {
        for (int j = 0; j < PLATE_SIZE; j++)
        {
            inFS >> hotPlate[i][j];
        }
    }

    // Update the plate three times.
    for (int i = 0; i < 3; i++)
    {
        UpdatePlate(hotPlate);
    }

    cout << "Printing input plate after 3 updates..." << endl;
    OutputPlate(hotPlate);

    return 0;
}