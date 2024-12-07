////#include<iostream>
////using namespace std;
////class b;
////class a{
////	
////		int x;
////	public:
////	a(){
////		x=10;
////}
////friend void compare(a &, b &);
////};
////class b{
////	int y;
////	public:
////		b(){
////			y=10;
////		}
////		friend void compare(a & , b &);
////};
////  void compare(a &x, b &y){
////  	if(this.x == this.y)
////  	cout<<"equal";
////  	else
////  	cout<<"not equal";
////  }
////int main(){
////	a x;
////	b y;
////	compare(x,y);
////	return 0;
////}
//
//#include<iostream>
//using namespace std;
//class B;
//class A{
//	int x;
//	public:
//		A(){
//			x=9;
//		}
//		void disp(){
//			cout<<x;
//		}
//};
//class B{
//	int y;
//	public:
//		B(){
//			y=8;
//		}
//		friend void class A:: disp();
//};
//int main(){
//	B bb;
//	A aa;
//	bb.disp();
//}

#include <iostream>

class ClassA;  

class ClassB {
public:
    void disp(ClassA& obj);  
};

class ClassA {
private:
    int privateData;

public:
    ClassA() : privateData(10){
	}
    friend void ClassB::disp(ClassA& obj);
};
void ClassB::disp(ClassA& obj) {
    std::cout << "ClassA's private data: " << obj.privateData << std::endl;
}
int main() {
    ClassA a;
    ClassB b;
    b.disp(a);  

    return 0;
}

