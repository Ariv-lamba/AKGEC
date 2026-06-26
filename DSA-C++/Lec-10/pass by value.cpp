#include <iostream>
using namespace std;

void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside function: a = " << a << ", b = " << b << endl;
     cout << &a << " " << &b << endl;
}

int main() {
    int a = 5, b = 10;
    swapByValue(a, b);
    cout << "Outside function: a = " << a << ", b = " << b << endl;
    return 0;
    cout << &a << " " << &b << endl;
}
