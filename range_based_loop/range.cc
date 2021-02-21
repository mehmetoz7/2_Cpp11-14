#include <iostream>
#include <vector> 
#include <map>
  
using namespace std;

int main(){
    vector< int > v { 1, 2, 3, 4, 5, 6 };    
    for ( vector< int >::const_iterator i = v.begin(); i!= v.end(); ++i )
       cout << *i << ' ';            
    cout << endl;

    for ( auto i = v.begin(); i != v.end(); ++i )
       cout << *i << ' ';            
    cout << endl;
    
    for ( auto i : v )
       cout << i << ' ';            
    cout << endl;
    
    
    //----------------------------        
    map<int, int> m { {0,1}, {2,3}, {4,5} };
    for ( map<int,int>::iterator i=m.begin(); i !=m.end(); ++i )
       cout << i->first << " => " << i->second << '\n';
    cout << endl;
    
    for ( auto i=m.begin(); i !=m.end(); ++i )
       cout << i->first << " => " << i->second << '\n';
    cout << endl;    

    for ( auto i : m )
       cout << i.first << " => " << i.second << '\n';
    cout << endl;    
    
    //----------------------------
    string s = "marco van basten";
    for(auto c : s)
       cout << c;
    cout << endl;
    
    
   
    return 0;
}
