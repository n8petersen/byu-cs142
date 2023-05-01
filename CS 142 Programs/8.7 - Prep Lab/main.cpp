#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Student {
public:
    Student(string name = "not initialized", double gpa = 0.0);
    void SetName(string studentName);
    void SetGPA(double newGPA);
    string ToString() const;
private:
    string name;
    double gpa;
};
Student::Student(string initialName, double initialGPA) {
    name = initialName;
    gpa = initialGPA;
}
void Student::SetName(string inputName) {
    name = inputName;
}
void Student::SetGPA(double newGPA) {
    gpa = newGPA;
}
string Student::ToString() const {
    return name + " has a GPA of " + to_string(gpa);
}

void OptionsMenuOption();
void AddMenuOption(vector<Student*>& studentsVector);
void DropMenuOption(vector<Student*>& studentsVector);
void PrintMenuOption(vector<Student*> studentsVector);
string GetUserString(const std::string& prompt);
double GetUserDouble(const std::string& prompt);
int GetUserInt(const std::string& prompt);

int main() {
    Student student;
    vector<Student*> studentsVector;

    string userMenuChoice = "none";
    bool continueMenuLoop = true;
    while (continueMenuLoop) {
        userMenuChoice = GetUserString("Enter Option: ");

        if (userMenuChoice == "add") {
            AddMenuOption(studentsVector);
        }
        else if (userMenuChoice == "drop") {
            DropMenuOption(studentsVector);
        }
        else if (userMenuChoice == "print") {
            PrintMenuOption(studentsVector);
        }
        else if (userMenuChoice == "quit") {
            continueMenuLoop = false;
        }
        else {
        }
    }

    return 0;
}

void OptionsMenuOption() {
    cout << "MENU" << endl
              << "add" << endl
              << "drop" << endl
              << "print" << endl
              << "quit" << endl << endl;
}
void AddMenuOption(vector<Student*>& studentsVector) {
    Student* ptrStudent;

    string userName = GetUserString("Student name:");
    double userGPA = GetUserDouble(userName + "'s GPA: ");

    ptrStudent = new Student(userName, userGPA);
    studentsVector.push_back(ptrStudent);
}
void DropMenuOption(vector<Student*>& studentsVector) {
    double index = GetUserInt("Index of student to drop: ");

    Student* ptrStudent = studentsVector.at(index);
    delete ptrStudent;

    studentsVector.erase(studentsVector.begin() + index);
}
void PrintMenuOption(vector<Student*> studentsVector) {
    unsigned int i;
    for (i = 0; i < studentsVector.size(); i++) {
        cout << i <<": " << studentsVector[i]->ToString() << endl;
    }
}

double GetUserDouble(const std::string& prompt) {
    double userAnswer = 0.0;

    std::cout << prompt;
    std::cin >> userAnswer;
    std::cin.ignore();
    std::cout << std::endl;
    return userAnswer;
}
int GetUserInt(const std::string& prompt) {
    int userAnswer = 0;

    std::cout << prompt;
    std::cin >> userAnswer;
    std::cin.ignore();
    std::cout << std::endl;
    return userAnswer;
}
string GetUserString(const std::string& prompt) {
    string userAnswer = "none";

    cout << prompt;
    getline(cin, userAnswer);
    cout << endl;
    return userAnswer;
}