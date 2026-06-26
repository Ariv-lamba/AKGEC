
// single input 
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;   // user enters input
    cout << "You entered: " << n << endl;
    return 0;
}


// multiple inputs in single line 
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;  // user enters: 10 20
    cout << "Sum = " << a + b << endl;
    return 0;
}


// multiple testcases
#include <iostream>
using namespace std;

int main() {
    int t;  
    cout << "Enter number of test cases: ";
    cin >> t;   // example: 3 test cases

    while (t--) {
        int n;
        cout << "Enter a number: ";
        cin >> n;
        cout << "Square = " << n * n << endl;
    }
    return 0;
}


// input until EOF (End Of File)

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter numbers (Ctrl+D to stop):" << endl;

    while (cin >> n) {   // keeps taking input until EOF
        cout << "Double = " << n * 2 << endl;
    }
    return 0;
}