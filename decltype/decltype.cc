#include <iostream>
  
using namespace std;

template <typename T>
auto add (T a, T b){
   return a + b;
}

int main(){
    //type of x is return type of the function
    decltype (add(5, 6)) x;
    cout << typeid(x).name() << endl;
    
    decltype (add(5.9, 6.8)) y;
    cout << typeid(y).name() << endl;

    //type of z is return type of x    
    decltype(x) z = 5;
    cout << typeid(z).name() << endl;
   
    return 0;
}
