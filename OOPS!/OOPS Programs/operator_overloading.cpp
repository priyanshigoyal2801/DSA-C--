#include<iostream>
using namespace std;
class demo{
    int a;
    public:
    demo(int a){
        this->a=a;
    }
    friend void operator ++(demo &d1,int);
    void show(){
        cout<<a;
    }
};
void operator ++(demo &d1,int){
d1.a+=1;
}


int main(){
    demo d1(7);
    d1++;
    d1.show();
}
