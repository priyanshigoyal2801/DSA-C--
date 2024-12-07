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
        if (front == (rear + 1) % size) //rear is just before front
        {
            cout << "queue is full";
        }
        else if (front == -1)
        {
            front = 0;
            rear = (rear + 1) % size;
            arr[rear] = data;
        }
        else
        {
            rear = (rear + 1) % size;
            arr[rear] = data;
        }
    }
    int dequeue()
    {
        if (front == -1)
        {
            cout << "queue is empty";
            return -1;
        }
        else if (front == rear)
        {
            front = -1;
            rear = -1;
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
            cout << arr[i] << endl;
            i = (i + 1) % size;
        }
        cout << arr[i];
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
    CQ.display();
}