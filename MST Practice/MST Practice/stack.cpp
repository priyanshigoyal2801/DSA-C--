//Infix to Postfix
// #include <iostream>
// #include <string>
// using namespace std;
// #define max_size 30
// int priority(char op){
//     if(op=='^'){
//         return 3;
//     }
//     else if(op=='*'||op=='/'){
//         return 2;
//     }
//     else if(op=='-'||op=='+'){
//         return 1;
//     }
//     else{
//         return -1;
//     }
// }
// class stacks{
//     private:
//         char stack[max_size];
//         int tops=-1;
//     public:
//         void push(char element){
//             if(tops>=max_size-1){
//                 cout<<"Stack Overflow"<<endl;
//             }
//             else{
//                 tops++;
//                 stack[tops]=element;
//             }
//         }
//         void pop(){
//             if(tops<=-1){
//                 cout<<"Stack Underflow"<<endl;
//             }
//             else{
//                 tops--;
//             }
//         }
//         void display(){
//             if(tops<=-1){
//                 cout<<"Stack is Empty"<<endl;
//             }
//             else{
//                 for(int i=tops;i>=0;i--){
//                     cout<<"Element at index "<<i<<" is: "<<stack[i]<<endl;
//                 }
//             }
//         }
//         bool isEmpty(){
//             return tops<=-1;
//         }
//         bool isFull(){
//             return tops>=max_size-1;
//         }
//         char top(){
//             if (tops == -1) {
//                 return '\0'; // Return null character if stack is empty
//             }
//             return stack[tops];
//         }
// };
// int main(){
//     stacks st;
//     string expr,answer="";
//     cout<<"Enter Expression: ";
//     cin>>expr;
//     for(int i=0;i<expr.length();i++){
//         if((expr[i]>='A' && expr[i]<='Z')||(expr[i]>='a' && expr[i]<='z')||(expr[i]>=0 && expr[i]<=9)){
//             answer+=expr[i];
//         }
//         else if(expr[i]=='('){
//             st.push(expr[i]);
//         }
//         else if(expr[i]==')'){
//             while(!st.isEmpty() && st.top()!='('){
//                 answer+=st.top();
//                 st.pop();
//             }
//             st.pop();
//         }
//         else{
//             while(!st.isEmpty() && priority(expr[i])<=priority(st.top())){
//                 answer+=st.top();
//                 st.pop();
//             }
//             st.push(expr[i]);
//         }
//     }
//     while(!st.isEmpty()){
//         answer+=st.top();
//         st.pop(); 
//     }
//     cout<<"Postfix: "<<answer<<endl;
//     return 0;
// }

//Infix to Prefix
// #include <iostream>
// #include <string>
// using namespace std;
// #define max_size 30
// string reverseString(const string& str) {
//     string reversed=str;
//     int len=str.length();
//     for(int i=0;i<len/2;i++){
//         char back=reversed[i];
//         reversed[i]=reversed[len-i-1];
//         reversed[len-i-1]=back;
//     }
//     return reversed;
// }
// int priority(char op){
//     if(op=='^'){
//         return 3;
//     }
//     else if(op=='*'||op=='/'){
//         return 2;
//     }
//     else if(op=='-'||op=='+'){
//         return 1;
//     }
//     else{
//         return -1;
//     }
// }
// class stacks{
//     private:
//         char stack[max_size];
//         int tops=-1;
//     public:
//         void push(char element){
//             if(tops>=max_size-1){
//                 cout<<"Stack Overflow"<<endl;
//             }
//             else{
//                 tops++;
//                 stack[tops]=element;
//             }
//         }
//         void pop(){
//             if(tops<=-1){
//                 cout<<"Stack Underflow"<<endl;
//             }
//             else{
//                 tops--;
//             }
//         }
//         void display(){
//             if(tops<=-1){
//                 cout<<"Stack is Empty"<<endl;
//             }
//             else{
//                 for(int i=tops;i>=0;i--){
//                     cout<<"Element at index "<<i<<" is: "<<stack[i]<<endl;
//                 }
//             }
//         }
//         bool isEmpty(){
//             return tops<=-1;
//         }
//         bool isFull(){
//             return tops>=max_size-1;
//         }
//         char top(){
//             if (tops == -1) {
//                 return '\0'; // Return null character if stack is empty
//             }
//             return stack[tops];
//         }
// };
// int main(){
//     stacks st;
//     string expr,answer="";
//     cout<<"Enter Expression: ";
//     cin>>expr;
//     expr=reverseString(expr);
//     for(int i=0;i<expr.length();i++){
//         if(expr[i] == '('){
//             expr[i] = ')';
//         }
//         else if(expr[i]==')'){
//             expr[i]='(';
//         }
//     }
//     for(int i=0;i<expr.length();i++){
//         if((expr[i]>='A' && expr[i]<='Z')||(expr[i]>='a' && expr[i]<='z')||(expr[i]>=0 && expr[i]<=9)){
//             answer+=expr[i];
//         }
//         else if(expr[i]=='('){
//             st.push(expr[i]);
//         }
//         else if(expr[i]==')'){
//             while(!st.isEmpty() && st.top()!='('){
//                 answer+=st.top();
//                 st.pop();
//             }
//             st.pop();
//         }
//         else{
//             if(expr[i]=='^'){
//                 while(!st.isEmpty() && priority(expr[i])<=priority(st.top())){
//                     answer+=st.top();
//                     st.pop();
//                 }
//                 st.push(expr[i]);
//             }
//             else{
//                 while(!st.isEmpty() && priority(expr[i])<priority(st.top())){
//                     answer+=st.top();
//                     st.pop();
//                 }
//                 st.push(expr[i]);
//             }
//         }
//     }
//     while(!st.isEmpty()){
//         answer+=st.top();
//         st.pop(); 
//     }
//     answer=reverseString(answer);
//     cout<<"Postfix: "<<answer<<endl;
//     return 0;
// }

