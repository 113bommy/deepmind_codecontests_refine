#include<iostream>
using namespace std;
int main(){
while(true){
int h,w;
cin>>h>>w;
if(h==0&&w==0)
return 0;
for(int i=0;i<h;i++){
for(int j=0;j<w;j++){
if(i==0||i==h-1||j=0||j==w-1)
cout<<'#';
else
cout<<'.';

}
cout<<'\n';
}
cout<<'\n';

}





}