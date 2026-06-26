#include <iostream>
using namespace std;

int add(int a, int b) {   // return type = int
    return a + b;         // return integer value
}

int main() {
    int x = add(5, 3);
    cout << "Sum = " << x << endl;
    return 0;
}
