GIẢ MÃ:

#define MAX_SIZE 100  
class Stack {
private:
    int arr[MAX_SIZE]; 
    int top;           

public:
    Stack() {
        top = -1;
    }

    bool IsEmpty() {
        return (top == -1);
    }

    bool IsFull() {
        return (top == MAX_SIZE - 1);
    }

    void Push(int x) {
        if (IsFull()) {
            cout << "Stack is Full\n";
            return;
        }
        arr[++top] = x;
    }

    void Pop() {
        if (IsEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }
        top--;
    }

    int Top() {
        if (IsEmpty()) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }
};

ĐỘ PHỨC TẠP:
IsEmpty() -> O(1)
IsFull() -> O(1)
Push() -> O(1)
Pop() -> O(1)
Top() -> O(1)