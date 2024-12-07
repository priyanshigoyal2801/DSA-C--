#include <iostream>
using namespace std;
class Circular
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    Circular(int size)
    {
        this->size = size;
        front = -1;
        rear = -1;
        arr = new int[size];
    }
    void enqueue(int data)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1)))
        {
            cout << "queue is full";
            return;
        }
        else if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else if (rear == (size - 1) && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = data;
    }
    int dequeue()
    {
        if (front == -1)
        {
            cout << "queue is empty";
            return -1;
        }

        int ans = arr[front];

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }

        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }

        return ans;
    }
    void disp()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
        else
        {
            for (int i = front; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};
int main()
{
    Circular CQ(5);
    CQ.enqueue(10);
    CQ.enqueue(20);
    CQ.enqueue(30);
    CQ.enqueue(40);
    CQ.enqueue(50); 
    CQ.dequeue();   
    CQ.enqueue(60); 
    CQ.enqueue(70); 
    CQ.disp();
}