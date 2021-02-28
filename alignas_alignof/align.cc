#include <iostream>
  
using namespace std;

//custom alignment of variables, structs, classes, unions
struct alignas(4) S1{
   char c1;  // 1 byte
   //3 bytes padding
   int i1;   // 4 bytes
   short s1; // 2 bytes
   char c2;  // 1 byte
   //1 byte padding
};


struct alignas(2) S2{
   char c1;  // 1 byte
   //3 bytes padding
   int i1;   // 4 bytes
   short s1; // 2 bytes
   char c2;  // 1 byte
   //1 byte padding
};

struct alignas(8) S3{
   char c1;  // 1 byte
   //7 bytes padding
   int i1;   // 4 bytes
   //4 bytes padding   
   short s1; // 2 bytes
   char c2;  // 1 byte
   //5 byte padding
};

int main(){   
   cout << sizeof(S1) << endl;
   cout << alignof(S1) << endl << endl;
   
   //due to i1 alignment is 4 again
   cout << sizeof(S2) << endl;   
   cout << alignof(S2) << endl << endl;

   cout << sizeof(S3) << endl;
   cout << alignof(S3) << endl << endl;
   
   return 0;
}



