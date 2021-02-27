/*automatically deallocate objects when it is out of scope*/
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

class Test{
private:
    int val = 0;
public:
    Test()=default;
    Test(int i) : val(i){}
    //copy constructor
    Test (const Test& x):val(x.val){}
    
    void set(int i){val = i;}
    void show(){cout << val << endl;}
};

int main(){   
   //classic memory allocation
   int *ptr = new int[5];
   //must delete in case of memory leak
   delete ptr;
   //-----------------------------
   //there are 3 ways to bind an abject to a smart pointer
   unique_ptr<int> w1(new int(5)); //way 1
   
   auto w2 = make_unique<int>(20); //way 2
   
   unique_ptr<int>w3; //way 3
   w3.reset(new int(17));
   //-----------------------------   
   
   //if one object is created and unique_ptr is pointing this
   //object, only one pointer can point the object at the same time
   unique_ptr<Test> t1(new Test{5});
   t1->show();
   
   //returns a pointer to the managed object
   cout << "t1 address:" << t1.get() << endl;
   
   unique_ptr<Test> t2(new Test);
   t2 = move(t1);
   cout << "t1 address:" << t1.get() << endl; //null
   cout << "t2 address:" << t2.get() << endl << endl; 
   //-----------------------------
   
   //more than one pointer can point to object at the same time
   shared_ptr<Test> t3(new Test{5});
   shared_ptr<Test> t4(t3); //copy constructor

   //returns the same memory address   
   cout << "t3 address:" << t3.get() << endl; 
   cout << "t4 address:" << t4.get() << endl;    
   cout << "use_count:" << t3.use_count() << endl;
   //object will not be destroyed if ref count is bigger than 0
   t4.reset(); 
   cout << "t3 address:" << t3.get() << endl; 
   cout << "t4 address:" << t4.get() << endl;    //null
   cout << "use_count:" << t3.use_count() << endl << endl;
   //-----------------------------
   
   unique_ptr<int[]> arr(new int[5]{1,2,3,4,5});
   for(int i=0; i<5; i++) cout << arr[i] << " ";
   cout << endl;
   
   unique_ptr<vector<int>> v(new vector<int>{1,2,3,4,5});
   v->push_back(8);   
   for(auto i: *v) {cout << i << " ";}
   cout << endl;
   //-----------------------------
   
      
   
   return 0;
}



