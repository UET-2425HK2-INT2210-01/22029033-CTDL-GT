#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    int n, x;
    cin >> n;
    string op;
    while (n--)
    {
        cin >> op;
        if (op == "push")
        {
            cin >> x, s.push(x);
        }
        else if (op == "pop" && !s.empty())
        {
            s.pop();
        }
    }
    stack<int> temp;
    while (!s.empty())
    {
        temp.push(s.top());
        s.pop();
    }
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    return 0;
}
