#include <iostream>
using namespace std;
long long L[100];
int N;
int main(){
	cin >> N;
  	L[0] = 2; L[1] = 1;
  	for(int i=2;i<=N;i++){
		L[i] = L[i-1]+L[i-2];
    }
  cout << L[N] << endl;
}
