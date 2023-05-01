#include <iostream>
using namespace std;

void ModifyPass(string& password);

int main()
{
    string userPass;            // Declares variable password string

    cin  >> userPass;           // Sets password to user input

    ModifyPass(userPass);       // Runs function to modify the user password

    cout << userPass << endl;   // Outputs the user password

    return 0;
}

void ModifyPass(string &password) {              // Function receives string and modifies characters as determined.
    for (int i = 0; i < password.length(); i++)     // Finds characters in password and replaces them if applicable
    {
        if (password.at(i) == 'i')
        {
            password.at(i) = '!';
        }
        if (password.at(i) == 'a')
        {
            password.at(i) = '@';
        }
        if (password.at(i) == 'l')
        {
            password.at(i) = '1';
        }
        if (password.at(i) == 'B')
        {
            password.at(i) = '8';
        }
        if (password.at(i) == 'E')
        {
            password.at(i) = '3';
        }
        if (password.at(i) == 'm')
        {
            password.at(i) = 'M';
        }
        if (password.at(i) == 's')
        {
            password.at(i) = '$';
        }
        if (password.at(i) == 'o')
        {
            password.at(i) = '0';
        }
    }
    password.append("z^w");                 // Adds  "z^w"  to the end of the password
}
