#include<iostream>
using namespace std;
class base{
	public:
		 void disp(){
			cout<<"base display \n";
		}
	virtual	void show(){
			cout<<"show base\n";
		}
};
class derived: public base{
	public:
		void disp(){
			cout<<"derived display\n";
		}
		void show(){
			cout<<"show derived\n";
		}
};
int main(){
	base b;
	derived d;
	base *p;
	p=&d;
	p->disp();
	p->show();
	d.disp();
	}

