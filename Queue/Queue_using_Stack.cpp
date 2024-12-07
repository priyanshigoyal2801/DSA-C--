#include<iostream>
#include<stack>
using namespace std;
class q{
    public:
stack<int> s1,s2;
void push(int x){
    while(s1.size()){

        s2.push(s1.top());
        s1.pop();
    }
    s1.push(x);
    while(s2.size()){
        s1.push(s2.top());
        s2.pop(); 
    }
}
void pop(){
    s1.pop();

}
void top(){
    cout<<s1.top()<<endl;
}
};
int main(){
    q q1;
    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(40);
    q1.pop();
    q1.top();
    q1.push(2);
    q1.pop();
    q1.top();
}

// approach 2
// #include <iostream>
// #include <stack>
// using namespace std;
// class q
// {
// public:
//     stack<int> s1, s2;
//     void push(int x)
//     {
//         s1.push(x);
//     }
//     void pop()
//     {
//         if (s2.empty() != 0)
//         {
//             s2.pop();
//         }
//         else
//         {
//             while (s1.size())
//             {
//                 s2.push(s1.top());
//                 s1.pop();
//             }
//             s2.pop();
//         }
//     }
//     void top()
//     {
//         if (s2.empty() != 0)
//         {
//             cout << s2.top() << endl;
//         }
//         else
//         {
//             while (s1.size())
//             {
//                 s2.push(s1.top());
//                 s1.pop();
//             }
//             cout << s2.top() << endl;
//         }
//     }
// };
// int main()
// {
//     q q1;
//     q1.push(10);
//     q1.push(20);
//     q1.push(30);
//     q1.push(40);
//     q1.pop();
//     q1.top();
//     q1.push(2);
//     q1.pop();
//     q1.top();
// }
