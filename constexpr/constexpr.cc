/*
provide sompile-time computation for better performance at runtime
*/
#include <iostream>
  
using namespace std;

template<typename T>
constexpr T mul(T x, T y){
   cout << "C++14 allows multiline constexpr functions" << endl;
   return x * y;
}

template<typename T>
class rectangle{
private:   
   T _h, _w;   
public:
   constexpr rectangle(T h, T w):_h(h), _w(w){}
   constexpr T area(){return _h * _w;}   
};

int main(){
   //compile time computation
   cout << mul<int>(5, 7) << endl;

   int x;
   cin >> x;
   //constexpr functions can also be called at runtime
   cout << mul<int>(x, 2) << endl; 
    
   constexpr rectangle<int> r{10, 2};
   cout << r.area() << endl;   
   
   return 0;
}


