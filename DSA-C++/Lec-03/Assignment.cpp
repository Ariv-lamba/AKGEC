#include <iostream>
using namespace std;

int main() {
    int a;

    // Taking input from user
    cout << "Enter a number: ";
    cin >> a;

    cout << "\n--- Assignment Operators ---\n";

    // Simple assignment
    int b = a;
    cout << "b = a → b = " << b << endl;

    // Add and assign
    b += 2;
    cout << "b += 2 → b = " << b << endl;

    // Subtract and assign
    b -= 1;
    cout << "b -= 1 → b = " << b << endl;

    // Multiply and assign
    b *= 3;
    cout << "b *= 3 → b = " << b << endl;

    // Divide and assign
    b /= 2;
    cout << "b /= 2 → b = " << b << endl;

    // Modulus and assign
    b %= 3;
    cout << "b %= 3 → b = " << b << endl;

    return 0;
}
