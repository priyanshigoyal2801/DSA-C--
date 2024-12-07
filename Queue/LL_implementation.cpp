#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
class Queue
{
    Node *start;
    Node *end;
    static int cnt;

public:
    Queue()
    {
        start = NULL;
        end = NULL;
    }
    void enqueue(int x)
    {
        Node *temp = new Node(x);
        if (start == NULL)
        {
            start = end = temp;
        }
        else
        {
            end->next = temp;
            end = temp;
        }
        cnt++;
    }
    void dequeue()
    {
        if (start == NULL)
        {
            cout << "queue is empty";
        }
        Node *temp = start;
        start = start->next;
        temp->next = NULL;
        delete temp;
        cnt--;
    }
    void peek()
    {
        cout << start->data << endl;
    }
    void display()
    {
        Node *temp = start;
        if(start==NULL){
            cout<<"queue is empty";
        }
        else{

        
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    }
    static void size()
    {
        cout << cnt << endl;
    }
};
int Queue::cnt;
int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();
   
}