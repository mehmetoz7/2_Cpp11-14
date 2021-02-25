#include <iostream>
#include <utility>
#include <vector>  

using namespace std;

template <typename T>
auto add (T a, T b){
   return a + b;
}

class B {    // class with specific constructor
  int val_=5;
public:
  int value() {return val_;}
};

int main(){
    //type of x is return type of the function
    decltype (add(5, 6)) x;
    cout << typeid(x).name() << endl;
    
    decltype (add(5.9, 6.8)) y;
    cout << typeid(y).name() << endl;

    //type of z is return type of x    
    decltype(x) z = 5;
    cout << typeid(z).name() << endl;
    
    //if there is no existing lvalue, declval is used
    decltype(declval<B>().value()) i;
    cout << typeid(i).name() << endl;
    
    decltype(B(declval<B>())) b; //class B instance
    cout << b.value() << endl;

    return 0;
}




