#include <iostream>
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
void insertAtHead(Node *&head, int c)
{
    Node *temp = new Node(c);
    temp->next = head;
    head = temp;
}
void insertAtTail(Node *&tail, int c)
{
    Node *temp = new Node(c);
    tail->next = temp;
    tail = temp;
}
void insertAtMiddle(Node *&head, int position, int d, Node *&tail)
{
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
    Node *NodeToInsert = new Node(d);
    NodeToInsert->next = temp->next;
    temp->next = NodeToInsert;
}

void deleteNode(Node *&head, int pos)
{
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
void deleteByVal(Node *&head, int val)
{
    if (head == NULL)
    {
        cout << "empty list";
    }
    if (head->data == val)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *prev = NULL;
        Node *temp = head;
        while (temp != NULL)
        {
            prev = temp;
            temp = temp->next;
            if (temp->data == val)
            {
                prev->next = temp->next;
                temp->next = NULL;
                delete temp;
            }
        }
    }
}
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    insertAtHead(head, 20);
    insertAtHead(head, 20);
    insertAtMiddle(head, 3, 60, tail);
    insertAtTail(tail, 30);
    insertAtMiddle(head, 4, 99, tail);
    deleteNode(head, 2);
    deleteByVal(head, 99);
    deleteNode(head, 3);
    insertAtHead(head, 55);
    print(head);
}

