#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void f1(){
   for(int i = 0; i < 100; i++)
      cout << "id th1: " <<  this_thread::get_id() << endl;
}

class c1{
public:
   void operator()(){
      for(int i = 0; i < 100; i++)
         cout << "id th2: " <<  this_thread::get_id() << endl;
   }
};

auto l1 = [](){
   for(int i = 0; i < 100; i++)
      cout << "id th3: " <<  this_thread::get_id() << endl;
   };

void f2(){
   //To get the identifier for the current thread use
   cout << "id th5: " <<  this_thread::get_id() << endl;
}

int main(){
   thread th1(f1);
   thread th2( (c1()) );
   thread th3(l1);   

   //member function, gives id of associated thread object   
   cout << "id th1: " << th1.get_id() << endl;
   cout << "id th2: " << th2.get_id() << endl;
   cout << "id th3: " << th3.get_id() << endl;
   cout << "id th4: " << this_thread::get_id() << endl;         

   for(int i = 0; i < 100; i++)
      cout <<  "id th4: " << this_thread::get_id() << endl; 

   if(th1.joinable())
      th1.join();
   if(th2.joinable())      
      th2.join();
   if(th3.joinable())
      th3.join();   

   cout <<"Exit 1 of Main function" << endl;
   cout <<"---------------------" << endl;   

   //vector of threads
   vector<thread> tList;   
   for(int i=0; i<10; i++)
      tList.push_back( thread(f2) );
      
   for(auto t = tList.begin(); t != tList.end(); t++){
      if((*t).joinable())
         (*t).join();
   }
   
   cout << "Exiting 2 from Main Thread" << endl;   

   return 0;
}




