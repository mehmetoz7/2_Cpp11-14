#include <iostream>

using namespace std;


template <class T, class U>
auto mul(T const& f_st, U const& s_nd)->decltype(f_st * s_nd){
    return f_st * s_nd;
}

int main(){
    auto f1 = [](int a, int b)->int{return a*b;};
    cout << f1(4, 5) << endl;

    cout << mul (5, 4.5) << endl;
    
    return 0;
}


