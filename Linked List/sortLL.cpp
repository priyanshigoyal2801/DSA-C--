
// #include <iostream>

// using namespace std;

// class Node
// {
// public:
//     int data;

//     Node *next;

//     Node(int data1, Node *next1)
//     {
//         data = data1;
//         next = next1;
//     }

//     Node(int data1)
//     {
//         data = data1;
//         next = nullptr;
//     }
// };

// // Function to merge two sorted linked lists
// Node *mergeTwoSortedLinkedLists(Node *list1, Node *list2)
// {
//     // Create a dummy node to serve
//     // as the head of the merged list
//     Node *dummyNode = new Node(-1);
//     Node *temp = dummyNode;

//     while (list1 != nullptr && list2 != nullptr)
//     {
//         // Compare elements of both lists and
//         // link the smaller node to the merged list
//         if (list1->data <= list2->data)
//         {
//             temp->next = list1;
//             list1 = list1->next;
//         }
//         else
//         {
//             temp->next = list2;
//             list2 = list2->next;
//         }
//         // Move the temporary pointer
//         // to the next node
//         temp = temp->next;
//     }

//     // If any list still has remaining
//     // elements, append them to the merged list
//     if (list1 != nullptr)
//     {
//         temp->next = list1;
//     }
//     else
//     {
//         temp->next = list2;
//     }
//     // Return the merged list starting
//     // from the next of the dummy node
//     return dummyNode->next;
// }

// // Function to find the middle of a linked list
// Node *findMiddle(Node *head)
// {
//     // If the list is empty or has only one node
//     // the middle is the head itself
//     if (head == nullptr || head->next == nullptr)
//     {
//         return head;
//     }

//     // Initializing slow and fast pointers
//     Node *slow = head;
//     Node *fast = head->next;

//     // Move the fast pointer twice as fast as the slow pointer
//     // When the fast pointer reaches the end, the slow pointer
//     // will be at the middle
//     while (fast != nullptr && fast->next != nullptr)
//     {
//         slow = slow->next;
//         fast = fast->next->next;
//     }

//     return slow;
// }

// // Function to perform merge sort on a linked list
// Node *sortLL(Node *head)
// {
//     // Base case: if the list is empty or has only one node
//     // it is already sorted, so return the head
//     if (head == nullptr || head->next == nullptr)
//     {
//         return head;
//     }

//     // Find the middle of the list using the findMiddle function
//     Node *middle = findMiddle(head);

//     // Divide the list into two halves
//     Node *right = middle->next;
//     middle->next = nullptr;
//     Node *left = head;

//     // Recursively sort the left and right halves
//     left = sortLL(left);
//     right = sortLL(right);

//     // Merge the sorted halves using the mergeTwoSortedLinkedLists function
//     return mergeTwoSortedLinkedLists(left, right);
// }

// // Function to print the linked list
// void printLinkedList(Node *head)
// {
//     Node *temp = head;
//     while (temp != nullptr)
//     {

//         cout << temp->data << " ";

//         temp = temp->next;
//     }
//     cout << endl;
// }

// int main()
// {

//     Node *head = new Node(3);
//     head->next = new Node(2);
//     head->next->next = new Node(5);
//     head->next->next->next = new Node(4);
//     head->next->next->next->next = new Node(1);

//     cout << "Original Linked List: ";
//     printLinkedList(head);

//     head = sortLL(head);

//     cout << "Sorted Linked List: ";
//     printLinkedList(head);

//     return 0;
// }



//bubble sort
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to swap data of two nodes
void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Function to perform Bubble Sort on the linked list
void bubbleSort(Node* head) {
    if (head == nullptr) return;

    bool swapped = true; // Start with swapped true
    while (swapped) {
        swapped = false; // Reset swapped for this pass
        Node* current = head;

        while (current->next != nullptr) {
            if (current->data > current->next->data) {
                swap(current, current->next);
                swapped = true; // A swap occurred
            }
            current = current->next;
        }
    }
}

// Helper function to insert a new node at the end of the list
Node* insert(Node* head, int data) {
    if (head == nullptr) return new Node(data);
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new Node(data);
    return head;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Inserting elements into the linked list
    head = insert(head, 5);
    head = insert(head, 10);
    head = insert(head, 3);
    head = insert(head, 1);
    head = insert(head, 7);

    cout << "Original List: ";
    printList(head);

    // Sorting the linked list using bubble sort
    bubbleSort(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}

