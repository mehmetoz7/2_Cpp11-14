/*-----------------------------------------------
* Special member function prototypes
Default constructor	C::C();
Destructor		C::~C();
Copy constructor	C::C (const C&);
Copy assignment	C& operator= (const C&);
Move constructor	C::C (C&&);
Move assignment	C& operator= (C&&);
-----------------------------------------------*/
#include <iostream>
  
using namespace std;

class Human{
    public:           
       //disable copy constructor
       Human(const Human&)=delete;
       
       //disable copy assignment
       Human& operator=(const Human&)=delete; 
       
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
    Human h1("Ronald Koemann", 65); 
    Human h2;    
        
    h2 = h1;       //copy assignment  causes compile error
    Human h3 = h2; //copy constructor causes compile error
      
    return 0;
}


