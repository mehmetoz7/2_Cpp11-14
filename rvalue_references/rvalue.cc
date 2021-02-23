/*enables to distinguish an lvalue from an rvalue

*/
#include <iostream>

using namespace std;

void f(int& i){cout << "lvalue" << endl;}
void f(int&& i){cout << "rvalue" << endl;}

//return of the function is an rvalue
int get(){int i=10; return i;}

int main(){
    int&& rvalue_ref = 50;

    int x = 80;    
    int& lvalue_ref = x;
    
    //in C++0x lvalue reference can bind to a temporary objects 
    //if it is const 
    const int& val = get();        
    
    //but otherwise can only be assigned to a normal reference
    //so these are not compilable
    //int& lvalue_ref = 40;   
    //int& lvalue_ref = get();        

    //these both are compilable in C++11
    const int&& val2 = get();
    int&& val3 = get();
    //---------------------------------
    
    //using rvalue reference, we can use function overloading to
    //determine whether input param. is an rvalue or an lvalue    
    f(x);         //lvalue
    f(lvalue_ref);//lvalue
    f(50);        //rvalue
    f(rvalue_ref);//lvalue
    f(get());     //rvalue
    
    //move converts an lvalue to an rvalue
    f(move(x));   //rvalue    
    //--------------------------------- 
    
    //tha main usage of rvalue references are to create 
    //move constructor and move assignment
    
    
    
    
    

    return 0;
}


