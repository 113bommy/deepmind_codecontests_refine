#include<iostream>
using namespace std;
int main()
{
int n,t=0;
cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  for(int i=0;i<n;i++)
{
  if(i%2==0&&a[i]%2==1)
  t++;
  }
  cout<<t;
  return 0;
}