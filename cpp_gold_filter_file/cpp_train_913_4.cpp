#include<bits/stdc++.h>
using namespace std;
 
int main(){
   int t;
  cin >> t;
  int a[t];
  for (int i =0 ;i < t; i++){
    cin >> a[i];
  }
  
  sort(a,a+t);
  double rtr = a[0];
  for (int i = 1; i < t; i++){
    rtr = (rtr + a[i])/2;
  }
  
  cout << rtr;
}