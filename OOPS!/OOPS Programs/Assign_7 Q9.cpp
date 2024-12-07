#include <iostream>
using namespace std;
class Test
{
    float f;
    public:
    Test(){
        f=9;
    }
public:
    operator float()
    {
        return 7.0f;
    }
    
};
int main(){
    Test t;
    float f=t;
    cout<<f;

}