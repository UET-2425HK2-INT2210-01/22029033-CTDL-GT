#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};
class Queue
{
private:
    Node* front;
    Node* rear;
public:
    Queue()
    {
        front = rear = nullptr;
    }
    void enqueue(int item)
    {
        Node* newNode = new Node(item);
        if (rear == nullptr)
        {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }
    void dequeue()
    {
        if (front == nullptr)
        {
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr)
            rear = nullptr;
    }
    int peek()
    {
        if (front == nullptr)
        {
            return -1;
        }
        return front->data;
    }
    bool isEmpty() {
        return (front == nullptr);
    }
    ~Queue()
    {
        while (front != nullptr)
        {
            dequeue();
        }
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    q.dequeue();
    return 0;
}
