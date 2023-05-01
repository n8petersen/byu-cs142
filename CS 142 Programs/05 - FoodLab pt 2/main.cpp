#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

void AreHungry(); // Function Declarations
void SweetOrSalty();
void HealthyOrNah();
void AreYouSure();
int Budget(int cash, int spending);

int main() { // main function starts the whole program
    int numPlays;

    cout << "what should I have for dinner?" << endl << endl;

    cout << "how many times do you want to play?" << endl << "(0 for random between 1-5): ";
    cin  >> numPlays;
    cout << endl;

    if (numPlays == 0) { // if user inputs 0, randomly generates number between 1-5
        srand(time(0)); // ensures the rand function will generate truly random numbers everytime it is ran
        numPlays = (rand() % 5) + 1;
    }

    cout << "will play " << numPlays << " time(s)" << endl;
    sleep_for(seconds(1)); // program pauses for 1 second

    for (int i = 0; i < numPlays; ++i) { // plays game n amount of times (user specified or randomly generated)
        cout << endl;
        AreHungry();

        cout << endl << "played " << i + 1 << "/" << numPlays << " times" << endl;
        sleep_for(seconds(1)); // program pauses for 1 second
    }

    return 0;
}

void AreHungry() { // answers the first branch, determines how hungry the user is. If the user is hungry, it will ask some basic financial questions.
    int varHungry = 0;

    while (varHungry < 1 || varHungry > 3) {
        cout << "are you hungry?" << endl;
        cout << "1: kinda   2. yes   3. no <3" << endl;

        cin  >> varHungry;

        if (varHungry == 1) {
            SweetOrSalty();
        } else if (varHungry == 2) {
            int cashOnHand = 2;
            int spending = 1;

            spending:
            cout << "how much money do you have on you (in dollars)?" << endl;
            cin >> cashOnHand;
            cout << endl;

            cout << "how much are you willing to spend (dollars)?" << endl;
            cin >> spending;
            cout << endl;

            if (spending > cashOnHand) {
                cout << "buddy you can't spend more money than you have" << endl;
                goto spending;
            }

            cout << Budget(cashOnHand, spending) << " dollar(s) left" << endl;
        } else if (varHungry == 3) {
            cout << "have a nice glass of air :)" << endl;
        }
    }
}

void SweetOrSalty() { // if the user answered they're kinda hungry, it will ask if they want a sweet or a salty snack
    int varSweet = 0;

    while (varSweet < 1 || varSweet > 2) {
        cout << "do you want something sweet or salty?" << endl;
        cout << "1. sweet   2. salty" << endl;
        cin >> varSweet;

        if (varSweet == 1) {
            HealthyOrNah();
        } else if (varSweet == 2) {
            cout << "eat some pretzels" << endl;
        }
    }
}

void HealthyOrNah() { // if the user says they want something sweet, program will ask if they want that sweet thing to be healthy or not
    int varHealthy = 0;

    while (varHealthy < 1 || varHealthy > 2) {
        cout << "do you want something healthy or nah?" << endl;
        cout << "1. healthy   2. nah" << endl;
        cin >> varHealthy;

        if (varHealthy == 1) {
            AreYouSure();
        } else if (varHealthy == 2) {
            cout << "get yourself an ice cream, king" << endl;
        }
    }
}

void AreYouSure() { // if the user answers they want to eat something healthy, program will confirm that decision
    int varSure = 0;

    while ( varSure < 1 || varSure > 2) {
        cout << "are you sure about that?" << endl;
        cout << "1. yes sadly   2. nah u right" << endl;
        cin >> varSure;

        if (varSure == 1) {
            cout << "ouch. go eat a fruit cup or somethin then" << endl;
        } else if (varSure == 2) {
            cout << "yeah, get yourself an ice cream, king" << endl;
        }
    }
}

int Budget(int cash, int budget) { // will take the numbers given earlier to decide what the user's budget will allow
    int remainder;

    if (budget < 4) {
        cout << "have a nice glass of air :)" << endl;
        remainder = cash;
    }
    else if (budget >= 25) {
        cout << "texas road house all the way, lets party" << endl;
        remainder = cash - budget;
    }
    else {
        cout << "looks like we're gettin a wendy's 4 for $4 baby" << endl;
        remainder = cash - 4;
    }
    return remainder;
}

