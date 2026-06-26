#include <iostream>
using namespace std;

int main() {
    int a;

    // Taking input from user
    cout << "Enter a number: ";
    cin >> a;

    cout << "\n--- Increment / Decrement Operators ---\n";

    // Prefix increment
    int b = a;
    cout << "Initial value of b = " << b << endl;
    cout << "++b (Prefix Increment) → " << ++b << endl;

    // Postfix increment
    b = a;
    cout << "\nReset b = " << b << endl;
    cout << "b++ (Postfix Increment) → " << b++ << endl;
    cout << "Value of b after b++ → " << b << endl;

    // Prefix decrement
    b = a;
    cout << "\nReset b = " << b << endl;
    cout << "--b (Prefix Decrement) → " << --b << endl;

    // Postfix decrement
    b = a;
    cout << "\nReset b = " << b << endl;
    cout << "b-- (Postfix Decrement) → " << b-- << endl;
    cout << "Value of b after b-- → " << b << endl;

    return 0;
}
