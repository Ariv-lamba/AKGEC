#include <iostream>
using namespace std;

int main() {
    int marks;
    cout << "Enter marks: ";
    cin >> marks;

    if (marks >= 90) {
        cout << "Grade A" << endl;
    } else if (marks >= 60) {
        cout << "Grade B" << endl;
    } else {
        cout << "Grade C" << endl;
    }

    return 0;
}


/*
#include <iostream>
using namespace std;

int main() {
    int age;
    cout << "Enter your age: ";
    cin >> age;

    if (age >= 18) {
        if (age >= 21) {
            cout << "You are 21 or older." << endl;
        } else {
            cout << "You are between 18 and 20." << endl;
        }
    } else {
        cout << "You are a minor." << endl;
    }

    return 0;
}
*/