#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,t; cin>>s>>t;
  int n=s.length();
  int cnt=0;
  for(int i=0;i<n;++)
    if(s[i]!=t[i]) cnt++;
  cout<<cnt<<endl;
}