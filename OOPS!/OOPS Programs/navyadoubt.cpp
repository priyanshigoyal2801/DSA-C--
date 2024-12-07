#include<iostream>
using namespace std;
template<class T>
class num{
    T number;
   // B n;
    
    public:
    num(T num = 0) : number(num) {}
    
    void input(){
        cout<<"enter number"<<endl;
        cin>>number;
    }
    
    num operator+(const num& obj){
        num obj1;
        obj1.number=number+obj.number;
        return obj1;
    }
    
    void show(){
        cout<<"the sum is "<<number;
    }
};
int main(){
    num<int> n1,n2,sumint;
    n1.input();
    n2.input();
    sumint=n1+n2;
    sumint.show();
     num<double> nn1,nn2,sumdouble;
    nn1.input();
    nn2.input();
    sumdouble=nn1+nn2;
    sumdouble.show();
    return 0;
}