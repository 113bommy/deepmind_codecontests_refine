#include<iostream>
using namespace std;
int main(){
int a,b;
while(1){
cin>>a>>b;
if(a==0&&b==0)break;
if(b<a)cout<<b<<" "<<a<<endl;
else cout<<a<<" "<<b<<endl;
}
return 0
}
