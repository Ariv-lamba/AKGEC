#include <iostream>
using namespace std;

int power(int base, int exp = 2) {  // exp has default value 2
    int result = 1;
    for(int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int main() {
    cout << power(5) << endl;    // uses default exp=2 → 25
    cout << power(2, 3) << endl; // uses given exp=3 → 8
    return 0;
}
