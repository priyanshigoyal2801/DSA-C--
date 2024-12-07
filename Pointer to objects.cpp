//////#include<iostream>
//////using namespace std;
//////class A{
//////	public:
//////		
//////};
//////int main(){
//////	A *ptr=new A;
//////	
//////}
////
////#include<iostream>
////using namespace std;
////class shared{     
////    static int resource;
////public:
////    static int getResource(){  
////        if(resource)   
////            return 0;
////        else{
////            resource = 1;
////            return 1;      
////        }
////    }
////    void freeResource(){
////        resource = 0;
////    }
////};
////int shared :: resource;
////int main(){
////   shared o1, o2;
////   if(o1.getResource())
////        cout << "\no1 has resource.";
////   if(o2.getResource())
////        cout << "\no2 access denied.";
////   o1.freeResource();
////   if(shared :: getResource())
////        cout << "\no2 has resource.";
////   return 0;
////}
//
////EXAMPLE
//#include <iostream>
//using namespace std;
//class base {
//protected:
//int i;
//public:
//base(int x) 
//{ i=x; cout << "Constructing base\n"; }
//~base() { cout << "Destructing base\n"; }
//};
//class derived: public base {
//int j;
//public:derived(int x, int y): base(y)
//{ j=x; 
//cout << "Constructing derived\n"; }
//~derived() { cout << "Destructing derived\n"; }
//void show() { cout << i << " " << j << "\n"; }
//};
//int main()
//{
//derived ob(3, 4);
//ob.show(); // displays 4 3
//return 0;
//}
//
//
//
#include<iostream>
using namespace std;
class Animal{
public: 
virtual void sound() = 0;
void sleeping() {cout<<"Sleeping"; }
};
class Dog: public Animal{
public:
void sound() {cout<<"Woof"<<endl;}
};

int main(){ 
Dog d;
Dog *ptr;
ptr=&d;
ptr->sound();
}

