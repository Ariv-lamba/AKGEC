#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int row = 1; row <= n; row++) {
        // Step 1: print numbers
        for (int num = 1; num <= n - row + 1; num++) {
            cout << num << " ";
        }

        // Step 2: print stars
        for (int star = 1; star <= 2 * (row - 1); star++) {
            cout << "* ";
        }

        cout << endl;
    }

    return 0;
}
