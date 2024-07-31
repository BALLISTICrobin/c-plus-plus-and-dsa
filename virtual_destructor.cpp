#include<iostream>
using namespace std;

class base {

public:
base(){
    cout<<"base constructor\n";
}
  virtual ~base() {
      cout << "base destructor\n";
   }

   virtual void f1() {
      cout << "base f1\n";
   }
};
class derived :  public base {
public:
derived(){
    cout<<"derived constructor\n";
}
   ~derived() {
      cout << "derived destructor\n";
   }
void f1() {
      cout << "derived f1\n";
   }
   void f2() {
      cout << "derived f2\n";
   }
};
int main() {

   base *p = new derived;
   p->f1();
   delete p;
   return 0;
}
