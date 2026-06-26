#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int &ref = x;  // ref is alias for x

    cout << "x = " << x << endl;
    cout << "ref = " << ref << endl;

    ref = 20;  // changes x
    cout << "x after changing ref = " << x << endl;
    return 0;
}
