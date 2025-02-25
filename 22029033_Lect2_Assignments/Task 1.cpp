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
        for(int j=n-1; j>=i+1; j--)
        {
            if(a[j]==a[i])
            {
                dem+=1;
            }
        }
    }
    cout<<dem;
    return 0;
}
