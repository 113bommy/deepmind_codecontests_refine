#include<bits/stdcc++.h>
using namespace std;
using ll=long long;
int main(){
  ll a,b;int k;cin>>a>>b>>k;
  for(int i=0;i<k;i++){
    if(k%2==0){a/=2;b+=a;}
    else{b/=2;a+=b;}
  }
  cout<<a<<' '<<b<<endl;
}
   
  