#include<bits/stdc++.h>
using namespace std;
int n;
long long a[87];
int main()
{
    cin>>n;
    a[0]=1;
    a[1]=1;
    for(int i=2;i<=n;i++)
        f[i]=f[i-1]+f[i-2];
    cout<<f[n];
}