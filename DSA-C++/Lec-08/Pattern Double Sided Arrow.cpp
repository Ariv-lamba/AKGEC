// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    
    for ( int row = 1; row<=n; row++){
        if( row == 1 ||  row == n){
            for(int i =1; i<= (n-1); i++){
                cout << "  ";
            }
            cout << 1 << " ";
            for(int i =1; i<= (n-1); i++){
                cout << "  ";
            }
        }else{ 
            
            //  row -> 2 ---- n-1 
            //   2 - n+1/2   exact 
            //   8  - n-1 row -> change   10- 2
               int yyyy = row;
              if( row > ( n+1)/2){
                  yyyy = n+1 - row;
              }
            // left space 
            
            
            
            int x = (2*n-1) - (2*yyyy) -( 2*yyyy -3);
            x = x/2;
            for(int i =1; i<=x; i++){
                cout << "  ";
            }
            
            // number 
            int y = yyyy ;
            for(int i =1; i<= yyyy ; i++){
                cout << y << " ";
                y--;
            }
            // centre space 
            for(int i =1; i<= ( 2*yyyy -3); i++){
                cout << "  ";
            }
            
            for(int i = 1; i<= yyyy ; i++){
                cout << i << " ";
            }
            
            
        }
        cout << endl;
    }
    
 
 

    return 0;
}