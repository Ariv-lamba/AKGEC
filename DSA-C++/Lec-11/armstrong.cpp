#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, sum = 0;
    cout << "Enter a number: ";
    cin >> n;

    int original = n;
    int digits = 0;

    // Count number of digits
    int temp = n;
    while (temp > 0) {
        temp = temp / 10;
        digits++;
    }

    temp = n;

    // Calculate sum of digits raised to power 'digits'
    while (temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp = temp / 10;
    }

    // Check if sum equals original number
    if (sum == original)
        cout << n << " is an Armstrong number." << endl;
    else
        cout << n << " is NOT an Armstrong number." << endl;

    return 0;
}
