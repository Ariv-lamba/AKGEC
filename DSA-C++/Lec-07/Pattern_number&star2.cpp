#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int row = 1; row <= n; row++) {
        // print numbers 1 to row
        for(int num = 1; num <= row; num++) {
            cout << num;
        }
        // print stars
        for(int star = 1; star <= n - row; star++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
