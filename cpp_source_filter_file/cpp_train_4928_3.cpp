#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, h[2005];
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++) cin >> h[i];
  sort(h, h + n);
  cout << h[a] - h[a - 1];
  return 0;
}
