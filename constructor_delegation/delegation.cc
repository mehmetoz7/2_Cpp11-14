/*
constructor has ability to call another constructor of the same
class
*/
#include <iostream>
  
using namespace std;

class Test{
public:
    int x, y, z;
    Test(){x=0; y=0; z=0;}
    Test(int z):Test(){
       this->z = z; //only z is updated
    }
};

int main(){
    Test t(3);
    cout << t.x << " " << t.y << " " << t.z << endl;
    return 0;
}
