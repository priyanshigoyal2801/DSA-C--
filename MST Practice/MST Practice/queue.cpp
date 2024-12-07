//Simple Queue
// #include <iostream>
// using namespace std;
// #define max_size 5
// class queues{
//     private:
//         int queue[max_size];
//         int front=-1;
//         int rear=-1;
//     public:
//         void enqueue(int element){
//             if(rear>=max_size-1){
//                 cout<<"Queue Overflow"<<endl;
//             }
//             else{
//                 if(front==-1 && rear==-1){
//                     front=0;
//                     rear=0;
//                     queue[rear]=element;
//                 }
//                 else{
//                     rear++;
//                     queue[rear]=element;
//                 }
//             }
//         }
//         void dequeue(){
//             if(front==-1||front>rear){
//                 cout<<"Queue Underflow"<<endl;
//             }
//             else{
//                 cout<<"Element Dequeued is: "<<queue[front]<<endl;
//                 front++;
//             }
//         }
//         void display(){
//             if(front==-1||front>rear){
//                 cout<<"Queue Underflow"<<endl;
//             }
//             else{
//                 for(int i=front;i<=rear;i++){
//                     cout<<queue[i]<<" ";
//                 }
//                 cout<<endl;
//             }
//         }
//         bool isEmpty(){
//             return front==-1||front>rear;
//         }
//         bool isFull(){
//             return rear>=max_size-1;
//         }
//         int peek(){
//             if(front==-1||front>rear){
//                 return -1;
//             }
//             else{
//                 return queue[front];
//             }
//         }
// };
// int main(){
//     queues q;
//     return 0;
// }

//Circular Queue
// #include <iostream>
// using namespace std;
// #define max_size 5
// class queues{
//     private:
//         int queue[max_size];
//         int front=-1;
//         int rear=-1;
//     public:
//         void enqueue(int element){
//             if(front==(rear+1)%max_size){
//                 cout<<"Queue Overflow"<<endl;
//             }
//             else{
//                 if(front==-1){
//                     front=0;
//                 }
//                 rear=(rear+1)%max_size;
//                 queue[rear]=element;
//                 cout<<"Enqueued: "<<element<<endl;
//             }
//         }
//         void dequeue(){
//             if(front==-1){
//                 cout<<"Queue Underflow"<<endl;
//             }
//             else{
//                 cout<<"Element Dequeued is: "<<queue[front]<<endl;
//                 if(front==rear){
//                     front=-1;
//                     rear=-1;
//                 }
//                 else{
//                     front=(front+1)%max_size;
//                 }
//             }
//         }
//         void display(){
//             if(front==-1){
//                 cout<<"Queue Underflow"<<endl;
//             }
//             else{
//                 cout<<"Queue elements: ";
//                 int i=front;
//                 while(i!=rear){
//                     cout<<queue[i]<<" ";
//                     i=(i+1)%max_size;
//                 }
//                 cout<<queue[rear]<<endl;
//             }
//         }
//         bool isEmpty(){
//             return front==-1;
//         }
//         bool isFull(){
//             return front==(rear+1)%max_size;
//         }
//         int peek(){
//             if(front==-1){
//                 return -1;
//             }
//             else{
//                 return queue[front];
//             }
//         }
// };
// int main(){
//     queues q;
//     q.enqueue(10);
//     q.enqueue(20);
//     q.enqueue(30);
//     q.enqueue(40);
//     q.enqueue(50);
//     q.dequeue();
//     q.dequeue();
//     q.enqueue(60); // Should wrap around
//     q.enqueue(70); // Should wrap around
//     cout << "Front element: "<<q.peek()<<endl;
//     q.display();
//     return 0;
// }

