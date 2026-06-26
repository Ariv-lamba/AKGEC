#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int row = 1; row <= n; row++) {
        // Step 1: Print leading tabs
        for (int space = 1; space <= n - row; space++) {
            cout << "\t";
        }

        // Step 2: Print numbers
        int num = row; // starting number for this row
        int peak = row + (row - 1); // peak value (middle number)

        // Left half (increasing part including peak)
        for (int i = 0; i < row; i++) {
            cout << num++ << "\t";
        }

        // Right half (decreasing part)
        num -= 2; // step back after peak
        for (int i = 0; i < row - 1; i++) {
            cout << num-- << "\t";
        }

        cout << endl;
    }

    return 0;
}
