#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 15; i++) {
        if (i == 3) continue; // skip 3
        if (i == 5) break;    // stop at 5
        cout << i << " ";
    }
    return 0;
}
