#include <iostream>
#include <cmath>
using namespace std;
int ucln(int a, int b)
{
   if(a==0 || b==0)
   {
       return a+b;
   }
   int min=a<b?a:b;
   for(int i=min;i>=1;i--)
   {
       if(a%i == 0 && b%i==0)
       {
           return i;
       }
   }
   return 1;
}
int main()
{
   int m,n;
   cin>>m;
   cin>>n;
   cout<<ucln(m,n);
   return 0;
}
