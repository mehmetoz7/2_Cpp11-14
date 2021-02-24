#include <iostream>
#include <string>
#include <vector>

using namespace std;

//enables to distinguish an lvalue from an rvalue
void f(int& i) {cout << "lvalue" << endl;}
void f(int&& i){cout << "rvalue" << endl;}

//return of the function is an rvalue
int get(){int i=10; return i;}

class Test{
private:
    string *ptr;
public:
    Test()=default;

    //constructor
    Test(const string& s):ptr(new string(s)){
       cout << "constructor" << endl;       
    }
    
    //destructor
    ~Test(){delete ptr;}

    //move constructor
    Test(Test&& x) : ptr(x.ptr) {
       cout << "move constructor" << endl;       
       x.ptr = nullptr;
    } 
    
    //copy constructor
    Test (const Test& x):ptr(new string(*x.ptr)){
       cout << "copy constructor" << endl;
    }
    
    //copy assignment
    Test& operator=(const Test& x){
       cout << "copy assignment" << endl;    
       *ptr = *x.ptr;
       return *this;
    }
     
    //move assignment
    Test& operator=(Test&& x){
       cout << "move assignment" << endl;
       delete ptr;
       ptr = x.ptr;
       x.ptr = nullptr;
       return *this;
    }    
};

Test f(Test a){
   return a;
}

int main(){
    int&& rvalue_ref = 50;

    int x = 80;    
    int& lvalue_ref = x;
    
    //in C++0x if lvalue reference is const, 
    //it can bind to a temporary objects 
    const int& val = get(); 
           
    //but otherwise can only be assigned to a normal reference
    //so these are not compilable
    //int& lvalue_ref = 40;   
    //int& lvalue_ref = get();      
    
    //in C++11 using rvalue reference these lines are compilable
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
    cout << "----------------" << endl;
    Test t1{"111"};    
    Test t2{"222"};
    Test t3 = t1;               //copy constructor
    t3 = t2;                    //copy assignment
    cout << "----------------" << endl;    
/*    
    vector<Test> v;   
    v.push_back(Test{"aaa"});   //move constructor 
    v.push_back(Test{"bbb"});   //move constructor    
*/
    t1 = f(Test());             //move assignment     
    Test t5 = f(Test());        //move constructor
    return 0;
}



