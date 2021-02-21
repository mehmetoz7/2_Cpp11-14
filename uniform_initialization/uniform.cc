#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>
  
using namespace std;

template <class T, class U>
class Calculator{
    public:
       Calculator(T x, U y):_x(x), _y(y){}
       auto mul(){ return _x * _y; }
       auto sub(){ return _x - _y; }  
    private:
       T _x;
       U _y;
};

class Human{
    public:
       Human(string name, int age) : _name(name), _age(age){}
       string getName(){return _name;}
       int getAge(){return _age;}
    private:
       string _name;
       int _age;
};

int main(){
    int x{5};
    int arr[3] {5,7,9};
    double y{4.6};
    int *p{&x};
    
    //-----------------------       
    vector<int> v {1,2,3,4,5,6};
    map<int, int> m { {0,1}, {2,3}, {4,5} };
    list<int> l {5, 7, 8};
    
    //-----------------------    
    Human h1 {"Bob", 37};       
    cout << h1.getAge() << " " << h1.getName() << endl;
    
    //-----------------------
    Calculator <int, double> c1{5, 6.6};
    cout << c1.mul() << " " << c1.sub() << endl;

    Calculator <double, int> c2{5.5, 6};
    cout << c2.mul() << " " << c2.sub() << endl;
    
    return 0;
}


