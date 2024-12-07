//Singly Linked Lists
// #include <iostream>
// using namespace std;
// struct Node{
//     public:
//         int data;
//         Node* next;
//     public:
//         Node(int data1,Node* next1){
//             data=data1;
//             next=next1;
//         }
//         Node(int data1){
//             data=data1;
//             next=nullptr;
//         }
// };
// void traverse(Node* head){
//     Node* temp=head;
//     while(temp){ //untill temp next is nullptr
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }
// }
// bool checkElement(Node* head,int target){
//     Node* temp=head;
//     while(temp){
//         if(temp->data==target){
//             return true;
//         }
//         temp=temp->next;
//     }
//     return false;
// }
// int length(Node* head){
//     int count=0;
//     Node* temp=head;
//     while(temp){
//         count++;
//         temp=temp->next;
//     }
//     return count;
// }
// int main(){
//     int size=5;
//     int arr[size]={10,20,30,40,50};
//     Node* head=new Node(arr[0]);
//     Node* temp=head;
//     for(int i=1;i<size;i++){  //linking the array
//         temp->next=new Node(arr[i]);
//         temp=temp->next;
//     }
//     traverse(head);
//     if(checkElement(head,150)){ //finding element in linked list
//         cout<<"\nElement Found"<<endl;
//     }
//     else{

//         cout<<"\nElement Not Found"<<endl;
//     }
//     cout<<"Length Of Linked List: "<<length(head)<<endl;
//     return 0;
// }

//Delete
// #include <iostream>
// using namespace std;
// struct Node{
//     public:
//         int data;
//         Node* next;
//     public:
//         Node(int data1,Node* next1){
//             data=data1;
//             next=next1;
//         }
//         Node(int data1){
//             data=data1;
//             next=nullptr;
//         }
// };
// Node* deleteStart(Node* head){
//     Node* temp=head;
//     head=head->next;
//     delete temp;
//     return head;
// }
// void deleteEnd(Node* head){
//     if(head==nullptr || head->next==nullptr){
//         return;
//     }
//     else{
//         Node* temp=head;
//         while(temp->next->next!=nullptr){
//             temp=temp->next;
//         }
//         delete temp->next;
//         temp->next=nullptr;
//     }
// }
// Node* deleteAny(Node* head,int pos){
//     if(head==nullptr){
//         return head;
//     }
//     if(pos==1){
//         Node* temp=head;
//         head=head->next;
//         delete temp;
//         return head;
//     }
//     else{
//         int count=0;
//         Node* temp=head;
//         Node* prev=nullptr;
//         while(temp){
//             prev=temp;
//             temp=temp->next;
//             count++;
//             if(pos-1==count){
//                 prev->next=prev->next->next;
//                 delete temp;
//                 return head;
//             }
//         }
//     }
// }
// Node* deleteValue(Node* head,int value){
//     if(head==nullptr){
//         return head;
//     }
//     if(head->data==value){
//         Node* temp=head;
//         head=head->next;
//         delete temp;
//         return head;
//     }
//     else{
//         Node* temp=head;
//         Node* prev=nullptr;
//         while(temp){
//             prev=temp;
//             temp=temp->next;
//             if(temp->data==value){
//                 prev->next=prev->next->next;
//                 delete temp;
//                 return head;
//             }
//         }
//     }
// }
// void display(Node* head){
//     Node* temp=head;
//     while(temp){
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }
// }
// int main(){
//     int size=5;
//     int arr[size]={10,20,30,40,50};
//     Node* head=new Node(arr[0]);
//     Node* temp=head;
//     for(int i=1;i<size;i++){
//         temp->next=new Node(arr[i]);
//         temp=temp->next;
//     }
//     display(head);
//     // head=deleteStart(head);
//     //deleteEnd(head);
//     //head=deleteAny(head,5);
//     head=deleteValue(head,20);
//     cout<<endl;
//     display(head);
//     return 0;
// }

