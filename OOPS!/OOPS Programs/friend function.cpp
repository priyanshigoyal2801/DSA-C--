#include <iostream>
using namespace std;
class ClassA;
class ClassB
{
public:
    void disp(ClassA &obj);
};

class ClassA
{
private:
    int privateData;

public:
    ClassA() : privateData(10) {}
    friend void ClassB::disp(ClassA &obj);
};
void ClassB::disp(ClassA &obj)
{
    cout << "ClassA's private data: " << obj.privateData << endl;
}
int main()
{
    ClassA a;
    ClassB b;
    b.disp(a);

    return 0;
}