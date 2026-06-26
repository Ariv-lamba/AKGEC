#include <iostream>
using namespace std;

// Function to find maximum of two numbers
int getMax(int a, int b) {
    if (a > b) 
        return a;
    else 
        return b;
}

int main() {
    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;

    cout << "Maximum = " << getMax(x, y) << endl;
    return 0;
}
