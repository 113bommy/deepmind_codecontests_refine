#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,k;
  char s[100];
  cin>>n>>k;
  cin>>s;
  s[k-1]+=32;
  cout<<s;
}
  