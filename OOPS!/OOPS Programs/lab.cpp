#include<iostream>
using namespace std;
// class a{
// public:
//  a(int a){
//     cout<<"const"<<a<<endl;
// }
//  ~a(){
//     cout<<"de"<<endl;
// }
// };
// class b:public a{
//    public:
//    b(int ab):a(ab){
// cout<<"derived"<<endl;
//    }
//    ~b(){
//     cout<<"hehe"<<endl;
//    }
// };
// int main(){
//     b B(6);

// }
void add(double a,float b){
    cout<<a*b;
}
void add(int a,int b){
    cout<<a+b;
}
int main(){
    add(2.5,3.5);
}