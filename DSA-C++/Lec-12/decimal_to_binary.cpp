#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int decimal;
    cout << "Enter Decimal Number: ";
    cin >> decimal;

    long long binary = 0;
    int power = 0;

    while(decimal > 0) {
        int remainder = decimal % 2;
        binary += remainder * pow(10, power);
        power++;
        decimal /= 2;
    }

    cout << "Binary = " << binary;

    return 0;
}