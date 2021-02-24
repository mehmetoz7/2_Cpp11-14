/*
if there is no user defined constructor in the class, compiler
creates a constructor implicitily. if there is a constructor
compiler does not create one. To make compiler generate this effective contructor it is being made default.

a function that is explicitely defaulted must be a special member
function and has no default argument
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>
  
using namespace std;

class Human{
    public:
       //adding =default to the code makes compiler add 
       //default constructor implicitily
       Human()=default; //let make compiler generate it
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


