#include <iostream>
#include <vector> 
#include <map>
  
using namespace std;

template<typename T, typename U>
auto add (T t, U u)
{
   cout << typeid(t).name() << " " << typeid(u).name() << endl;
   return t+u;
}
 
int main(){
    auto x = 44; //shold be initialized at decleration
    auto y = 55.9;
    auto p = &x;
    auto pp = &p;
    auto ppp = &pp;  
    
    cout << typeid(x).name() << endl;
    cout << typeid(y).name() << endl;
    cout << typeid(p).name() << endl;    
    cout << typeid(pp).name() << endl;
    cout << typeid(ppp).name() << endl;

    //----------------------------
    cout << add(3, 4.5) << endl;

    //----------------------------    
    vector< int > v { 1, 2, 3, 4, 5, 6 };    
    for ( vector< int >::const_iterator i = v.begin(); i!= v.end(); ++i )
       cout << *i << ' ';            
    cout << endl;

    for ( auto i = v.begin(); i != v.end(); ++i )
       cout << *i << ' ';            
    cout << endl;
    
    //----------------------------        
    map<int, int> m { {0,1}, {2,3}, {4,5} };
    for (map<int,int>::iterator i=m.begin(); i !=m.end(); ++i)
       cout << i->first << " => " << i->second << '\n';
    cout << endl;
    
    for (auto i=m.begin(); i !=m.end(); ++i)
       cout << i->first << " => " << i->second << '\n';
    cout << endl;    
    
    //----------------------------
   
    return 0;
}
