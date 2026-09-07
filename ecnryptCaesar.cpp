#include <iostream>
#include <string>

using namespace std;

string encryptCaesar(string text, int shift) {
    string result = "";
    shift = shift % 26;

    for (char c : text) {
        if (isupper(c)) {
            result += char((c - 'A' + shift) % 26 + 'A');
        }
        else if (islower(c)) {
            result += char((c - 'a' + shift) % 26 + 'a');
        }
        else {
            result += c;
        }
    }
    return result;
}

string decryptCaesar(string text, int shift) {
    return encryptCaesar(text, 26 - (shift % 26));
}

int main() {
    string message;
    int shift;

    getline(cin, message);
    cin >> shift;

    string encrypted = encryptCaesar(message, shift);
    string decrypted = decryptCaesar(encrypted, shift);

    cout << encrypted << endl;
    cout << decrypted << endl;

    return 0;
}
