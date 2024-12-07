#include <iostream>
#include <string>
using namespace std;
#define max_size 10
int hashmap[26]={0};
class queues{
    private:
        int queue[max_size];
        int front=-1;
        int rear=-1;
    public:
        void enqueue(int element){
            if(rear>=max_size-1){
                cout<<"Queue Overflow"<<endl;
            }
            else{
                if(front==-1 && rear==-1){
                    front=0;
                    rear=0;
                    queue[rear]=element;
                }
                else{
                    rear++;
                    queue[rear]=element;
                }
            }
        }
        void dequeue(){
            if(front==-1||front>rear){
                cout<<"Queue Underflow"<<endl;
            }
            else{
                front++;
            }
        }
        void display(){
            if(front==-1||front>rear){
                cout<<"Queue Underflow"<<endl;
            }
            else{
                for(int i=front;i<=rear;i++){
                    cout<<queue[i]<<" ";
                }
                cout<<endl;
            }
        }
        bool isEmpty(){
            return front==-1||front>rear;
        }
        bool isFull(){
            return rear>=max_size-1;
        }
        int peek(){
            if(front==-1||front>rear){
                return -1;
            }
            else{
                return queue[front];
            }
        }
};
void hashing(string s){
    for(int i=0;i<s.length();i++){
        hashmap[s[i]-'a']++;
    }
}
int main(){
    queues q;
    string expr;
    cout<<"Enter String: ";
    cin>>expr;
    hashing(expr);
    for(int i=0;i<expr.length();i++){
        q.enqueue(expr[i]);
        while(!q.isEmpty()&&hashmap[q.peek()-'a']>1){
            q.dequeue();
        }
        if(q.isEmpty()){
            cout<<" -1 ";
        }
        else{
            cout<<q.peek()<<" ";
        }
    }
    cout<<endl;
    return 0;
}