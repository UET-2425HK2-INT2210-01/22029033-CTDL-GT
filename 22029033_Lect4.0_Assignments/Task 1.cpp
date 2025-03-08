#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node(int val) : value(val), next(nullptr) {}
};

class LinkedList
{
private:
    Node* head;
    vector<string> output;

public:
    LinkedList() : head(nullptr) {}

    void append(int x)
    {
        Node* newNode = new Node(x);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void search(int x)
    {
        Node* temp = head;
        int index = 0;
        while (temp)
        {
            if (temp->value == x)
            {
                output.push_back(to_string(index));
                return;
            }
            temp = temp->next;
            index++;
        }
        output.push_back("NO");
    }

    void reverse()
    {
        Node* prev = nullptr;
        Node* current = head;
        while (current)
        {
            Node* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        head = prev;

        string result = "";
        Node* temp = head;
        while (temp)
        {
            result += to_string(temp->value) + " ";
            temp = temp->next;
        }
        if (!result.empty()) result.pop_back();
        output.push_back(result);
    }

    void printOutput()
    {
        for (const string& line : output)
        {
            cout << line << endl;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    LinkedList linkedList;
    for (int i = 0; i < n; i++)
    {
        string command;
        cin >> command;
        if (command == "append")
        {
            int x;
            cin >> x;
            linkedList.append(x);
        }
        else if (command == "search")
        {
            int x;
            cin >> x;
            linkedList.search(x);
        }
        else if (command == "reverse")
        {
            linkedList.reverse();
        }
    }
    linkedList.printOutput();
    return 0;
}
