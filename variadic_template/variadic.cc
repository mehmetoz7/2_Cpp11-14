#include <iostream>

using namespace std;

auto sum(){return 0;}

template<typename H, typename ... ARGS>
auto sum(H h, ARGS ...t){
    return h + sum(t...);
}

int main(){
    cout << sum(4,5,6.7,8) << endl;
    return 0;
}


