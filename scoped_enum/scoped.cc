#include <iostream>
  
using namespace std;

int main(){
    enum class color{red, green, blue, yellow};
    
    color col1 = color::red;
    color col2 = color::green;
    
    if(col1 == color::red)
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;        
        
    cout << static_cast<int>(col2) << endl;
    //---------------------------
    
    enum old_color{lila, pink, white, black};
    int number =old_color::white;
    cout << number << endl;
    
    if(number == 2)
        cout << "equal" << endl;    
    
    //causes error at compile time
    //number = color::red;
        
    number = static_cast<int>(color::yellow);
    cout << number << endl;
    
    return 0;
}


