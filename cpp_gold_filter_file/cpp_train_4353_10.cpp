#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  char a[120];
  pair<pair<string,int>,int> b[110];
  for(int i=0;i<N;i++){
 int t;
    cin>>a>>t;
    string A=a;
    b[i]=make_pair(make_pair(a,-t),i);
    
  
  }
  sort(b,b+N);
  for(int i=0;i<N;i++){
    cout<<b[i].second+1<<endl;
    
  }

}
