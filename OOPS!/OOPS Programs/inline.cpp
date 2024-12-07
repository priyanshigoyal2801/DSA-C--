#include <iostream>
using namespace std;
class Y;
class X
{
    int x;
    static int count;

public:
    X()
    {
        x = 19;
    }
    void display();
    friend void swap(X &x1, Y &y1);
};
int X :: count = 10;
class Y
{
    int y; 

public:
    Y()
    {
        y = 20;
    }
    friend void swap(X &x1, Y &y1);
    void display();
};
void X::display()
{
    cout << x << " " << count;
}
void Y::display()
{
    cout << y;
}
void swap(X &x1, Y &y1)
{
    int temp = x1.x;
    x1.x = y1.y;
    y1.y = temp;
}
int main()
{
    X x;
    Y y1;
    swap(x, y1);
    x.display();
    cout << endl;
    y1.display();
    return 0;
}

/*
//static declaration
static int <function> (){

}

//static definition
int <class> :: <function> (){
    // static data -> int <class> :: <variable>;
}

//static function calling
int main(){
    A::fun(obj1, obj2);
}

// friend declaration
friend int <function> (){

}

// friend definition
int <function> (){

}

//inline declaration
inline int <function> (){
    //inline is in requesting mode when included in a class
}

//inline definition
int <class> :: <function> (){

}

*/