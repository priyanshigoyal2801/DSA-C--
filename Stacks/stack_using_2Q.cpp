#include <iostream>
#include <queue>
using namespace std;
class S2Q
{
public:
    queue<int> q1, q2;
    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    void pop()
    {
        if (!q1.empty())
        {
            q1.pop();
        }
        else{
            cout<<"empty stack";
        }
    }
    void topp()
    {
        cout << q1.front();
    }
};
int main()
{
    S2Q s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    
}