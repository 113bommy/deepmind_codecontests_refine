#include <bits/stdc++.h>
using namespace std;
long long c, v, ans, tans;
long long t[15];
string b, n;
int main() {
  cin >> b >> n >> c;
  for (int i = 0; i < b.size(); i++) v = (v * 10 + b[i] - '0') % c;
  t[0] = 1;
  for (int i = 1; i < 10; i++) t[i] = t[i - 1] * v % c;
  for (int i = n.size() - 1; i >= 0; i--) {
    n[i]--;
    if (n[i] >= '0')
      break;
    else
      n[i] = '9';
  }
  ans = 1;
  for (int i = 0; i < n.size(); i++) {
    tans = ans;
    for (int j = 0; j < 10; j++) ans = ans * tans % c;
    ans = ans * t[n[i] - '0'] % c;
  }
  ans = ans * (v + c - 1) % c;
  if (ans == 0)
    cout << c;
  else
    cout << ans;
  return 0;
}
