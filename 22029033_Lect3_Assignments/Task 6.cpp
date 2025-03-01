#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};
class Stack
{
private:
    Node* top;
public:
    Stack() : top(nullptr) {}
    void push(int item)
    {
        Node* newNode = new Node(item);
        newNode->next = top;
        top = newNode;
    }
    void pop()
    {
        if (!top)
        {
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    int peek()
    {
        return top ? top->data : -1;
    }
    bool isEmpty()
    {
        return top == nullptr;
    }
    ~Stack()
    {
        while (top) pop();
    }
};
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;
    return 0;
}
