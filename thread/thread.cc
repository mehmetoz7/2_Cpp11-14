#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <string>
#include <condition_variable>
#include <functional> //for bind

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

mutex mtx;
void f5(int n, char c){
   mtx.lock();
   for(int i=0; i<n; i++)
      cout << c;
   cout << endl;
   mtx.unlock();
}

void f6(int n, char c){
   lock_guard<mutex> lockGuard(mtx);
   for(int i=0; i<n; i++)
      cout << c;
   cout << endl;
}

class c3{
   mutex m_mutex;
   bool m_bDataLoaded;
public:
   c3(){ m_bDataLoaded = false; }   
   void loadData(){
      this_thread::sleep_for(chrono::milliseconds(1000));
      cout << "Loaded Data from XML" << endl;
      m_mutex.lock();
      m_bDataLoaded = true;
      m_mutex.unlock();
    }        
    void mainTask(){
       cout << "Do Some Handshaking" << endl;       
       m_mutex.lock();
       while(m_bDataLoaded != true){
          m_mutex.unlock();
          cout << "waiting event" << endl;
          this_thread::sleep_for(chrono::milliseconds(100));
          m_mutex.lock();          
       }
       m_mutex.unlock();
       this_thread::sleep_for(chrono::milliseconds(500));       
       cout << "Do Processing On loaded Data" << endl;
   }
};

class c4{
   mutex m_mutex;
   condition_variable cv1;
   bool m_bDataLoaded;
public:
   c4(){ m_bDataLoaded = false; }
   void loadData(){
      this_thread::sleep_for(chrono::milliseconds(1000));
      cout<<"Loading Data from XML"<<endl;
      
      lock_guard<mutex> guard(m_mutex);
      m_bDataLoaded = true;
            
      cv1.notify_one();
   }
   
   bool isDataLoaded(){ return m_bDataLoaded; }
   
   void mainTask(){
      cout << "Do Some Handshaking" << endl;
      unique_lock<mutex> mlock(m_mutex);
      cv1.wait(mlock, bind(&c4::isDataLoaded, this));
      cout << "Do Processing On loaded Data" << endl;
   }
};


mutex mtx2;
condition_variable cv2;
bool ready = false;
bool isReady(){ return ready; }

void print_id (int id) {
   unique_lock<mutex> lck(mtx2);
   cv2.wait(lck, bind(isReady));
   cout << "thread " << id << '\n';
}

void go() {
   unique_lock<mutex> lck(mtx2);
   ready = true;
   cv2.notify_all();
}

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
      
   for(auto& th : tList){
      if(th.joinable())
         th.join();
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
   
   //syncronization with mutex   
   cout << "mutex synchronization" << endl;           
   thread th8(f5, 500, '*');
   thread th9(f5, 500, '-');
   th8.join();
   th9.join();
   
   //syncronization with lock_guard   
   cout << "lock_guard synchronization" << endl;              
   thread th10(f6, 500, '*');
   thread th11(f6, 500, '-');   
   th10.join();
   th11.join();   
   cout <<"---------------------" << endl;   
   
   //event handling
   c3 app1;
   thread th12(&c3::mainTask, &app1);
   thread th13(&c3::loadData, &app1);
   th12.join();
   th13.join();
   cout <<"---------------------" << endl;   

   //condition variable   
   c4 app2;
   std::thread th14(&c4::mainTask, &app2);
   std::thread th15(&c4::loadData, &app2);
   th14.join();
   th15.join();
   cout <<"---------------------" << endl; 
   
   vector<thread> tL;
   for (int i=0; i<10; ++i)
      tL.push_back(thread(print_id,i));

   cout << "10 threads getting ready to race...\n";
   this_thread::sleep_for(chrono::milliseconds(1000));   
   go();

   for (auto& th : tL) th.join();   
   cout <<"---------------------" << endl; 
      
   
   return 0;
}




