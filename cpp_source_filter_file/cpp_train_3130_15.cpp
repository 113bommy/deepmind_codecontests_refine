#include<iostream>
using namespace std;
void main(){
  int a[100],n;
  cin>>n;
  for(int i=0;i<n;i++)
    cin >> a[i];
  for(int j=n-1;j>=0;j--){
    cout<<a[j];
    if(j!=0)
      cout<<" ";
  }
  cout<<endl;
  return ;
}