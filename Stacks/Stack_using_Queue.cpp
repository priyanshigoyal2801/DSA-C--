#include<iostream>
#include<queue>
using namespace std;
class st{
    
    public:
queue<int> q;
void push(int x){
    int s=q.size();
    q.push(x);
    for(int i=0;i<s;i++){
        int y=q.front();
        q.push(y);
        q.pop();
    }
}
void pop(){
    q.pop();
}
void top(){
   cout<< q.front()<<endl;
}

};
int main(){
    st s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.pop();
    s.top();
     s.pop();
    s.top();

}
