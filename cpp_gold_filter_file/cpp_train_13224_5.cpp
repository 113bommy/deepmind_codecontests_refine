#include<iostream>
using namespace std;

int main(){
 int n,m,c;
 int a[100][100],b[100];
 cin >> n >> m;
 a[n][m]={};
 b[m]={};

 for(int i=0;i<n;++i){
  for(int j=0;j<m;++j){
   cin >> a[i][j];
  }
 }

 for(int j=0;j<m;++j){
  cin >> b[j];
 }
 
 for(int i=0;i<n;++i){
  c=0;
  for(int j=0;j<m;++j){
   c+=a[i][j]*b[j];
  }
  cout << c << endl;
 }
return 0;
}