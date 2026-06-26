// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    int n;
cin >> n;
for(int row = 1; row<=n; row++){
    
    
    if(row == n){
        // star -> n+1/2
        for(int i =0; i<(n+1)/2; i++){
            cout << "* ";
        }
        
        // space -> n-3/2
         for(int i =0; i<(n-3)/2; i++){
            cout << "  ";
        }
        
        // 1 star
         cout << "* ";
    }
    
    if(row>1 && row <(n+1)/2){
         cout << "* ";
    // n-3/2 space 
    for(int i= 0; i<(n-3)/2; i++){
        cout << "  ";
    }
    // * 
    cout << "* ";
    // n-1/2 space 
    for(int i =0; i<(n-1)/2; i++){
        cout << "  ";
    }
    }
    
    if(row>(n+1)/2 && row <n){
        for(int i =0; i<(n-1)/2; i++){
        cout << "  ";
        }
         cout << "* ";
          for(int i= 0; i<(n-3)/2; i++){
        cout << "  ";
       }
        cout << "* ";
    }
   
    
    
    
    if(row == 1){
        cout << "* ";
        // sp[ace] -> n-3/2 
        for(int i =0; i<(n-3)/2; i++){
            cout << "  ";
        }
        
        // star -> n+1/2 
        for(int i =0; i<(n+1)/2; i++){
            cout << "* ";
        }
    }
      
    // b3 -> all star 
    if(row == (n+1)/2){
        for(int i =0; i<n; i++){
            cout << "* ";
        }
    }
   
    cout << endl;
    
}

    return 0;
}