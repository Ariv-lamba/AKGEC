#include <iostream>
using namespace std;

int main() {


    // increment and decrement postfix and prefix working 
    int a=0, b=0;
    if(a++){
        cout << "condition is true" << endl;
    }else{
        cout << "condition is false" << endl;
    }
    cout << "a = " << a << endl;

    if(++b){
        cout << "condition is true" << endl;
    }else{
        cout << "condition is false" << endl;
    }
    cout << "b = " << b << endl;

    // logical or operartor special conditon

    if(a++ || ++b){
        cout << a << " "<< b << endl;
    }

    if(a++ && ++b){
        cout << a << " "<< b << endl;
    }   
  
    return 0;
}
