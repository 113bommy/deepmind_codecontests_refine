#include <iostream>
using namespace std;
 
char N[3];
 
int main(){
  cin >> N;
  if(N[0] == '7' || N[1] == '7' || N[2] == '7') cout << "Yes";
  else cout << "No";
}