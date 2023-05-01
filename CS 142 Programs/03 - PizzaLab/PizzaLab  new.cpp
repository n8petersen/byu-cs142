#include <iostream>
#include <cmath>
using namespace std;

const double VAR_PI = 3.14159265;

const double LARGE_DIAMETER = 20.0;
const double MEDIUM_DIAMETER = 16.0;
const double SMALL_DIAMETER = 12.0;
const double LARGE_PRICE = 14.68;
const double MEDIUM_PRICE = 11.48;
const double SMALL_PRICE = 7.28;
const int LARGE_FEEDS = 7;
const int MEDIUM_FEEDS = 3;
const int SMALL_FEEDS = 1;

// This function calculates the sum area of each pizza size, given the diameter and quantity
double CalculateArea(double pizzaDiameter, int numPizzas) {
    double pizzaArea = VAR_PI * pow((pizzaDiameter / 2.0), 2);
    double sumArea = pizzaArea * numPizzas;

    return sumArea;
}

// This function calculates the sum cost of each pizza size, given the diameter and quantity
double CalculatePrice(double pricePerPizza, int numPizzas) {
    double sumPizzaCost = pricePerPizza * numPizzas;

    return sumPizzaCost;
}

int main() {
    double areaTotal = 0.0;
    double avgArea = 0.0;
    int numGuests = 0;
    int remGuests = 0;
    int numLarge = 0;
    int numMedium = 0;
    int numSmall = 0;
    double percentTip = 0.0;
    double subTotalCost = 0.0;
    double totalCost = 0.0;

    cout << "Please enter how many guests to order for: ";
    cin  >> numGuests;
    cout << endl;

  // Number of each pizza size is calculated given number of guests and number of people each pizza feeds.
    numLarge = numGuests / LARGE_FEEDS;
    remGuests = numGuests % LARGE_FEEDS;
    numMedium = remGuests / MEDIUM_FEEDS;
    remGuests = remGuests % MEDIUM_FEEDS;
    numSmall = remGuests / SMALL_FEEDS;
    cout << numLarge << " large pizzas, " << numMedium << " medium pizzas, and " << numSmall << " small pizzas will be needed." << endl << endl;

    // Calculates the total area and of pizza using function for each pizza size, as well as the area per guest.
    areaTotal = CalculateArea(LARGE_DIAMETER, numLarge) + CalculateArea(MEDIUM_DIAMETER, numMedium) + CalculateArea(SMALL_DIAMETER, numSmall);
    avgArea = areaTotal / numGuests;
    cout << "A total of " << areaTotal << " square inches of pizza will be ordered (" << avgArea << " per guest)." << endl << endl;

    cout << "Please enter the tip as a percentage (i.e. 10 means 10%): "; // Prompts user to input tip percentage
    cin  >> percentTip;
    cout << endl;

    subTotalCost = CalculatePrice(LARGE_PRICE, numLarge) + CalculatePrice(MEDIUM_PRICE, numMedium) + CalculatePrice(SMALL_PRICE, numSmall);
    totalCost = subTotalCost + subTotalCost * (percentTip / 100);
    cout << "The total cost of the event will be: $" << round(totalCost) << endl;

    return 0;
}