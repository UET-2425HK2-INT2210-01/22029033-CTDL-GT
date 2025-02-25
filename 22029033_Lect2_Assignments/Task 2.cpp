#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node(int data)
        {
            this->data = data;
            this->next = nullptr;
        }
};

class LinkedList
{
    private:
        Node* head;
    public:
        LinkedList()
        {
            head = nullptr;
        }

    void insert(int p, int x)
    {
        Node* new_node = new Node(x);
        if (p == 0)
        {
            new_node->next = head;
            head = new_node;
            return;
        }
        Node* current = head;
        for (int i = 0; i < p - 1; i++)
        {
            if (current == nullptr)
            {
                break;
            }
            current = current->next;
        }

        if (current != nullptr)
        {
            new_node->next = current->next;
            current->next = new_node;
        }
    }

    void delete_node(int p)
    {
        if (head == nullptr)
        {
            return;
        }
        if (p == 0)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        for (int i = 0; i < p - 1; i++)
        {
            if (current == nullptr)
            {
                return;
            }
            current = current->next;
        }
        if (current != nullptr && current->next != nullptr)
        {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }
    void print_list()
    {
        Node* current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList linked_list;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string operation;
        cin >> operation;
        if (operation == "insert")
        {
            int p, x;
            cin >> p >> x;
            linked_list.insert(p, x);
        }
        else if (operation == "delete")
        {
            int p;
            cin >> p;
            linked_list.delete_node(p);
        }
    }
    linked_list.print_list();
    return 0;
}
