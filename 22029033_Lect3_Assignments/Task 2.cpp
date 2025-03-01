#include <iostream>
using namespace std;
long long luythua(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return 2*luythua(n - 1);
    }
}
int main()
{
    int n;
    cin >> n;
    cout << luythua(n);
    return 0;
}