//Alternate
// #include <iostream>
// using namespace std;
// #define max_size 10
// class queues{
//     private:
//         int queue[max_size];
//         int front=-1;
//         int rear=-1;
//     public:
//         void enqueue(int element){
//             if(rear>=max_size-1){
//                 cout<<"Queue Overflow"<<endl;
//             }
//             else{
//                 if(front==-1 && rear==-1){
//                     front=0;
//                     rear=0;
//                     queue[rear]=element;
//                 }
//                 else{
//                     rear++;
//                     queue[rear]=element;
//                 }
//             }
//         }
//         void dequeue(){
//             if(front==-1||front>rear){
//                 cout<<"Queue Underflow"<<endl;
//             }
//             else{
//                 cout<<"Element Dequeued is: "<<queue[front]<<endl;
//                 front++;
//             }
//         }
//         void display(){
//             if(front==-1||front>rear){
//                 cout<<"Queue Underflow"<<endl;
//             }
//             else{
//                 for(int i=front;i<=rear;i++){
//                     cout<<queue[i]<<" ";
//                 }
//                 cout<<endl;
//             }
//         }
//         bool isEmpty(){
//             return front==-1||front>rear;
//         }
//         bool isFull(){
//             return rear>=max_size-1;
//         }
//         int peek(){
//             if(front==-1||front>rear){
//                 return -1;
//             }
//             else{
//                 return queue[front];
//             }
//         }
//         int size(){
//             int count=0;
//             if(front==-1||front>rear){
//                 return 0;
//             }
//             else if(rear==max_size-1){
//                 return max_size;
//             }
//             else{
//                 for(int i=front;i<=rear;i++){
//                     count++;
//                 }
//                 return count;
//             }
//         }
//         int getFront(){
//             return front;
//         }
//         int getRear(){
//             return rear;
//         }
//         void reset(){
//             front=-1;
//             rear=-1;
//         }
// };
// int main(){
//     queues og,first,second;
//     og.enqueue(4);
//     og.enqueue(7);
//     og.enqueue(11);
//     og.enqueue(20);
//     og.enqueue(5);
//     og.enqueue(9);
//     while(!og.isEmpty()){
//         if(og.getFront()<og.size()/2+1){
//             first.enqueue(og.peek());
//             og.dequeue();
//         }
//         else{
//             second.enqueue(og.peek());
//             og.dequeue();
//         }
//     }
//     og.reset();
//     bool firstTurn=true;
//     while(!first.isEmpty() || !second.isEmpty()){
//         if(firstTurn){
//             og.enqueue(first.peek());
//             first.dequeue();
//             firstTurn=false;
//         }
//         else{
//             og.enqueue(second.peek());
//             second.dequeue();
//             firstTurn=true;
//         }
//     }
//     og.display();
//     return 0;
// }

//Stack Using Two Queues
// #include <iostream>
// using namespace std;
// #define max_size 10
// class queues{
//     private:
//         int queue[max_size];
//         int front=-1;
//         int rear=-1;
//     public:
//         void enqueue(int element){
//             if(rear>=max_size-1){
//                 cout<<"Queue Overflow"<<endl;
//             }
//             else{
//                 if(front==-1 && rear==-1){
//                     front=0;
//                     rear=0;
//                     queue[rear]=element;
//                 }
//                 else{
//                     rear++;
//                     queue[rear]=element;
//                 }
//             }
//         }
//         void dequeue(){
//             if(front==-1||front>rear){
//                 cout<<"Queue Underflow"<<endl;
//             }
//             else{
//                 cout<<"Element Dequeued is: "<<queue[front]<<endl;
//                 front++;
//             }
//         }
//         void display(){
//             if(front==-1||front>rear){
//                 cout<<"Queue Underflow"<<endl;
//             }
//             else{
//                 for(int i=front;i<=rear;i++){
//                     cout<<queue[i]<<" ";
//                 }
//                 cout<<endl;
//             }
//         }
//         bool isEmpty(){
//             return front==-1||front>rear;
//         }
//         bool isFull(){
//             return rear>=max_size-1;
//         }
//         int peek(){
//             if(front==-1||front>rear){
//                 return -1;
//             }
//             else{
//                 return queue[front];
//             }
//         }
//         int getFront(){
//             return front;
//         }
//         int getRear(){
//             return rear;
//         }
// };
// class stacks{
//     private:
//         queues q1,q2;
//     public:
//         void push(int element){
//             q2.enqueue(element);
//             while(!q1.isEmpty()){
//                 q2.enqueue(q1.peek());
//                 q1.dequeue();
//             }
//             swap(q1,q2);
//         }
//         void pop(){
//             q1.dequeue();
//         }
//         void display(){
//             if(q1.isEmpty()){
//                 cout<<"Stack is empty"<<endl;
//             }
//             cout<<"Stack elements: ";
//             q1.display();
//         }
//         bool isEmpty(){
//             return q1.isEmpty();
//         }
//         bool isFull(){
//             return q1.isFull();
//         }
// };
// int main(){
//     stacks st;
//     st.push(20);
//     st.push(10);
//     st.pop();
//     st.push(15);
//     st.push(30);
//     st.display();
//     return 0;
// }

