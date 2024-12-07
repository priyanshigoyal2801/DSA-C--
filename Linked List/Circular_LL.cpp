#include<iostream>
using namespace std;
class Node{
     public:
    int data;
    Node * next;
   
    Node(int d)
    {
        data=d;
        next=NULL;
    }
};
void insertNode(Node *&tail,int element, int d){
    if(tail==NULL){
        Node * newNode=new Node(d);
        tail=newNode;
        tail->next=tail;
    }
    else{
        Node *curr=tail;

        while(curr->data!=element){
            curr=curr->next;
        }
        Node *temp=new Node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}
void deleteNode(Node *&tail,int val){
    if(tail==NULL){
        cout<<"list is empty";
    }
    else{
        Node *prev=tail;
        Node *curr=prev->next;
        while(curr->data!=val){
            prev=curr;
            curr=curr->next;
        }
        if(curr==prev){   //single node
            tail=NULL;
        }
        else if(tail==curr){   //to prevent deletion of  main node->tail
            tail=prev;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
void print(Node *tail){
   if(tail==NULL){
        cout<<"list is empty";
    }
    Node*temp=tail;
    
    while(tail->next!=temp){
        cout<<tail->data<<endl;
        tail=tail->next;
    }
     cout<<tail->data<<endl;
}
int main(){
    Node *tail=NULL;
    insertNode(tail,5,3);
    insertNode(tail,3,4);
    insertNode(tail,4,5);
    insertNode(tail,3,6);
    print(tail);
    deleteNode(tail,5);
    deleteNode(tail,3);
    print(tail);
}