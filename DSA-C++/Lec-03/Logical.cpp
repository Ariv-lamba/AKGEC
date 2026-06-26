#include <iostream>
using namespace std;

int main() {
    int a, b;

    // Taking input from user
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;

    cout << "\n--- Logical Operators ---\n";

    // Logical AND
    cout << "(a > 0 && b > 0) → " << (a > 0 && b > 0) << endl;

    // Logical OR
    cout << "(a > 0 || b > 0) → " << (a > 0 || b > 0) << endl;

    // Logical NOT
    cout << "!(a > b) → " << !(a > b) << endl;

    return 0;
}
