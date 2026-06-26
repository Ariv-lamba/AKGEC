#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int row = 1; row <= n; row++) {
        if (row % 2 == 1) {
            // odd row -> all 1s
            for (int i = 0; i < row; i++) {
                cout << 1;
            }
        } else {
            // even row -> 1 ... 1
            cout << 1;
            for (int i = 0; i < row - 2; i++) {
                cout << 0;
            }
            cout << 1;
        }
        cout << endl;
    }

    return 0;
}
