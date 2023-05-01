#include <iostream>
#include <vector>
using namespace std;

void RunMenu(vector<int> numJersey, vector<int> numRating, int& countPlayers);
void OutputRoster(vector<int> numJersey, vector<int> numRating, int countPlayers);
void AddPlayer(vector<int>& numJersey, vector<int>& numRating, int& countPlayers);
void RemovePlayer(vector<int>& numJersey, vector<int>& numRating, int& countPlayers);
void UpdateRating(vector<int> numJersey, vector<int>& numRating, int countPlayers);
void AboveRating(vector<int> numJersey, vector<int> numRating, int countPlayers);

int main() {
    int numPlayers = 5;
    vector<int> playerJersey(numPlayers);
    vector<int> playerRating(numPlayers);

    for (int i = 0; i < numPlayers; ++i) {
        cout << "Enter player " << i + 1 << "'s jersey number: ";
        cin >> playerJersey.at(i);
        cout << endl;

        cout << "Enter player " << i + 1 << "'s rating: ";
        cin >> playerRating.at(i);
        cout << endl;
    }

    cout << endl;

    OutputRoster(playerJersey, playerRating, numPlayers);
    RunMenu(playerJersey, playerRating, numPlayers);

    return 0;
}

void RunMenu(vector<int> numJersey, vector<int> numRating, int& countPlayers) {
    char userInput;

    cout << endl << "MENU" << endl;
    cout << "a - Add player" << endl;
    cout << "d - Remove player" << endl;
    cout << "u - Update player rating" << endl;
    cout << "r - Output players above a rating" << endl;
    cout << "o - Output roster" << endl;
    cout << "q - Quit" << endl;
    cout << endl << "Choose an option: ";

    userInput = 'z';
    cin  >> userInput;

    switch (userInput) {
        case 'a':
            AddPlayer(numJersey, numRating, countPlayers);
            RunMenu(numJersey, numRating, countPlayers);
            break;
        case 'd':
            RemovePlayer(numJersey, numRating, countPlayers);
            RunMenu(numJersey, numRating, countPlayers);
            break;

        case 'u':
            UpdateRating(numJersey, numRating, countPlayers);
            RunMenu(numJersey, numRating, countPlayers);

        case 'r':
            AboveRating(numJersey, numRating, countPlayers);
            RunMenu(numJersey, numRating, countPlayers);

        case 'o':
            OutputRoster(numJersey, numRating, countPlayers);
            RunMenu(numJersey, numRating, countPlayers);
            break;

        case 'q':
            exit(0);
        default:
            cout << "Invalid Input" << endl;
            RunMenu(numJersey, numRating, countPlayers);
    }
}

void OutputRoster(vector<int> numJersey, vector<int> numRating, int countPlayers) {
    cout << endl << "ROSTER" << endl;

    for (int i = 0; i < countPlayers; ++i) {
        cout << "Player " << i + 1 << " -- ";
        cout << "Jersey number: " << numJersey.at(i) << ", ";
        cout << "Rating: " << numRating.at(i) << endl;
    }
}

void AddPlayer(vector<int>& numJersey, vector<int>& numRating, int& countPlayers) {
    numJersey.resize(numJersey.size() + 1);
    numRating.resize(numRating.size() + 1);
    countPlayers = countPlayers + 1;

    cout << "Enter another player's jersey number: ";
    cin  >> numJersey.at(countPlayers - 1);
    cout << "Enter another player's rating: ";
    cin  >> numRating.at(countPlayers - 1);
}

void RemovePlayer(vector<int>& numJersey, vector<int>& numRating, int& countPlayers) {
    int jerseyNumber;
    int index = numJersey.at(0);

    cout << "Enter a jersey number: ";
    cin  >> jerseyNumber;

    for (int i = 0; i < countPlayers; ++i) {
        if (numJersey.at(i) == jerseyNumber) {
            index = i;
        }
    }

    numJersey.erase(numJersey.begin() + index);
    numRating.erase(numRating.begin() + index);

    countPlayers = countPlayers - 1;
}

void UpdateRating(vector<int> numJersey, vector<int>& numRating, int countPlayers) {
    int jerseyNumber;
    int index = numJersey.at(0);
    int newRating;

    cout << "Enter a jersey number: ";
    cin  >> jerseyNumber;

    for (int i = 0; i < countPlayers; ++i) {
        if (numJersey.at(i) == jerseyNumber) {
            index = i;
        }
    }

    cout << "Enter a new rating for player: ";
    cin  >> newRating;
    numRating.at(index) = newRating;
}

void AboveRating(vector<int> numJersey, vector<int> numRating, int countPlayers) {
    int minRating;

    cout << "Enter a rating: ";
    cin  >> minRating;
    cout << endl << endl << "ABOVE " << minRating << endl;

    for (int i = 0; i < countPlayers; ++i) {
        if (numRating.at(i) > minRating) {
            cout << "Player " << i + 1 << " -- Jersey number: " << numJersey.at(i) << ", Rating: " << numRating.at(i) << endl;
        }
    }

}