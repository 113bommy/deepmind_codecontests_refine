#include <bits/stdc++.h>
using namespace std;
int t, a[10], b[10];
int main() {
  int i, j, k;
  cin >> t;
  while (t > 0) {
    k = t % 10;
    a[k]++;
    t /= 10;
  }
  string s;
  cin >> s;
  for (i = 0; i < s.size(); i++) {
    b[s[i] - '0']++;
  }
  a[6] += a[9], a[2] += a[5];
  a[9] = 0, a[5] = 0;
  b[6] += b[9], b[2] += b[5];
  b[9] = 0, b[5] = 0;
  int min = 999999;
  for (i = 0; i <= 9; i++)
    if (a[i] != 0) {
      k = b[i] / a[i];
      if (k < min) min = k;
    }
  cout << k << endl;
  return 0;
}
