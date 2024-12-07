#include <iostream>
using namespace std;
class Node
{
  int data;
  Node *next;
  static int cnt;

public:
  Node(int data)
  {
    this->data = data;
    next = NULL;
    cnt++;
  }
  void push(int x, Node *&top)
  {
    Node *temp = new Node(x);
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
  void topp(Node *&top)
  {
    cout << top->data << endl;
  }
  void display(Node *top)
  {
    Node *temp = top;
    while (temp != NULL)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
  static void size(){
cout<<cnt<<endl;
  }
};
int Node::cnt;
int main()
{
  Node *top = new Node(1);
  top->push(2, top);
  top->push(3, top);
  top->push(4, top);
  top->display(top);
  top->pop(top);
  top->topp(top);
  top->display(top);
  top->size();
  top->pop(top);
  top->size();
}