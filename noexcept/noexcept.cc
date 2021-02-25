/*
Use noexcept when throw is impossible or unacceptable, 
By declaring function noexcept, we give the compiler and human
readers information that can make it easier for them to understand
 and manipulate compute.
*/

#include <iostream>
#include <stdexcept>
#include <stdexcept> 

using namespace std;

void f1() { throw runtime_error("oops"); }
void f2() {} //will not throw but not stated explicitely

// as SPECIFIER
void f3() noexcept {}

//may throw exception
int divide(int x, int y){
   try {
      if (y == 0) { throw (y); } 
      else { return x/y; }
   }
   catch (...) {
      cout << "divide by zero detected" << endl;
      return 0;
   }
}

void makeReadable(bool b){
   if (b)
      cout << "will not propagate exception" << endl;
   cout << "may propagate exception" << endl;
}

int main() {
   //as OPERATOR 
   
   //it determines if operand can produce an exception or not
   //if returns true operand wont produce an exception
   makeReadable(noexcept(f1()));   
   makeReadable(noexcept(f2()));
     
   auto l1 = [](int n){return n > 0;};
   makeReadable(noexcept(l1(5)));
   
   makeReadable(noexcept(f3()));      
   
   makeReadable(noexcept(divide(10, 6)));

}

