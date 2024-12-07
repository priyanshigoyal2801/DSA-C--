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
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *newHead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
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
    cout << "Original list";
    head->display(head);
    head = head->reverseList(head);
    cout << "Reversed list ";
    head->display(head);
}
