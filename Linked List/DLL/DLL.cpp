#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};
Node* convertArrToDLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *back = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        temp->prev = back;
        back->next = temp;
        back = temp;
    }
    return head;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *DeleteHead(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete temp;
    return head;
}
Node *DeleteTail(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *back = temp->prev;
    temp->prev = NULL;
    back->next = NULL;
    delete temp;
    return head;
}
Node *removeKthElement(Node *head, int k)
{
    Node *temp = head;
    if (head == NULL)
        return NULL;
    int cnt = 0;
    while (temp->next != NULL)
    {
        cnt++;
        if (cnt == k)
            break;
        temp = temp->next;
    }
    Node *back = temp->prev;
    Node *front = temp->next;
    if (back == NULL && front == NULL)
    {
        return NULL;
    }
    else if (back == NULL)
    {
        return DeleteHead(head);
    }
    else if (front == NULL)
    {
        return DeleteTail(head);
    }

    back->next = front;
    front->prev = back;
    temp->next = NULL;
    temp->prev = NULL;
    delete temp;
    return head;
}
void deleteNode(Node* head){
    Node* back=head->prev;
    Node* front = head->next;
    if(front==NULL){
        back->next=nullptr;
        head->prev=nullptr;
       free(head);
        return;
    }
    back->next=front;
    front->prev=back;
    head->prev=head->next=nullptr;
    free(head);
}
Node* insertBeforeHead(Node* head,int data){
    Node* newNode = new Node(data);
    newNode->prev=NULL;
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
    return head;
}
Node* insertBeforeTail(Node* head, int data){
    if(head==NULL)
    {
        return insertBeforeHead(head,data);
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* back=temp->prev;
    Node* newNode= new Node(data);
    newNode->next=temp;
    newNode->prev=back;
    back->next=newNode;
    temp->prev=newNode;
    return head;
    
}
Node* insertBeforeKthElement(Node* head, int k, int data){
    if(k==1){
        return insertBeforeHead(head,data);
    }
    Node* temp=head;
    int cnt=0;
    while(temp->next!=NULL){
cnt++;
if(cnt==k)break;
temp=temp->next;
    }
    Node* back=temp->prev;
    Node* newNode= new Node(data);
    back->next=newNode;
    temp->prev=newNode;
    newNode->prev=back;
    newNode->next=temp;
    return head;
}
void insertBeforeNode(Node* head, int data){
    Node* back=head->prev;
    Node* newNode= new Node(data);
    newNode->next=head;
    newNode->prev=back;
    head->prev=newNode;
    back->next=newNode;
    
}
int main()
{
    vector<int> arr = {12, 5, 8, 7};
    Node *head = convertArrToDLL(arr);
    print(head);
    // deleteNode(head->next->next);
    Node* head1=insertBeforeKthElement(head,3,90);
    insertBeforeNode(head->next->next,99);
    // Node *head2 = removeKthElement(head, 2);
    print(head1);
}