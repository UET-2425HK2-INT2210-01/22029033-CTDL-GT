GIẢ MÃ:

#define MAX_SIZE 100  
class Queue {
private:
    int arr[MAX_SIZE]; 
    int front, rear;   

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool IsEmpty() {
        return (front == -1 || front > rear);
    }

    bool IsFull() {
        return (rear == MAX_SIZE - 1);
    }

    void Enqueue(int x) {
        if (IsFull()) {
            cout << "Queue is Full\n";
            return;
        }
        if (front == -1) front = 0; 
        rear++;
        arr[rear] = x;
    }

    void Dequeue() {
        if (IsEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        front++; 
    }

    int Front() {
        if (IsEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }
};

ĐỘ PHỨC TẠP:
IsEmpty() -> O(1)
IsFull() -> O(1)
Enqueue() -> O(1)
Dequeue() -> O(1)
Front() -> O(1)
