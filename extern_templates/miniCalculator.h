/*
*/
#include <iostream>
#include <stdexcept>
#include <stdexcept> 

template<class T>
class miniCalculator{
private:
   
public:   
   T mul(T a, T b){ return a * b; };
   T div(T a, T b){ return a / b; };
   T sub(T a, T b){ return a - b; };
   T add(T a, T b){ return a + b; };
};



