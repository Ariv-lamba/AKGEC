#include <iostream>
using namespace std;

int add(int a, int b) {        // version 1
    return a + b;
}

double add(double a, double b) {  // version 2
    return a + b;
}

int main() {
    cout << add(3, 4) << endl;      // calls int version
    cout << add(2.5, 3.7) << endl;  // calls double version
    return 0;
}
