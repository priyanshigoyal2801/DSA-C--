#include<iostream>
#include<string>
using namespace std;
class rectangle{
	private:
	int width;
	int height;
	public:
	void getdata(){
		cout<<"enter height of reactangle in cm";
		cin>>height;
		cout<<"enter width of rectangle in cm";
		cin>>width;
		
	}
	void calculateArea(){
		cout<<"area of rectangle is"<<height*width<<"cm^2";
		
	}
	
};
int main(){
	rectangle r;
	r.getdata();
	r.calculateArea();
	
}