//Postfix to Infix
// #include <iostream>
// #include <string>
// using namespace std;
// #define max_size 20
// class stacks{
//     private:
//         string stack[max_size];
//         int tops=-1;
//     public:
//         void push(string element){
//             if(tops>=max_size-1){
//                 cout<<"Stack Overflow"<<endl;
//             }
//             else{
//                 tops++;
//                 stack[tops]=element;
//             }
//         }
//         void pop(){
//             if(tops<=-1){
//                 cout<<"Stack Underflow"<<endl;
//             }
//             else{
//                 tops--;
//             }
//         }
//         void display(){
//             if(tops<=-1){
//                 cout<<"Stack is Empty"<<endl;
//             }
//             else{
//                 for(int i=tops;i>=0;i--){
//                     cout<<"Element at index "<<i<<" is: "<<stack[i]<<endl;
//                 }
//             }
//         }
//         bool isEmpty(){
//             return tops<=-1;
//         }
//         bool isFull(){
//             return tops>=max_size-1;
//         }
//         string top(){
//             if (tops==-1){
//                 return '\0';
//             }
//             return stack[tops];
//         }
// };
// int main(){
//     stacks st;
//     string expr;
//     cout<<"Enter Expression: ";
//     cin>>expr;
//     for(int i=0;i<expr.length();i++){
//         if((expr[i]>='A' && expr[i]<='Z')||(expr[i]>='a' && expr[i]<='z')||(expr[i]>=0 && expr[i]<=9)){
//             string s(1,expr[i]);
//             st.push(s);
//         }
//         else{
//             string top1=st.top();
//             st.pop();
//             string top2=st.top();
//             st.pop();
//             st.push('('+top2+expr[i]+top1+')');
//         }
//     }
//     cout<<"Infix Expression: "<<st.top()<<endl;
//     return 0;
// }

//Prefix to Infix
// #include <iostream>
// #include <string>
// using namespace std;
// #define max_size 20
// class stacks{
//     private:
//         string stack[max_size];
//         int tops=-1;
//     public:
//         void push(string element){
//             if(tops>=max_size-1){
//                 cout<<"Stack Overflow"<<endl;
//             }
//             else{
//                 tops++;
//                 stack[tops]=element;
//             }
//         }
//         void pop(){
//             if(tops<=-1){
//                 cout<<"Stack Underflow"<<endl;
//             }
//             else{
//                 tops--;
//             }
//         }
//         void display(){
//             if(tops<=-1){
//                 cout<<"Stack is Empty"<<endl;
//             }
//             else{
//                 for(int i=tops;i>=0;i--){
//                     cout<<"Element at index "<<i<<" is: "<<stack[i]<<endl;
//                 }
//             }
//         }
//         bool isEmpty(){
//             return tops<=-1;
//         }
//         bool isFull(){
//             return tops>=max_size-1;
//         }
//         string top(){
//             if (tops==-1){
//                 return '\0';
//             }
//             return stack[tops];
//         }
// };
// int main(){
//     stacks st;
//     string expr;
//     cout<<"Enter Expression: ";
//     cin>>expr;
//     for(int i=expr.length()-1;i>=0;i--){
//         if((expr[i]>='A' && expr[i]<='Z')||(expr[i]>='a' && expr[i]<='z')||(expr[i]>=0 && expr[i]<=9)){
//             string s(1,expr[i]);
//             st.push(s);
//         }
//         else{
//             string top1=st.top();
//             st.pop();
//             string top2=st.top();
//             st.pop();
//             st.push('('+top1+expr[i]+top2+')');
//         }
//     }
//     cout<<"Infix Expression: "<<st.top()<<endl;
//     return 0;
// }

