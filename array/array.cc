#include <iostream>
#include <array>
  
using namespace std;

void printArray(array<int, 10> &arr){
   for (auto & elem : arr)
      cout << elem << " , ";
}

int main(){
   //C++11 sequential container with constant size elements
    
   array<int, 10> arr = {1,2,3,4,5,6,7,8,9,10};
   
   cout << arr[2] << endl;   
   cout << arr[12] << endl;   
   cout << arr.at(2) << endl;
   
   try{ arr.at(12); }
   catch (const out_of_range& exp){
      cerr << exp.what() << endl;
   }
   
   cout << get<2>(arr) << endl;

   arr.fill(4);
   printArray(arr);
   cout << endl;
   
   return 0;
}
