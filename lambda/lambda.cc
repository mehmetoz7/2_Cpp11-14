/*
[capture clause](parameters)->return type{definition of method}

[ ](){} 	no captures
[=](){} 	captures everything by copy(not recommendded)
[&](){} 	captures everything by reference(not recommendded)
[x](){}	captures x by copy
[&x](){}	captures x by reference
[&, x](){}	captures x by copy, everything else by reference
[=, &x](){}	captures x by reference, everything else by copy
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
  
using namespace std;

void f1(int x){ cout << "f1 function: " << x << endl; }
void f2(int x){ cout << "f2 function: " << x << endl; }

class zeroCount{
private:
    int count = 0;
public:    
    int get(){return count;}
    void update(vector<int> &v){
    //capturing private members in a class requires this operator
       for_each(v.begin(), v.end(), [this](int i){
          if(i == 0) count++; //count private member is captured
       });
    }
};

void log(){cout << endl;};
template <typename T, typename ... Args>
void log(T f_st, Args ... args){
    cout << f_st << " ";
    log(args ...);
}

int main(){
    vector <int> v {0,1,2,3,4,5,6,7,8,9,0};
    for_each(v.begin(), v.end(), [](int i){cout << i << " ";});
    cout << endl;
    
    //lambda with capture
    auto sum = 0;
    for_each(v.begin(), v.end(), [&sum](int i){sum += i;});
    cout << sum << endl;
    
    //calls some other functions in requested order
    auto l_f1 = [](int a, int b){f1(a); f2(b);};
    //with parameters for a and b
    l_f1(5, 6);
    
    //identifiying return type (not necessary in C++14)
    auto l_f2 = [&](int n)->bool{return n > 0;};
    cout << l_f2(-3) << endl;
    cout << l_f2(4)  << endl;
    
    //generic lambda (for C++14)
    auto l_f3 = [](auto a, auto b){return a * b;};
    cout << l_f3(4,   6)   << endl;
    cout << l_f3(4.2, 6.5) << endl;    
    
    //using lambda in a class
    zeroCount zCounter;
    zCounter.update(v);
    cout << "dd" << zCounter.get() << endl;
    
    //variadic generic lambda
    auto l_f4 = [](auto ... prm){ log(prm ...); };
    l_f4(2, "abcd", 4, 5.5);
    
    //function as capture parameter
    function<int(int)> l_f5 = [&l_f5](int x){
       return x < 2 ? 1 : l_f5(x-2) + l_f5(x-1);};    
    cout << l_f5(10) << endl;
    
    return 0;
}


