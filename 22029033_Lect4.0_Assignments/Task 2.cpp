#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Element
{
    int value;
    int priority;
    Element(int v, int p) : value(v), priority(p) {}

    bool operator<(const Element& other) const
    {
        return priority < other.priority;
    }
};

class PriorityQueue
{
private:
    priority_queue<Element> pq;

public:
    void enqueue(int x, int p)
    {
        pq.push(Element(x, p));
    }

    void dequeue()
    {
        if (!pq.empty())
        {
            pq.pop();
        }
    }

    void printQueue()
    {
        priority_queue<Element> temp = pq;
        vector<pair<int, int>> result;
        while (!temp.empty())
        {
            result.push_back({temp.top().value, temp.top().priority});
            temp.pop();
        }
        for (size_t i = 0; i < result.size(); i++)
        {
            cout << "(" << result[i].first << ", " << result[i].second << ")";
            if (i < result.size() - 1) cout << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cin >> n;
    PriorityQueue pq;

    for (int i = 0; i < n; i++)
    {
        string command;
        cin >> command;
        if (command == "enqueue")
        {
            int x, p;
            cin >> x >> p;
            pq.enqueue(x, p);
        }
        else if (command == "dequeue")
        {
            pq.dequeue();
        }
    }

    pq.printQueue();
    return 0;
}
