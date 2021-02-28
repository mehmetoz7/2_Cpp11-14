#include <iostream>
  
using namespace std;

int main(){   
   
   auto a1 = 42;        // ... decimal
   auto a2 = 0x2A;      // ... hexadecimal
   auto a3 = 0b101010;  // ... binary
   auto a4 = 0b100'0001;  // ASCII 'A'
   cout << a1 << " " << a2 << " " << a3 << " " << a4 << endl;
       
   return 0;
}



