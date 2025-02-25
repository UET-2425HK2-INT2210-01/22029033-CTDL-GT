#include<iostream>
using namespace std;
int main()
{
    int n, dem=0;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<n; i++)
    {
        if(a[i-1]+a[i]+a[i+1]==0)
        {
            dem++;
        }
    }
    cout<<dem;
    return 0;
}
