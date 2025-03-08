#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValidParentheses(const string& s)
{
    stack<char> st;
    unordered_map<char, char> bracket_map = {{')', '('}, {']', '['}, {'}', '{'}};

    for (char c : s)
    {
        if (bracket_map.count(c))
        {
            char top = st.empty() ? '#' : st.top();
            if (top == '#' || top != bracket_map[c])
            {
                return false;
            }
            st.pop();
        } else
        {
            st.push(c);
        }
    }
    return st.empty();
}

int main() {
    string s;
    cin >> s;

    cout << (isValidParentheses(s) ? "Valid" : "Invalid") << endl;

    return 0;
}
