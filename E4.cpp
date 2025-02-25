#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr){}
};

class Queue
{
    Node *head = nullptr, *tail = nullptr;
    public:
    void enqueue(int x)
    {
        Node* newNode = new Node(x);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void dequeue()
    {
        if (head)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (!head)
            {
                tail = nullptr;
            }
        }
    }
    void print()
    {
        for (Node* curr = head; curr; curr = curr->next)
        {
            cout << curr->data << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue queue;
    int n, x;
    string op;
    cin >> n;
    while (n--)
    {
        cin >> op;
        if (op == "enqueue")
        {
            cin >> x;
            queue.enqueue(x);
        }
        else
        {
            queue.dequeue();
        }
    }
    queue.print();
    return 0;
}
