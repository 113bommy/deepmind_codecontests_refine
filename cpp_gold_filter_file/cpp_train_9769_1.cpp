#include<bits/stdc++.h>
using namespace std;
int main(){
  char a[4];
  
  cin>>a;
  if(a[0]==a[1]&&a[1]==a[2]||a[3]==a[1]&&a[1]==a[2])
    cout << "Yes" <<endl;
  else cout << "No" <<endl;
}