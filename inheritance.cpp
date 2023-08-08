// Online C++ compiler to run C++ program online
//protected interal members in a class are same as internal private members
//derived protected members are same as internal private members from same class
//===========================================================================
/*                          
                            derived class
                  public      private     protected
base class
public            public      private     protected
private          hidden      hidden       hidden
protected       protected    private     protected

*/
#include <iostream>
using namespace std;

class A{
public:
    int x;
    void callPrinterA(){
        printX();
    }
private:
    void printX(){
        cout<<"x is "<<x<<endl;
    }

protected:
    void helloA(){
        cout<<"hello A"<<endl;
    }
};

class B:public A{
public:
    void callHello(){//can call protected functions from  base class
        helloA();
    }
//  can't call private functions of base class.
    /*
    void callPrinter(){
        printX();
    }
    */
};


int main() {
    A a1;
    a1.x=11;
    cout<<a1.x<<endl;
    a1.callPrinterA();
    //a1.printX()   printX is private
    //a1.helloA();  helloA is protected
    B b1;
    b1.x=22;
    cout<<b1.x<<endl;
    b1.callPrinterA();//since callPrinterA is a public fnc of base class and printX private fnc is within its scope.
    
    //b1.printX();  printX is private
    //b1.helloA();  helloA is protected
    b1.callHello(); //since callHello is a publilc function and class B is derived public from A and helloA is a protected function will remain protected
    b1.callPrinterA();
    
    
    return 0;
}
