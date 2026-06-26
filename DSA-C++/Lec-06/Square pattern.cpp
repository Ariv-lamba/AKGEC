#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int row = 1; row <= n; row++) {
        // Step 1: print r repeated r times
        for (int col = 1; col <= row; col++) {
            cout << row << " ";
        }

        // Step 2: print normal numbers from r+1 to n
        for (int col = row + 1; col <= n; col++) {
            cout << col << " ";
        }

        cout << endl;
    }

    return 0;
}