//Postfix to Prefix
// #include <iostream>
// #include <string>
// using namespace std;
// #define max_size 20
// class stacks{
//     private:
//         string stack[max_size];
//         int tops=-1;
//     public:
//         void push(string element){
//             if(tops>=max_size-1){
//                 cout<<"Stack Overflow"<<endl;
//             }
//             else{
//                 tops++;
//                 stack[tops]=element;
//             }
//         }
//         void pop(){
//             if(tops<=-1){
//                 cout<<"Stack Underflow"<<endl;
//             }
//             else{
//                 tops--;
//             }
//         }
//         void display(){
//             if(tops<=-1){
//                 cout<<"Stack is Empty"<<endl;
//             }
//             else{
//                 for(int i=tops;i>=0;i--){
//                     cout<<"Element at index "<<i<<" is: "<<stack[i]<<endl;
//                 }
//             }
//         }
//         bool isEmpty(){
//             return tops<=-1;
//         }
//         bool isFull(){
//             return tops>=max_size-1;
//         }
//         string top(){
//             if (tops==-1){
//                 return '\0';
//             }
//             return stack[tops];
//         }
// };
// int main(){
//     stacks st;
//     string expr;
//     cout<<"Enter Postfix Expression: ";
//     cin>>expr;
//     for(int i=0;i<expr.length();i++){
//         if((expr[i]>='A' && expr[i]<='Z')||(expr[i]>='a' && expr[i]<='z')||(expr[i]>=0 && expr[i]<=9)){
//             string s(1,expr[i]);
//             st.push(s);
//         }
//         else{
//             string top1=st.top();
//             st.pop();
//             string top2=st.top();
//             st.pop();
//             st.push(expr[i]+top2+top1);
//         }
//     }
//     cout<<"Prefix Expression: "<<st.top()<<endl;
//     return 0;
// }

//Prefix to Postfix
// #include <iostream>
// #include <string>
// using namespace std;
// #define max_size 20
// class stacks{
//     private:
//         string stack[max_size];
//         int tops=-1;
//     public:
//         void push(string element){
//             if(tops>=max_size-1){
//                 cout<<"Stack Overflow"<<endl;
//             }
//             else{
//                 tops++;
//                 stack[tops]=element;
//             }
//         }
//         void pop(){
//             if(tops<=-1){
//                 cout<<"Stack Underflow"<<endl;
//             }
//             else{
//                 tops--;
//             }
//         }
//         void display(){
//             if(tops<=-1){
//                 cout<<"Stack is Empty"<<endl;
//             }
//             else{
//                 for(int i=tops;i>=0;i--){
//                     cout<<"Element at index "<<i<<" is: "<<stack[i]<<endl;
//                 }
//             }
//         }
//         bool isEmpty(){
//             return tops<=-1;
//         }
//         bool isFull(){
//             return tops>=max_size-1;
//         }
//         string top(){
//             if (tops==-1){
//                 return '\0';
//             }
//             return stack[tops];
//         }
// };
// int main(){
//     stacks st;
//     string expr;
//     cout<<"Enter Postfix Expression: ";
//     cin>>expr;
//     for(int i=expr.length()-1;i>=0;i--){
//         if((expr[i]>='A' && expr[i]<='Z')||(expr[i]>='a' && expr[i]<='z')||(expr[i]>=0 && expr[i]<=9)){
//             string s(1,expr[i]);
//             st.push(s);
//         }
//         else{
//             string top1=st.top();
//             st.pop();
//             string top2=st.top();
//             st.pop();
//             st.push(top1+top2+expr[i]);
//         }
//     }
//     cout<<"Prefix Expression: "<<st.top()<<endl;
//     return 0;
// }

//Queues Using Stack
#include <iostream>
#define max_size 10
using namespace std;
class stacks{
    private:
        int stack[max_size];
        int tops=-1;
    public:
        void push(int element){
            if(tops>=max_size-1){
                cout<<"Stack Overflow"<<endl;
            }
            else{
                tops++;
                stack[tops]=element;
            }
        }
        void pop(){
            if(tops<=-1){
                cout<<"Stack Underflow"<<endl;
            }
            else{
                tops--;
            }
        }
        void display(){
            if(tops<=-1){
                cout<<"Stack is Empty"<<endl;
            }
            else{
                for(int i=tops;i>=0;i--){
                    cout<<"Element at index "<<i<<" is: "<<stack[i]<<endl;
                }
            }
        }
        bool isEmpty(){
            return tops<=-1;
        }
        bool isFull(){
            return tops>=max_size-1;
        }
        int top(){
            if (tops==-1){
                return -1;
            }
            return stack[tops];
        }
        int getTopIndex(){
            return tops;
        }
};
class queue{
    private:
        stacks st1,st2;
    public:
        void enqueue(int value){
            if(st1.getTopIndex()>=max_size-1){
                cout<<"Queue Overflow"<<endl;
            }
            else{
                st1.push(value);
            }   
        }
        void dequeue(){
            if(st1.getTopIndex()==-1){
                cout<<"Queue Underflow"<<endl;
            }
            else{
                while(st1.getTopIndex()!=0){
                    st2.push(st1.top());
                    st1.pop();
                }
                st1.pop();
                while(st2.getTopIndex()!=-1){
                    st1.push(st2.top());
                    st2.pop();
                }
            }
        }
        void display(){
            st1.display();
        }
};
int main(){
    queue q;
    q.enqueue(10);
    q.display();
    cout<<endl;
    q.enqueue(20);
    q.display();
    cout<<endl;
    q.enqueue(30);
    q.display();
    cout<<endl;
    q.dequeue();
    q.display();
    cout<<endl;
    return 0;
}