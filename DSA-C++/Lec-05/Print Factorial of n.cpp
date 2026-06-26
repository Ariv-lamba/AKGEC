#include <iostream>
using namespace std;

int main() {
    int N;
    long long fact = 1;  // use long long for large numbers
    cout << "Enter N: ";
    cin >> N;

    for (int i = 1; i <= N; i++) {
        fact *= i;
    }

    cout << "Factorial of " << N << " = " << fact << endl;
    return 0;
}
