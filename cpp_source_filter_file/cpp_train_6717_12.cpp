#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int sum = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    sum += pow(2, i);
  }
  cout << sum;
  return 0;
}
