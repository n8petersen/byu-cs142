#include <iostream>
#include <cmath>
using namespace std;

int main() {
   const double varPi = 3.14159265;       // Declares constant for pi
   const double LARGE_DIAMETER = 20.0;    // Declares constants the various pizza diameters
   const double MEDIUM_DIAMETER = 16.0;
   const double SMALL_DIAMETER = 12.0;
   const double LARGE_PRICE = 14.68;    // Declares constants for the pizza prices
   const double MEDIUM_PRICE = 11.48;   
   const double SMALL_PRICE = 7.28;
   const int LARGE_FEEDS = 7;             // Declares constants for how many people each pizza size can feed
   const int MEDIUM_FEEDS = 3;
   double sumPriceLarge = 0.0;      // Declares doubles for sum prices of each pizza size
   double sumPriceMedium = 0.0;
   double sumPriceSmall = 0.0;
   double areaLarge = 0.0;                // Declares doubles for each pizza size's area (per pizza)
   double areaMedium = 0.0;
   double areaSmall = 0.0;
   double sumAreaLarge = 0.0;             // Declares doubles for the sum areas for each pizza size
   double sumAreaMedium = 0.0;
   double sumAreaSmall = 0.0;
   double areaTotal = 0.0;                // Declares doubles of total area of pizza
   double avgArea = 0.0;
   int numGuests = 0;                     // Declares integer variable for amount of guests
   int numLarge = 0;                      // Declares integer variables for number of pizzas per each size
   int numMedium = 0;
   int numSmall = 0;
   double percentTip = 0.0;                    // Declares double for tip percentage
   double amtTip = 0.0;                   // Declares double for Tip Amount
   double subTotalCost = 0.0;       // Declares double for sub total before tip
   double totalCost = 0.0;          // Declares double for total cost
   
   cout << "Please enter how many guests to order for: ";
   cin  >> numGuests;
   cout << endl;

   
   int remGuests = 0;                     // Declares integer variable for remainder number of guests after Large is calculated
   numLarge = numGuests / LARGE_FEEDS;    // Calculates the number of large pizzas needed
   remGuests = numGuests % LARGE_FEEDS;   // Calculates the remainder number of guests 
   numMedium = remGuests / MEDIUM_FEEDS;  // Calculates the number of medium pizzas needed, based off the remainder of guests
   numSmall = remGuests % MEDIUM_FEEDS;   // Calculates the number of small pizzas needed
   cout << numLarge << " large pizzas, " << numMedium << " medium pizzas, and " << numSmall << " small pizzas will be needed." << endl << endl;
   
   areaLarge = varPi * pow((LARGE_DIAMETER / 2.0), 2);      // Calculates the area of a single large pizza
   sumAreaLarge = areaLarge * numLarge;                     // Calculates the sum area of all large pizzas
   areaMedium = varPi * pow((MEDIUM_DIAMETER / 2.0), 2);    // Calculates the area of a single medium pizza
   sumAreaMedium = areaMedium * numMedium;                  // Calculates the sum area of all medium pizzas
   areaSmall = varPi * pow((SMALL_DIAMETER / 2.0), 2);      // Calculates the area of a single small pizza
   sumAreaSmall = areaSmall * numSmall;                     // Calculates the sum area of all small pizzas
   areaTotal = sumAreaLarge + sumAreaMedium + sumAreaSmall; // Calculates the sum area of all pizzas
   avgArea = areaTotal / numGuests;
   cout << "A total of " << areaTotal << " square inches of pizza will be ordered (" << avgArea << " per guest)." << endl << endl;
   
   sumPriceLarge = numLarge * LARGE_PRICE;
   sumPriceMedium = numMedium * MEDIUM_PRICE;
   sumPriceSmall = numSmall * SMALL_PRICE;
   
   cout << "Please enter the tip as a percentage (i.e. 10 means 10%): ";   // Prompts user to input tip percentage
   cin  >> percentTip;
   cout << endl;
   
   subTotalCost = sumPriceLarge + sumPriceMedium + sumPriceSmall;          // Calculates subtotal before tip
   amtTip = subTotalCost * (percentTip / 100);                             // Calculates tip amount based on percentage and subtotal
   totalCost = subTotalCost + amtTip;                                      // Calculates total cost based on subtotal and tip amount
   totalCost = round(totalCost);
   cout << "The total cost of the event will be: $" << totalCost << endl;
   
   return 0;
}