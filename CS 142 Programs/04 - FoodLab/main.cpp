#include <iostream>
using namespace std;

void AreHungry();
void SweetOrSalty();
void HealthyOrNah();
void AreYouSure();
int Budget(int cash, int spending);

int main() { //main function starts the whole program

    cout << "what should I have for dinner?" << endl;
    cout << endl;

    AreHungry();
    return 0;
}

void AreHungry() { //answers the first branch, determines how hungry the user is. If the user is hungry, it will ask some basic financial questions.
    int varHungry;

    are_hungry:
    cout << "are you hungry?" << endl;
    cout << "1: kinda   2. yes   3. no <3" << endl;

    cin  >> varHungry;

    if (varHungry == 1) {
        SweetOrSalty();
    }
    else if (varHungry == 2) {
        int cashOnHand;
        int spending;

        spending:
        cout << "how much money do you have on you (in dollars)?" << endl;
        cin  >> cashOnHand;
        cout << endl;

        cout << "how much are you willing to spend (dollars)?" << endl;
        cin  >> spending;
        cout << endl;

        if (spending > cashOnHand) {
            cout << "buddy you can't spend more money than you have" << endl;
            goto spending;
        }
        cout << Budget(cashOnHand, spending) << " dollar(s) left" << endl;
    }
    else if (varHungry == 3) {
        cout << "have a nice glass of air :)" << endl;
    }
}

void SweetOrSalty() { //if the user answered they're kinda hungry, it will ask if they want a sweet or a salty snack
    int varSweet;

    sweet_or_salty:
    cout << "do you want something sweet or salty?" << endl;
    cout << "1. sweet   2. salty" << endl;
    cin  >> varSweet;

    if (varSweet == 1) {
        HealthyOrNah();
    }
    else if (varSweet == 2) {
        cout << "eat some pretzels" << endl;
    }
    else {
        cout << "sir that wasn't an option. try again" << endl;
        cout << endl;
        goto sweet_or_salty;
    }

}
void HealthyOrNah() { //if the user says they want something sweet, program will ask if they want that sweet thing to be healthy or not
    int varHealthy;

    healthy_or_nah:
    cout << "do you want something healthy or nah?" << endl;
    cout << "1. healthy   2. nah" << endl;
    cin  >> varHealthy;

    if (varHealthy == 1) {
        AreYouSure();
    }
    else if (varHealthy == 2) {
        cout << "get yourself an ice cream, king" << endl;
    }
    else {
        cout << "eek that wasn't an option. try again" << endl;
        cout << endl;
        goto healthy_or_nah;
    }
}

void AreYouSure() { //if the user answers they want to eat something healthy, program will confirm that decision
    int varSure;

    are_sure:
    cout << "are you sure about that?" << endl;
    cout << "1. yes sadly   2. nah u right" << endl;
    cin  >> varSure;

    if (varSure == 1) {
        cout << "ouch. go eat a fruit cup or somethin then" << endl;
    }
    else if (varSure == 2) {
        cout << "yeah, get yourself an ice cream, king" << endl;
    }
    else {
        cout << "nnnoooo that wasn't an option. try again" << endl;
        cout << endl;
        goto are_sure;
    }
}

int Budget(int cash, int budget) { //will take the numbers given earlier to decide what the user's budget will allow
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

