#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if (((n - 2) * (n - 1)) / 2 > k) {
    for (int i = 0; i < n; i++) cout << "0 " << i << endl;
  } else {
    cout << "no solution" << endl;
  }
  return 0;
}
