// #include <iostream>
// #include <stack>
// using namespace std;
// class ListNode
// {
//     public:
//     int val;
//     ListNode *next;

//     ListNode(int data)
//     {

//         val = data;
//         next = NULL;
//     }
//     ListNode *reverseList(ListNode *head)
//     {
//         if (head == NULL)
//             return NULL;
//         stack<int> st;
//         ListNode *temp = head;
//         while (temp != NULL)
//         {
//             st.push(temp->val);
//             temp = temp->next;
//         }
//         ListNode *temp1 = head;
//         while (!st.empty())
//         {
//             temp1->val = st.top();
//             st.pop();
//             temp1 = temp1->next;
//         }
//         return head;
//     }
//     void display(ListNode *head)
//     {
//         ListNode *temp = head;
//         while (temp != NULL)
//         {
//             cout << temp->val << " ";
//             temp = temp->next;
//         }
//         cout << endl;
//     }
// };
// int main()
// {
//     ListNode *head = new ListNode(1);
//     head->next = new ListNode(2);
//     head->next->next = new ListNode(3);
//     head->next->next->next = new ListNode(4);
//     head->next->next->next->next = new ListNode(5);
//     cout << "Original list ";
//     head->display(head);
//     head = head->reverseList(head);
//     cout << "Reversed list ";
//     head->display(head);

// }

// optimized
#include <iostream>
#include <stack>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int data)
    {

        val = data;
        next = NULL;
    }
    ListNode *reverseList(ListNode *head)
    {
        ListNode *temp = head;
        ListNode *prev = NULL;
        while (temp != NULL)
        {
            ListNode *front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    void display(ListNode *head)
    {
        ListNode *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    cout << "Original list ";
    head->display(head);
    head = head->reverseList(head);
    cout << "Reversed list ";
    head->display(head);
}
