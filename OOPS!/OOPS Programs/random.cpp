#include<iostream>
using namespace std;
class demo{
    static int x;
    public:
    demo(){
        x=1;
    }
    void display(){
        cout<<x;
    }
};
int demo::x=100;
int main(){
    demo d1;
    d1.display();
}
