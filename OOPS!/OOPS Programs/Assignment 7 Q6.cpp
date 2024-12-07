#include <iostream>
using namespace std;
class Time
{
    int h, m, s;

public:
    Time() {}
    Time(int h, int m, int s)
    {
        this->h = h;
        this->m = m;
        this->s = s;
    }
    Time operator+(Time t)
    {
        Time t3;
        t3.s = s + t.s;
        t3.m = m + t.m + t3.s/ 60;
        t3.s %= 60;
        t3.h = h + t.h + t3.m/ 60;
        t3.m %= 60;
        return t3;
    }
    void show()
    {
        cout << (h < 10 ? "0" : "") << h << ":"
             << (m < 10 ? "0" : "") << m << ":"
             << (s < 10 ? "0" : "") << s << endl;
    }
};
int main(){
    Time t1(5,15,34),t2(9,53,58),t3;
t3 = t1 + t2; t3.show();
}