//Insert
// #include <iostream>
// using namespace std;
// struct Node{
//     public:
//         int data;
//         Node* next;
//     public:
//         Node(int data1,Node* next1){
//             data=data1;
//             next=next1;
//         }
//         Node(int data1){
//             data=data1;
//             next=nullptr;
//         }
// };
// void display(Node* head){
//     Node* temp=head;
//     while(temp){
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }
// }
// Node* insertStart(Node* head,int value){
//     Node* temp=new Node(value);
//     temp->next=head;
//     return temp;
// }
// Node* insertEnd(Node* head,int value){
//     if(head==nullptr){
//         return new Node(value);
//     }
//     Node* temp=head;
//     while(temp->next){
//         temp=temp->next;
//     }
//     temp->next=new Node(value);
//     return head;
// }
// Node* insertAny(Node* head,int value,int pos){
//     if(head==nullptr){
//         if(pos==1){
//             return new Node(value);
//         }
//         else{
//             return head;
//         }
//     }
//     if(pos==1){
//         Node* temp=new Node(value,head);
//         return temp;
//     }
//     int count=0;
//     Node* temp=head;
//     while(temp){
//         count++;
//         if((pos-1)==count){
//             Node* x=new Node(value,temp->next);
//             temp->next=x;
//             return head;
//         }
//         temp=temp->next;
//     }
// }
// Node* insertBeforeValue(Node* head,int value,int ValueBefore){
//     if(head==nullptr){
//         return nullptr;
//     }
//     if(head->data==ValueBefore){
//         Node* temp=new Node(value,head);
//         return temp;
//     }
//     Node* temp=head;
//     while(temp->next){
//         if(temp->next->data==ValueBefore){
//             Node* x=new Node(value,temp->next);
//             temp->next=x;
//             return head;
//         }
//         temp=temp->next;
//     }
// }
// int main(){
//     int size=5;
//     int arr[size]={10,20,30,40,50};
//     Node* head=new Node(arr[0]);
//     Node* temp=head;
//     for(int i=1;i<size;i++){
//         temp->next=new Node(arr[i]);
//         temp=temp->next;
//     }
//     display(head);
//     cout<<endl;
//     head=insertBeforeValue(head,5,50);
//     //head=insertAny(head,5,4);
//     //head=insertEnd(head,5);
//     //head=insertStart(head,5);
//     display(head);
//     return 0;
// }

//Delete All Given ELements
// #include <iostream>
// using namespace std;
// struct Node{
//     public:
//         int data;
//         Node* next;
//     public:
//         Node(int data1,Node* next1){
//             data=data1;
//             next=next1;
//         }
//         Node(int data1){
//             data=data1;
//             next=nullptr;
//         }
// };
// void display(Node* head){
//     Node* temp=head;
//     while(temp){ //untill temp next is nullptr
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }
// }
// bool checkElement(Node* head,int target){
//     Node* temp=head;
//     while(temp){
//         if(temp->data==target){
//             return true;
//         }
//         temp=temp->next;
//     }
//     return false;
// }
// Node* removeGiven(Node* head,int key){
//     if(head==nullptr){
//         return head;
//     }
//     if(!checkElement(head,key)){
//         return head;
//     }
//     else{
//         int count=0;
//         Node* temp=head;
//         Node* prev=nullptr;
//         while(temp){
//             if(temp->data==key){
//                 count++;
//                 if(temp==head){
//                     prev=temp;
//                     head=head->next;
//                     temp=temp->next;
//                 }
//                 else{
//                     prev->next=temp->next;
//                     temp=prev->next;
//                     }
//             }
//             else{
//                 prev=temp;
//                 temp=temp->next;
//             }            
//         }
//         return head;
//     }
// }
// int main(){
//     int size=7;
//     int arr[size]={1,2,1,2,1,3,1};
//     Node* head=new Node(arr[0]);
//     Node* temp=head;
//     for(int i=1;i<size;i++){  //linking the array
//         temp->next=new Node(arr[i]);
//         temp=temp->next;
//     }
//     display(head);
//     cout<<endl;
//     head=removeGiven(head,2);
//     display(head);
//     return 0;
// }

