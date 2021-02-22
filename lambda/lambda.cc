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
  
using namespace std;

int main(){
    vector <int> v {1,2,3,4,5,6,7,8,9};
    for_each(v.begin(), v.end(), [](int i){cout << i << " ";});
    cout << endl;
    
    return 0;
}


