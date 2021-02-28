#include <iostream>
#include <iomanip> 

using namespace std;

template<class T>

//defines a family of variables
constexpr T pi = T(3.1415926535897932385L);  
 
template<class T>
T circular_area(T r){
   return pi<T> * r * r; //variable template instantiation
};

int main(){ 
   cout << setprecision(50) << circular_area<double>(5) << endl;
   cout << setprecision(50) << circular_area<float>(5) << endl;   
   cout << setprecision(10) << circular_area<int>(5) << endl;
   cout << setprecision(10) << circular_area<long>(5) << endl;      
   return 0;
}



