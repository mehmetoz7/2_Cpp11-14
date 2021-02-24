#include <iostream>
#include <iomanip>
  
using namespace std;

long double operator"" _kg(long double x){return x * 1000;}
long double operator""  _g(long double x){return x;}
long double operator"" _mg(long double x){return x / 1000;}

int main(){
    long double w = 10.0_kg;
    cout << 10.0_kg / 1.0_g << endl;
    return 0;
}


