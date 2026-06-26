// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    int n;
cin >> n;
 for(int row = 1; row<n; row++){
    int x = 1;
    for(int i =0; i<row; i++){
        cout << x <<" ";
        x++;
    }
    
    // space 2n-2row
    for(int i =0; i<2*n-2*row; i++){
        cout << "  ";
    }
     
     int y = row;
    for(int i =0; i<row; i++){
        cout << y <<" ";
        y--;
    }
    cout << endl;
    
}
for(int i =1; i<=n; i++){
	cout << i << " ";
}
for(int i = n-1; i>=0; i--){
	cout << i << " ";
}

    return 0;
}