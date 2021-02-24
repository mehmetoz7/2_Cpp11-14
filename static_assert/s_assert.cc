/* static_assert(constant_expression, string_literal);
if condition is not then stop the compile process */
#include <iostream>
  
using namespace std;

template<typename T>
T divide(T const x, T const y){
    return x / y;
};

int main(){
    const int x = 10;
    const int y = 5;
    //if the condition is true, has no effect
    static_assert(y != 0, "divide by zero detected");

    cout << divide<int>(x, y) << endl;
    return 0;
}

