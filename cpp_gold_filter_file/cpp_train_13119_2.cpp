#include <bits/stdc++.h>
using namespace std;

int main(){

string str;

while(1){

cin >> str;

if(str =="0"){
break;
}

int sum=0;

for(int i=0;i<(int)str.size();i++){
sum += str[i] - '0';

}

cout << sum << endl;

}

return 0;

}
