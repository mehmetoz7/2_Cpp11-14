#include <iostream>
#include <thread>
#include <vector>
#include <string>

using namespace std;

void f1(){
   for(int i = 0; i < 3; i++)
      cout << "id th1: " <<  this_thread::get_id() << endl;
}

class c1{
public:
   void operator()(){
      for(int i = 0; i < 3; i++)
         cout << "id th2: " <<  this_thread::get_id() << endl;
   }
};

auto l1 = 
[](){
for(int i = 0; i < 3; i++)
   cout << "id th3: " <<  this_thread::get_id() << endl;
};

void f2(){
   //To get the identifier for the current thread use
   cout << "id th4: " <<  this_thread::get_id() << endl;
}

void f3(int x, string str)
{
    cout << "id th5: " <<  this_thread::get_id() << endl;    
    cout << "Passed Number = " << x << " ";
    cout << "Passed String = " << str << endl;
}

void f4(int const & x){
    int & y = const_cast<int &>(x);
    y++;
    cout << "id th6: " <<  this_thread::get_id() << endl;        
    cout << "Inside Thread x = " << x << endl;
}

class c2 {
public:
   c2(){}
   c2(const c2 & obj){}
   void c2_MemberFunction(int *x){
      *x = *x + 1;
      cout << "id th7: " <<  this_thread::get_id();      
      cout << endl << "c2_MemberFunction " << *x << endl;
   }
};

//--------------------------------------------------------

int main(){
   //3 ways to create thread
   thread th1(f1);
   thread th2( (c1()) );
   thread th3(l1);   

   //member function, gives id of associated thread object   
   cout << "id th1: " << th1.get_id() << endl;
   cout << "id th2: " << th2.get_id() << endl;
   cout << "id th3: " << th3.get_id() << endl;
   cout << "id th4: " << this_thread::get_id() << endl;         

   for(int i = 0; i < 3; i++)
      cout <<  "id th4: " << this_thread::get_id() << endl; 

   //th1 is a deamon and not joinable anymore
   th1.detach();

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
   cout <<"---------------------" << endl;   
   
   //passing parameters to a thread
   int x1 = 10;
   string str = "Sample String";

   thread th5(f3, x1, str);
   th5.join();

   cout << "Exiting 3 from Main Thread" << endl;   
   cout <<"---------------------" << endl;   

   //passing parameters with reference 
   int x2 = 9;
   cout << "In Main Thread x : " << x2 << endl;
   thread th6(f4, ref(x2));
   th6.join();
   cout << "In Main Thread x : " << x2 << endl;
   cout << "Exiting 4 from Main Thread" << endl;
   cout <<"---------------------" << endl;   

   //passing parameters with pointer
   c2 dummyObj;
   int x3 = 10;
   cout << "In Main Thread x : " << x3 << endl;   
   //thread function, class obj, parameter are passed  
   thread th7(&c2::c2_MemberFunction, &dummyObj, &x3);
   th7.join();
   cout << "In Main Thread x : " << x3 << endl;
   cout << "Exiting 5 from Main Thread" << endl;      
   cout <<"---------------------" << endl;   
      
      
   return 0;
}




