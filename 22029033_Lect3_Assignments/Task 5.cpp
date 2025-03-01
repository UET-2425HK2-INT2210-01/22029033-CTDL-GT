#include <iostream>
using namespace std;
class Stack
{
private:
    int *stack, top, capacity;
public:
    Stack(int size)
    {
        capacity = size;
        stack = new int[size];
        top = -1;
    }
    void push(int item)
    {
        if (top == capacity - 1)
        {
            return;
        }
        stack[++top] = item;
    }
    void pop()
    {
        if (top == -1)
        {
            return;
        }
        top--;
    }
    int peek()
    {
        return (top != -1) ? stack[top] : -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }
    ~Stack()
    {
        delete[] stack;
    }
};
int main()
{
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;
    return 0;
}
