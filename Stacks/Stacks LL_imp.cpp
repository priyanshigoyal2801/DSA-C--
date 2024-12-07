#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    static int cnt;
    Node *next;
    Node(int data)
    {
        cnt++;
        this->data = data;
        next = NULL;
    }
    void push(Node *&top, int d)
    {
        Node *temp = new Node(d);
        temp->next = top;
        top = temp;
    }
    void pop(Node *&top)
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            Node *temp = top;
            top = top->next;
            temp->next = NULL;
            delete temp;
            cnt--;
        }
        
    }
    void disp(Node *top)
    {
        while (top != NULL)
        {
            cout << top->data << " ";
            top = top->next;
        }
        cout << endl;
    }
    static void size(){
        cout << cnt << endl;
    }
};
int Node :: cnt=0;
int main()
{
    Node *top = new Node(4);
    top->push(top, 5);
    top->push(top, 6);
    top->push(top, 7);
    top->push(top, 8);
    top->push(top, 9);
    top->pop(top);
    top->pop(top);
    top->pop(top);
    top->pop(top);
   
    top->pop(top);

    top->disp(top);
    Node :: size();
    return 0;
}