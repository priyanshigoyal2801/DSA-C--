#include<iostream>
using namespace std;
class Shape{
	public:
	const int area;
	
		Shape(int a):area(a){
		}
		void calculateArea(){
			cout<<"area of shape is"<<area;
		}
};
class Circle:public Shape{
	static int count;
	public:
		Circle(int radius):Shape(radius*radius*3.14){
			count++;
		}
		void calculateArea(){
			cout<<"Area of circle is "<<area<<endl;
		}
	static void countObj(){
			cout<<"No. of objects are " <<count;
		}
		
};
int Circle::count;
int main(){
	Circle c1(10),c2(20),c3(30);
	c1.calculateArea();
	c2.calculateArea();
	c3.calculateArea();
	c1.countObj();
}
