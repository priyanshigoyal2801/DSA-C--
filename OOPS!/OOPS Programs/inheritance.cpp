#include <iostream>
using namespace std;
#include <iostream>

class Base {
public:
    // Virtual destructor to ensure proper destruction of derived classes
    ~Base() {
   cout << "Base class destructor called" << endl;
    }
};

class Derived : public Base {
public:
    ~Derived() {
    cout << "Derived class destructor called" << std::endl;
    }
};

int main() {
    Base* obj = new Derived(); // Polymorphic behavior
    delete obj;  // Correctly calls Derived's destructor followed by Base's destructor
    return 0;
}

// class A{    
//     public :
//     int a;
//     A(int x){
//         a=x;
//     }
    
// };
// class B : public A{
//     public :
//     int b;
//     B(int x, int y ) : A(x) {
//         b=y;
//     }
    
// };
// class C: virtual public A {
//     public:
//     int c;  
//     C(){
//         c=30;
//     }
// };
// class D: public B, public C{
//     public :
//     int d;
//     D(){
//         d=40;
// //     }
// // };
// int main()
// {
//     B bb(4,5);
//     cout << bb.a << " " << bb.b;
//     // D dd;
//     // cout << dd.a << ' ' << dd.b << " " << dd.c << " " << dd.d;
//     return 0;
// }