//Circular
// #include <iostream>
// using namespace std;
// struct Node{
//     public:
//         int data;
//         Node* next;
//     public:
//         Node(int data1,Node* next1){
//             data=data1;
//             next=next1;
//         }
//         Node(int data1){
//             data=data1;
//             next=nullptr;
//         }
// };
// void display(Node* head){
//     Node* temp=head;
//     do{
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }while(temp!=head);
// }
// bool search(Node* head,int value){
//     Node* temp=head;
//     do{
//         if(temp->data==value){
//             return true;
//         }
//         else{
//             temp=temp->next;
//         }
//     }while(temp!=head);
//     return false;
// }
// Node* insertStart(Node* head,int value){
//     if(head==nullptr){
//         Node*x=new Node(value);
//         x->next=x;
//         return x;
//     }
//     else{
//         Node* last=head;
//         while(last->next!=head){
//             last=last->next;
//         }
//         Node* temp=new Node(value);
//         last->next=temp;
//         temp->next=head;
//         return temp;
//     }
// }
// Node* insertEnd(Node* head,int value){
//     if(head==nullptr){
//         Node*x=new Node(value);
//         x->next=x;
//         return x;
//     }
//     else{
//         Node* last=head;
//         while(last->next!=head){
//             last=last->next;
//         }
//         last->next=new Node(value,head);
//         return head;
//     }
// }
// Node* insertAnywhere(Node* head,int value,int pos){
//     if(head==nullptr){
//         if(pos==1){
//             Node* x=new Node(value);
//             x->next=x;
//             return x;
//         }
//         else{
//             return nullptr;
//         }
//     }
//     if(pos==1){
//         Node* last=head;
//         while(last->next!=head){
//             last=last->next;
//         }
//         Node* temp=new Node(value,head);
//         last->next=temp;
//         return temp;
//     }
//     else{
//         int count=0;
//         Node* temp=head;
//         do{
//             count++;
//             if(pos-1==count){
//                 Node* frontTemp=temp->next;
//                 temp->next=new Node(value,frontTemp);
//             }
//             temp=temp->next;
//         }while(temp!=head);
//         return head;
//     }
// }
// Node* deleteStart(Node* head){
//     if(head==nullptr){
//         return nullptr;
//     }
//     if(head==head->next){
//         return nullptr;
//     }
//     else{
//         Node* temp=head;
//         while(temp->next!=head){
//             temp=temp->next;
//         }
//         head=head->next;
//         temp->next=head;
//         return head;
//     }
// }
// Node* deleteEnd(Node* head){
//     Node* temp=head;
//     while(temp->next->next!=head){
//         temp=temp->next;
//     }
//     temp->next=head;
//     return head;
// }
// Node* deleteAnywhere(Node* head,int pos){
//     if(head==nullptr){
//         return nullptr;
//     }
//     if(head->next==head){
//         return nullptr;
//     }
//     if(pos==1){
//         Node* temp=head;
//         while(temp->next!=head){
//             temp=temp->next;
//         }
//         head=head->next;
//         temp->next=head;
//     }
//     else{
//         Node* temp=head;
//         Node* prev=nullptr;
//         int count=0;
//         while(temp->next!=head){
//             prev=temp;
//             count++;
//             temp=temp->next;
//             if(pos-1==count){
//                 prev->next=prev->next->next;
//             }
//         }
//         return head;
//     }
// }
// int main(){
//     int size=5;
//     int arr[size]={10,20,30,40,50};
//     Node* head=new Node(arr[0]);
//     Node* temp=head;
//     for(int i=1;i<size;i++){
//         temp->next=new Node(arr[i]);
//         temp=temp->next;
//     }
//     temp->next=head;
//     display(head);
//     cout<<endl;
//     // if(search(head,50)){
//     //     cout<<"Element Found"<<endl;
//     // }
//     // else{
//     //     cout<<"Element Not Found"<<endl;
//     // }
//     // head=insertStart(head,5);
//     // head=insertEnd(head,65);
//     // head=insertAnywhere(head,100,2);
//     // head=deleteStart(head);
//     // head=deleteAnywhere(head,4);
//     display(head);
//     return 0;
// }

//Stack Using Linked Lists
// #include <iostream>
// using namespace std;
// struct Node{
//     public:
//         int data;
//         Node* next;
//     public:
//         Node(int data1,Node* next1){
//             data=data1;
//             next=next1;
//         }
//         Node(int data1){
//             data=data1;
//             next=nullptr;
//         }
// };
// class stack{
//     public:
//         Node* head;
//     public:
//         stack(){
//             head=nullptr;
//         }
//         void push(int value){
//             if(head==nullptr){
//                 head=new Node(value);
//             }
//             else{
//                 Node* temp=new Node(value,head);
//                 head=temp;
//             }
//         }
//         void display(){
//             if(head==nullptr){
//                 cout<<"Stack Underflow"<<endl;
//             }
//             else{
//                 Node* temp=head;
//                 while(temp){
//                     cout<<temp->data<<" ";
//                     temp=temp->next;
//                 }
//                 cout<<endl;
//             }
//         }
//         void pop(){
//             if(head==nullptr){
//                 cout<<"Stack Underflow"<<endl;
//             }
//             else{
//                 head=head->next;
//             }
//         }
//         Node* top(){
//             if(head==nullptr){
//                 return nullptr;
//             }
//             else{
//                 return head;
//             }
//         }
// };
// int main(){
//     stack st;
//     st.pop();
//     st.push(10);
//     st.push(20);
//     st.display();
//     cout<<(st.top())->data<<endl;
//     st.pop();
//     st.display();
//     return 0;
// }

