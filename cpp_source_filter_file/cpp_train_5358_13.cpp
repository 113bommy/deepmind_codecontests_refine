#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int n = a + b + 1;
  vector<int> v;
  int m = n - b;
  for (int i = b + 1; i <= n; i++) {
    cout << i << ' ';
  }
  for (int i = 1; i <= b; i++) {
    cout << i << ' ';
  }
}
