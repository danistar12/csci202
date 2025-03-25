/* Program name: Testing.cpp
* Author: Danielle Lloyd    
* Date last updated: 3/24/2025
* Purpose: 
*/

#include <iostream>
#include <regex>
#include <string>

using namespace std;

//validate email without using regex
bool isValidEmail(const string& email) {
    //find the position of '@' and '.' in the email
    size_t atPos = email.find('@');
    size_t dotPos = email.find('.', atPos); // The '.' should appear after '@'

    //check if '@' and '.' are present and in the correct order
    if (atPos != string::npos && dotPos != string::npos &&
        atPos > 0 && dotPos > atPos + 1 && dotPos < email.length() - 1) {
        return true;
    }
    return false;
}

int main() {
    string email;

    cout << "Enter your email address: ";
    getline(cin, email);

    // Loop until the user enters "quit"
    while (email != "quit") {
        // Validate email
        if (isValidEmail(email)) {
            cout << "Valid email entered!" << endl;
        } else {
            cout << "Invalid email. Please try again." << endl;
        }

        // Prompt for the next input
        cout << "Enter your email address: ";
        getline(cin, email);
    }

    cout << "Goodbye!" << endl;

    return 0;
}
