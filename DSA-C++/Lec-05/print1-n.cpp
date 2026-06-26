#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
   for(int j=1; j<=n; j++){
       cout << j << endl;
   }
    return 0;
}

// can also use while loop here 

/*
#include <iostream>
using namespace std;        
int main() {
    int n;
    cin >> n;
   int j=1;
   while(j<=n){
       cout << j << endl;
       j++;
   }
    return 0;
}
*/  

// can also use do while loop here
/*
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
   int j=1;
   do{
       cout << j << endl;
       j++;
   }while(j<=n);
    return 0;
}
*/