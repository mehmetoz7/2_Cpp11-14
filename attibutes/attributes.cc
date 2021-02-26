/*specify additional information to the compiler to enforce 
constraints, optimise certain piece of code or do some specific
code generation.*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//function will not return the caller, inform compiler
[[noreturn]] void assertFailure(const char *msg){
   cout << msg << endl;
   terminate();
}

vector<int> fill(int count){
   vector<int> v{};   
   try{
      if(count > 0){
         for(int i=0; i<count; i++){v.push_back(i);}      
         return v;
      }
      else{ throw ("unacceptable input parameter"); }
   }
   catch(const char *ex){ assertFailure(ex); }   
};

int main(){ 
   vector<int> v = fill(-5);
   for(auto i:v){cout << i << ' ';}
   cout << endl;
}



