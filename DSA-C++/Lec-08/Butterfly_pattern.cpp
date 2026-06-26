// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
   int n;
   cin >> n;
   int r = 2*n+1;
   
   for(int row = 1; row<=r; row++){
       if(row == (n+1)){
           for(int i = n ; i>=0; i--){
               cout << i <<" ";
           }
           for(int i =1; i<=n; i++){
               cout << i <<" ";
           }
       }else{
           int al = row;
           if(row>(n+1)){
              al = ( 2*n+2 -row);
           }
           
           
          
           int x = n;
           for(int i = 1; i<=al; i++){
               cout << x << " ";
               x--;
           }
           // c2 space 
           for(int i = 1; i<= (r-2*al); i++){
               cout << "  ";
           } 
           
           // c3 
           for(int i =1; i<=al; i++){
               cout << ++x << " ";
           }
           
       }
       cout << endl;
   }
   


    return 0;
}  // Butterfly pattern.