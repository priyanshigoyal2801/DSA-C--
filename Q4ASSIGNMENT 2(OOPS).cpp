#include<iostream>
using namespace std;
class complex{
	private:
	float real;
	float img;
	public:
		void setComplex(float r, float i){
			real=r;
			img=i;
		}
		void displayComplex(){
			cout<<real;
			if(img>=0){
				cout<<"+"<<img<<"i"<<endl;
			}
			else{
				cout<<"-"<<img<<"i"<<endl;
			}
		}
		complex addComplex(complex c){
			complex sum;
			sum.real=real+c.real;
			sum.img=img+c.img;
			 
            return sum;
		}
};
int main(){
	complex c1,c2,c3;
	c1.setComplex(2.4,3);
	cout << "First Complex Number: ";
	c1.displayComplex();
	cout << "Second Complex Number: ";
	c2.setComplex(2,5.6);
	c2.displayComplex();
	c3=c1.addComplex(c2);
	c3.displayComplex();
	
}
