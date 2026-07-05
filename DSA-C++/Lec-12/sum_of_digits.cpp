#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter Number: ";
    cin >> n;

    int sum = 0;

    while(n > 0) {
        int digit = n % 10;
        sum += digit;
        n /= 10;
    }

    cout << "Digit Sum = " << sum;

    return 0;
}