/*
override means that compiler will check the base classes to see if
there is a virtual function with this EXACT SIGNATURE. And if there
is not the compiler will indicate an error.

With final C++11 adds the ability to prevent inheritting from a class or preventing overriding methods in derived classes. 
*/
#include <iostream>
  
using namespace std;

class Base{
    virtual void f1(int);
};

class Derived : public Base{
    virtual void f1(int) override;

    //this will indicate a compile error
    //virtual void f1(double) override;
};
//------------------------------------

//no class can be derived from this class
class Base2 final{
    virtual void f1(int);
};

class Base3{
    //no class can override this function
    virtual void f1(int) final;
};


int main(){   
    return 0;
}



