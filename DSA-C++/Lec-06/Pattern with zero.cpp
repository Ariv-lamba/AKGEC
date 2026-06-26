#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= row; col++) {
            if (col == 1 || col == row) {
                cout << row << "\t";
            } else {
                cout << 0 << "\t";
            }
        }
        cout << endl;
    }

    return 0;
}
