#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,a,b;
  cin>>n>>a>>b;
  for(int i=1;i<n;i++){
    int x,y;
    cin>>x>>y;
    if(x>a){
      a=x; b=y;
    }
  }
  cout<<a+b<<endl;
}
