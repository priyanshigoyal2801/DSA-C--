#include <iostream>
using namespace std;

class circularQ
{
private:
    int *arr;
    int size;
    int front;
    int rear;

public:
    circularQ(int size)
    {
        this->size = size;
        front = rear = -1;
        arr = new int[size];
    }
    void enqueue(int a)
    {
        if (rear == -1)
        {
            front = rear = 0;
            arr[rear] = a;
        }
        else if ((rear + 1) % size == front)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            rear = (rear + 1) % size;
            arr[rear] = a;
        }
    }
    int dequeue()
    {
        if (front == -1)
        {
            cout << "Queue is Empty";
        }
        else if (front == rear)
        {
            front = -1;
            return arr[front];
        }
        else
        {
            front = (front + 1) % size;
            return arr[front];
        }
    }
    void display()
    {
        int i = front;
        while (i != rear)
        {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }
        cout << arr[i] << endl;
    }
};
int main()
{
    circularQ cq(5);
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);
    cq.enqueue(5);
    cq.display();
    cq.dequeue();
    cq.enqueue(7);
    cq.display();
    return 0;
}