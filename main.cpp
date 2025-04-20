#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

string generatePassword(int length, bool useUpper, bool useLower, bool useDigits, bool useSpecial) {
    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lower = "abcdefghijklmnopqrstuvwxyz";
    string digits = "0123456789";
    string special = "!@#$%^&*()_+-=[]{}|;:,.<>?";
    
    string allChars = "";
    if (useUpper) allChars += upper;
    if (useLower) allChars += lower;
    if (useDigits) allChars += digits;
    if (useSpecial) allChars += special;

    string password = "";
    for (int i = 0; i < length; i++) {
        int index = rand() % allChars.length();
        password += allChars[index];
    }

    return password;
}

int main() {
    srand(time(0)); // Random seed

    int length;
    char u, l, d, s;

    cout << "Password length: ";
    cin >> length;
    cout << "Include uppercase letters? (y/n): ";
    cin >> u;
    cout << "Include lowercase letters? (y/n): ";
    cin >> l;
    cout << "Include digits? (y/n): ";
    cin >> d;
    cout << "Include special characters? (y/n): ";
    cin >> s;

    string password = generatePassword(
        length,
        u == 'y' || u == 'Y',
        l == 'y' || l == 'Y',
        d == 'y' || d == 'Y',
        s == 'y' || s == 'Y'
    );

    cout << "\nGenerated Password: " << password << endl;

    return 0;
}
