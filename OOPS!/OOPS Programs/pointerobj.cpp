// #include<iostream>
// using namespace std;
// class demo{

// int a;
// public:
// demo () {
// }
// demo(int aa)
// {
// a=aa;
// }
// void display()
// {
// cout << a<<endl;
// }
// };
// int main()
// {
// demo *p=new demo[2]{demo(1),demo(2)};
// demo *pp=new demo(27);
// pp->display();
// p->display();
// (p+1)->display();
// delete[]p;}

#include<iostream>
using namespace std;
class ex{
    static int x;
public:
static void display(){
    cout<<x<<" ";
    x++;
}
};

int ex::x=1;
int main(){
    ex e1,e2;
    // e1.display();
    // e2.display();
    ex::display();
    ex::display();
}