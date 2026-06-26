#include <iostream>
using namespace std;

int main() {
    int a, b;

    // Taking input from user
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;

    // Arithmetic operations
    cout << "\n--- Arithmetic Operators ---\n";
    cout << "Addition (a + b) = " << (a + b) << endl;
    cout << "Subtraction (a - b) = " << (a - b) << endl;
    cout << "Multiplication (a * b) = " << (a * b) << endl;
    cout << "Division (a / b) = " << (a / b) << endl;
    cout << "Modulus (a % b) = " << (a % b) << endl;

    return 0;
}
