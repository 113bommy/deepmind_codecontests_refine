#include<iostream>
using namespace std;
int main(){
int a,b,c,i=0;
cin >> a >> b >> c;
for(int x=a,; x<=b; x++){
if(c%x==0) i++;
}
cout << i <<endl;
return 0;
}
