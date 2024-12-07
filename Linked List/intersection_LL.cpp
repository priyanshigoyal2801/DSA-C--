#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int new_data)
    {
        data = new_data;
        next = NULL;
    }
};

// Function to get the intersection point of two linked lists
Node *getIntersectionNode(Node *head1, Node *head2)
{
    unordered_set<Node *> visitedNodes;

    // Traverse the first list and store all nodes in a set
    Node *curr1 = head1;
    while (curr1 != NULL)
    {
        visitedNodes.insert(curr1);
        curr1 = curr1->next;
    }

    // Traverse the second list and check if any node is in the set
    Node *curr2 = head2;
    while (curr2 != NULL)
    {
        if (visitedNodes.find(curr2) != visitedNodes.end())
        {

            // Intersection point found
            return curr2;
        }
        curr2 = curr2->next;
    }

    return NULL;
}

int main()
{

    Node *head1 = new Node(10);
    head1->next = new Node(15);
    head1->next->next = new Node(30);

    Node *head2 = new Node(3);
    head2->next = new Node(6);
    head2->next->next = new Node(9);
    head2->next->next->next = head1->next;

    Node *intersectionPoint = getIntersectionNode(head1, head2);

    if (intersectionPoint == NULL)
        cout << " No Intersection Point \n";
    else
        cout << "Intersection Point: " << intersectionPoint->data << endl;

    return 0;
}