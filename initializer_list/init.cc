#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>
  
using namespace std;

template <class T>
class Sample{
    public:
       Sample(initializer_list<T> il){
          for(auto i : il)
             v.push_back(i);
       }
       void Print(){
          for(auto i:v)
             cout << i << " ";
          cout << endl;
       }
    private:
       vector<T>v;
};

int main(){
    Sample<int> s1 {1,2,3,4,5};
    s1.Print();
    
    Sample<double> s2 {1.8, 2.7, 3.8, 4.0, 5.9};
    s2.Print();
    
    return 0;
}


