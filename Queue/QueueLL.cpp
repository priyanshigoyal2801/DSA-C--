#include <iostream>
// #include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
class Queue
{
    public:
    Node *start;
    Node *end;
    static int cnt;


    Queue()
    {
        start = NULL; // Initialize start and end to NULL
        end = NULL;
    }
    void push(int x)
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
    void pop()
    {
        Node *temp = start;
        start = start->next;
        temp->next = NULL;
        delete temp;
        cnt--;
    }
     void display()
    {
        Node *current = start;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    void top()
    {
        cout << start->data << endl;
    }
    static void size(){
        cout << cnt << endl;
    }
};
int Queue::cnt;
int main()
{
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.display();
    q.pop();
    q.display();
    q.top();
    q.size();
    return 0;
}