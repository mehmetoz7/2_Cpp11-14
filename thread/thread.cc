#include <iostream>
#include <thread>

using namespace std;

void thread_function(){
   for(int i = 0; i < 20; i++)
      cout << "id th1: " <<  this_thread::get_id() << endl;
}

class DisplayThread{
public:
   void operator()(){
      for(int i = 0; i < 20; i++)
         cout << "id th2: " <<  this_thread::get_id() << endl;
   }
};

int main(){
   thread th1(thread_function);
   thread th2( (DisplayThread()) );
   thread th3([]{
      for(int i = 0; i < 20; i++)
         cout << "id th3: " <<  this_thread::get_id() << endl;
      });   
      
   cout << "id th1: " << th1.get_id() << endl;
   cout << "id th2: " << th2.get_id() << endl;
   cout << "id th3: " << th3.get_id() << endl;
   cout << "id th4: " << this_thread::get_id() << endl;         

   for(int i = 0; i < 20; i++)
      cout <<  "id th4: " << this_thread::get_id() << endl; 

   th1.join();
   th2.join();
   th3.join();   

   cout <<"Exit of Main function" << endl;

   return 0;
}


