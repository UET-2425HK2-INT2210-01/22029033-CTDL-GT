GIẢ MÃ:

struct Node {
    int data;
    Node* next;
};
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool IsEmpty() {
        return (front == nullptr);
    }

    void Enqueue(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = nullptr;
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void Dequeue() {
        if (IsEmpty()) {
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    int Front() {
        if (IsEmpty()) {
            return -1;
        }
        return front->data;
    }
};

ĐỘ PHỨC TẠP:
IsEmpty() -> O(1)
Enqueue() -> O(1)
Dequeue() -> O(1)
Front() -> O(1)