#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    double a[5];
    for(int i=0; i<5; i++)
    {
        cin>>a[i];
    }
    double max=a[0];
    double min=a[0];
    for(int i=0; i<5; i++)
    {
        if(a[i]<min)
        {
            min=a[i];
        }
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    cout<<setprecision(2)<<max+min;
    return 0;
}
