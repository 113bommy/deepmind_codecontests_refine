#include<bits/stdc++.h>
using namespace std;
#define MAX_N 1<<17
int n,dat[2*(MAX_N)-1];

//INT＿MAXで初期化
void init(int n_){
  n=1;
  while(n<n_)n*=2;
  for(int i=0;i<2*n-1;i++)dat[i]=INT_MAX;
}

void update(int k,int a){
  k+=n-1;
  dat[k]=a;
  while(k>0){
    k=(k-1)/2;
    dat[k]=min(dat[k*2+1],dat[k*2+2]);
  }
}

int query(int a,int b,int k=0,int l=0,int r=n){
  if(r<=a||b<=l)return INT_MAX;
  if(a<=l&&r<=b)return dat[k];
  else{
    int vl=query(a,b,k*2+1,l,(l+r)/2);
    int vr=query(a,b,k*2+2,(l+r)/2,r);
    return min(vl,vr);
  }
}

int main(){
  int q;
  cin>>n>>q;
  init(n);
  for(int i=0;i<q;i++){
    int com,x,y;
    cin>>com>>x>>y;
    if(com)cout<<query(x,y+1)<<endl;
    else update(x,y);
  }
  return 0;
}

