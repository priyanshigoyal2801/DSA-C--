#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(){
        data = 0;
        next = NULL;
    }
    Node(int val){
        data = val;
        next = NULL;
    }
};
class linkedList{
    public:
    Node *head;
    linkedList(){
        head = NULL;
    }

    void addNode(int);
    void display();
    linkedList reverseLinkedList(linkedList);
};

void linkedList :: addNode(int x){
    Node *nNode = new Node(x);
    if(head == NULL){
        head = nNode;
    }
    else{
        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = nNode;
    }
}
void linkedList :: display(){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
linkedList linkedList :: reverseLinkedList(linkedList l){
    Node *temp = l.head , *prev = NULL;
    while(temp != NULL){
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    l.head = prev;
    return l;
}

linkedList findUnion(linkedList l1 , linkedList l2){
    linkedList l3;
    unordered_set<int> set;
    Node *temp1 = l1.head , *temp2 = l2.head;
    while(temp1 != NULL){
        set.insert(temp1->data);
        temp1 = temp1->next;
    }
    while(temp2 != NULL){
        set.insert(temp2->data);
        temp2 = temp2->next;
    }
    for(auto it : set){
        l3.addNode(it);
    }
    l3 = l3.reverseLinkedList(l3);

    return l3;
}
linkedList findIntersection(linkedList l1 , linkedList l2){
    linkedList l3;
    unordered_map<int,int> mpp;
    Node *temp1 = l1.head , *temp2 = l2.head;
    while(temp1 != NULL){
        mpp[temp1->data]++;
        temp1 = temp1->next;
    }
    while(temp2 != NULL){
        if(mpp[temp2->data] > 0){
            l3.addNode(temp2->data);
            mpp[temp2->data]--;
        }
        temp2 = temp2->next;
    }

    return l3;
}

int main(){
    linkedList l1,l2;
    int x , y , i;
    cout<<"Enter how many nodes you want to enter for first node: ";
    cin>>x;
    for(i = 0;i < x;i++){
        int val;
        cout<<"Enter value for "<<i + 1<<" node for first linked list: ";
        cin>>val;
        l1.addNode(val);
    }
    cout<<endl<<"Enter how many nodes you want to enter for second node: ";
    cin>>y;
    for(i = 0;i < y;i++){
        int val;
        cout<<"Enter value for "<<i + 1<<" node for second linked list: ";
        cin>>val;
        l2.addNode(val);
    }

    linkedList l3 , l4;
    l3 = findUnion(l1 , l2);
    l4 = findIntersection(l1 , l2);
    cout<<"Union of two lists are: ";
    l3.display();
    cout<<endl<<"Intersection of two lists are: ";
    l4.display();
}