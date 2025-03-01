#include <iostream>
using namespace std;

class Queue
{
private:
    int *queue;
    int front, rear, capacity;
public:
    Queue(int size)
    {
        capacity = size;
        queue = new int[capacity];
        front = rear = -1;
    }
    void enqueue(int item)
    {
        if (rear == capacity - 1)
        {
            return;
        }
        if (front == -1)
        {
            front = 0;
        }
        queue[++rear] = item;
    }
    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            return;
        }
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
    }
    int peek()
    {
        if (front == -1 || front > rear)
        {
            return -1;
        }
        return queue[front];
    }
    bool isEmpty()
    {
        return (front == -1 || front > rear);
    }
    Queue()
    {
        delete[] queue;
    }
};

int main()
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    return 0;
}
