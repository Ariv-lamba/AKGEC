#include <iostream>
#include <string>   // for string
using namespace std;

int main() {
    // Integer types
    int a = 10;                  // 4 bytes (commonly)
    short s = 5;                 // 2 bytes
    long l = 100000;             // 4 or 8 bytes
    long long ll = 10000000000;  // 8 bytes

    // Floating point types
    float f = 3.14f;             // 4 bytes
    double d = 3.1415926535;     // 8 bytes
    long double ld = 3.14159265358979; // 12 or 16 bytes

    // Character type
    char c = 'A';                // 1 byte

    // Boolean type
    bool flag = true;            // 1 byte

    // String type
    string str = "Hello C++";    // dynamic size

    // Printing values and sizes
    cout << "Integer (int): " << a << " | Size: " << sizeof(a) << " bytes" << endl;
    cout << "Short: " << s << " | Size: " << sizeof(s) << " bytes" << endl;
    cout << "Long: " << l << " | Size: " << sizeof(l) << " bytes" << endl;
    cout << "Long long: " << ll << " | Size: " << sizeof(ll) << " bytes" << endl;

    cout << "Float: " << f << " | Size: " << sizeof(f) << " bytes" << endl;
    cout << "Double: " << d << " | Size: " << sizeof(d) << " bytes" << endl;
    cout << "Long double: " << ld << " | Size: " << sizeof(ld) << " bytes" << endl;

    cout << "Char: " << c << " | Size: " << sizeof(c) << " bytes" << endl;
    cout << "Bool: " << flag << " | Size: " << sizeof(flag) << " bytes" << endl;

    cout << "String: " << str << " | Size: " << sizeof(str) 
         << " bytes (object, content varies)" << endl;

    return 0;
}
