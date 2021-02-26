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
   catch(const char *e){
      //allows the compiler to end the function without a return
      //statement
      assertFailure(e); 
   }   
};

[[deprecated("use calcWithRef")]] void div_1(int a, int b){
    cout << a / b;
} 
  
bool div_2(auto a, auto b){
    try{
       if(b==0){
          throw("divide by zero error");
       }
       else{
           
           cout << a/b << endl;
           return true;
       }
    }
    catch(const char* e){
       cout << e << endl;
       return false;
    }    
} 

int main(){ 
   vector<int> v = fill(5);
   for(auto i:v){cout << i << ' ';}
   cout << endl;
   
   div_1(15, 0) ;
   
}



