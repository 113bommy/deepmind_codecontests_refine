#include<bits/stdc++.h>
using namespace std;
int main(){
 int n,i,sum=0,k;
 cin>>n>>k;
int a[n];
for(i=0;i<n;i++)
 cin>>a[i];
sort(a,a+n);
for(i=n-1;i>=n-k;i--)
 sum+=a[i];
cout<<sum;
}