//Stack Using One Queue
// #include <iostream>
// using namespace std;
// #define max_size 4
// class queues{
//     private:
//         int queue[max_size];
//         int front=-1;
//         int rear=-1;
//     public:
//         void enqueue(int element){
//             if(rear>=max_size-1){
//                 cout<<"Queue Overflow"<<endl;
//             }
//             else{
//                 if(front==-1 && rear==-1){
//                     front=0;
//                     rear=0;
//                     queue[rear]=element;
//                 }
//                 else{
//                     rear++;
//                     queue[rear]=element;
//                 }
//             }
//         }
//         void dequeue(){
//             if(front==-1||front>rear){
//                 cout<<"Queue Underflow"<<endl;
//             }
//             else{
//                 cout<<"Element Dequeued is: "<<queue[front]<<endl;
//                 front++;
//             }
//         }
//         void display(){
//             if(front==-1||front>rear){
//                 cout<<"Queue Underflow"<<endl;
//             }
//             else{
//                 for(int i=front;i<=rear;i++){
//                     cout<<queue[i]<<" ";
//                 }
//                 cout<<endl;
//             }
//         }
//         bool isEmpty(){
//             return front==-1||front>rear;
//         }
//         bool isFull(){
//             return rear>=max_size-1;
//         }
//         int peek(){
//             if(front==-1||front>rear){
//                 return -1;
//             }
//             else{
//                 return queue[front];
//             }
//         }
//         void shiftLeft(int element){
//             for(int i=rear+1;i>front;i--){
//                 queue[i]=queue[i-1];
//             }
//             queue[0]=element;
//             rear++;
//         }
// };
// class stacks{
//     private:
//         queues q;
//     public:
//         void push(int element){
//             if(q.isEmpty()){
//                 q.enqueue(element);
//             }
//             else{
//                 if(q.isFull()){
//                     cout<<"Stack Overflow"<<endl;
//                 }
//                 else{
//                     q.shiftLeft(element);
//                 }
//             }
//         }
//         void pop(){
//             cout<<"Element Popped: "<<q.peek()<<endl;
//             q.dequeue();
//         }
//         void display(){
//             if(q.isEmpty()){
//                 cout<<"Stack Underflow"<<endl;
//             }
//             else{
//                 cout<<"Stack Elements: ";
//                 q.display();
//             }
//         }
//         int top(){
//             if(q.isEmpty()){
//                 cout<<"Stack Underflow"<<endl;
//                 return -1;
//             }
//             else{
//                 return q.peek();
//             }
//         }
// };
// int main(){
//     stacks st;
//     st.push(5);
//     st.display();
//     st.push(10);
//     st.display();
//     st.push(15);
//     st.display();
//     st.push(20);
//     st.display();
//     st.push(25);
//     st.pop();
//     st.display();
//     cout<<st.top();
//     return 0;
// }

//Enqueue Front and Dequeue Rear
// #include <iostream>
// using namespace std;
// #define max_size 5
// class queues{
//     private:
//         int queue[max_size];
//         int front=-1;
//         int rear=-1;
//     public:
//         void enqueue(int element){
//             if(rear>=max_size-1){
//                 cout<<"Queue Overflow"<<endl;
//             }
//             else{
//                 if(front==-1 && rear==-1){
//                     front=0;
//                     rear=0;
//                     queue[rear]=element;
//                 }
//                 else{
//                     rear++;
//                     queue[rear]=element;
//                 }
//             }
//         }
//         void dequeue(){
//             if(front==-1||front>rear){
//                 cout<<"Queue Underflow"<<endl;
//             }
//             else{
//                 cout<<"Element Dequeued is: "<<queue[front]<<endl;
//                 front++;
//             }
//         }
//         void display(){
//             if(front==-1||front>rear){
//                 cout<<"Queue Underflow"<<endl;
//             }
//             else{
//                 for(int i=front;i<=rear;i++){
//                     cout<<queue[i]<<" ";
//                 }
//                 cout<<endl;
//             }
//         }
//         bool isEmpty(){
//             return front==-1||front>rear;
//         }
//         bool isFull(){
//             return rear>=max_size-1;
//         }
//         int peek(){
//             if(front==-1||front>rear){
//                 return -1;
//             }
//             else{
//                 return queue[front];
//             }
//         }
//         void enqueueFront(int element){
//             if(isFull()){
//                 cout<<"Queue Overflow"<<endl;
//             }
//             else{
//                 for(int i=rear+1;i>front;i--){
//                     queue[i]=queue[i-1];
//                 }
//                 rear++;
//                 queue[front]=element;
//             }
//         }
//         void dequeueRear(){
//             if(isEmpty()){
//                 cout<<"Queue Underflow"<<endl;
//             }
//             else{
//                  rear--;
//             }
//         }
// };
// int main(){
//     queues q;
//     q.enqueue(10);
//     q.enqueue(20);
//     q.display();
//     q.enqueueFront(30);
//     q.display();
//     q.dequeue();
//     q.display();
//     q.dequeue();
//     q.display();
//     q.enqueueFront(99);
//     q.display();
//     q.enqueue(100);
//     q.display();
//     q.dequeueRear();
//     q.display();
//     q.enqueue(200);
//     q.display();
//     return 0;
// }

