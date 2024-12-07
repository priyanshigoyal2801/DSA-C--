#include <iostream>
using namespace std;
class Queue
{
public:
    int *arr;
    int size;
    int front;
    int rear;
    Queue(int size)
    {
        this->size = size;
        front = 0;
        rear = 0;
        arr = new int[size];
    }
    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        else
            return false;
    }
    void enqueue(int element)
    {
        if (rear == size - 1)
        {
            cout << "queue is full";
        }
        else
        {
            arr[rear] = element;
            rear++;
        }
    }
    int dequeue()
    {
        if (front == -1)
            return -1;
        else
        {
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
            if (front ==0){
                front = -1;
            }
            return ans;
        }
    }
    int qfront()
    {
        if (front == -1)
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }
    void print()
    {
        if (front == -1)
            cout << "queue is empty";
        else
        {
            for (int i = front; i < rear; i++)
            {
                cout << arr[i]<<" ";
            }
        }
        cout << endl;
    }
};
int main()
{
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    //  q.enqueue(3);
    // q.enqueue(4);
    cout<<q.qfront();
    cout<<endl;
    q.print();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.print();
}