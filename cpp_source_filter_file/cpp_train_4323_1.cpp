#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 25; i >= 0; i--) {
    if ((n >> i) & 1) cout << (1 << i) << ' ';
  }
  return 0;
}
