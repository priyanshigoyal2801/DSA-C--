#include<iostream>
using namespace std;
class Stack{
    public:
int *arr;
int size;
int top;
Stack(int size){
    this->size=size;
    top=-1;
    arr=new int[size];
}
void push(int element){
    if(size-top>1){
        top++;
        arr[top]=element;
    }
    else{
        cout<<"stack overflow";
    }
}
void pop(){
    if(top>=0){
        top--;
    }
    else{
        cout<<"stack underflow";
    }
}
int peek(){
    if(top>=0)
    return arr[top];
    else{
        cout<<"stack is empty";
        return -1;
    }
}
bool isEmpty(){
    if(top==-1)
    return true;
    else
    return false;

}
void print(){
    for(int i=top;i>=0;i--){
        cout<<arr[i];
    }
}
};
int main(){
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
   st.print();
   cout<<endl;
   st.pop();
   st.print();

}