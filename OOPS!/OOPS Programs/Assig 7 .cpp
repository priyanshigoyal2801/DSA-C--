#include<iostream>
using namespace std;
class Test{
int i;
public:
	Test(){
		i=1;
	}
friend void operator - (Test &x);
void show(){cout<<i;} 
};
void operator-(Test &x){
x.i= -x.i;
}
int main(){
Test x1;
-x1;
x1.show();
}
