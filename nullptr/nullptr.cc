/*NULL is defined as (void *)0 and conversion of NULL to integer types is allowed.*/
#include <iostream>

using namespace std;

void fun(int n){ cout << "int" << endl; };
void fun(int *s){ cout << "int *" << endl; };

int main(){
    //causes compile time error since both functions available
    //fun(NULL);
    
    //Like NULL, nullptr is convertible to any pointer type. 
    fun(nullptr); //no compile error    
    
    int y = NULL; //no compile error
    //Unlike NULL, nullptr is not convertible to integral types.
    //int x = nullptr;
    
    int *ptr = nullptr;
    //nullptr is convertible to boolean
    if(ptr == nullptr) {cout << "true" << endl;}
    else {cout << "false" << endl;}
    
    //nullptr is convertible to bool
    nullptr_t np1, np2;
    if( np1 >= np2){cout << "comparable" << endl;}
    else {cout << "not comparable" << endl;}

    //can be checked if a pointer type is nullptr 
    char *n = np1;
    if(n==nullptr){cout << "x is null" << endl;}
    else {cout << "x is not null" << endl;}    
    
    return 0;
}


