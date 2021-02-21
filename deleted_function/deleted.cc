#include <iostream>
  
using namespace std;

class Human{
    public:
       Human()=default;
       Human(string name, int age) : _name(name), _age(age){}

       string getName(){return _name;}
       Human& setName(string n){
          _name = n;
          return *this;
          }
       
       int getAge(){return _age;}
       Human& setAge(int a){
          _age=a;
           return *this;
       }
       
    private:
       string _name;
       int _age;
};

int main(){
    Human h;      
    
    h.setAge(67).setName("Ruud Gullit");
    cout << h.getAge() << " " << h.getName() << endl;    
    return 0;
}


