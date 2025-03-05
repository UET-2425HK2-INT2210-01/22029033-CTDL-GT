GIẢ MÃ:

struct Node {
    int data;
    Node* next;
};
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    bool IsEmpty() {
        return (top == nullptr);
    }

    void Push(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }

    void Pop() {
        if (IsEmpty()) return;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int Top() {
        if (IsEmpty()) return -1;
        return top->data;
    }
};

ĐỘ PHỨC TẠP:
IsEmpty() -> O(1)
Push() -> O(1)
Pop() -> O(1)
Top() -> O(1)