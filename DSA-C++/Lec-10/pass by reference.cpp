#include <iostream>
using namespace std;

void swapByReference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside function: a = " << a << ", b = " << b << endl;
     cout << &a << " " << &b << endl;
}

int main() {
    int x = 5, y = 10;
    swapByReference(x, y);
    cout << "Outside function: x = " << x << ", y = " << y << endl;
    return 0;
     cout << &x << " " << &y << endl;
}
   