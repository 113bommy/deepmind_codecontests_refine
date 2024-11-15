#include <bits/stdc++.h>
using namespace std;
long long h[100010];
int _h[100010];
int n;
bool posibil(int p, long long t, int nr);
int main() {
  _h[0] = 1;
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  int m;
  cin >> n >> m;
  for (int i(1); i <= n; i++) cin >> _h[i];
  while (!h[n]) n--;
  long long p(0), q(1ll << 60);
  while (q) {
    if (!posibil(0, p + q, m)) p += q;
    q >>= 1ll;
  }
  cout << p + 1ll;
  return 0;
}
bool posibil(int p, long long t, int nr) {
  for (int i(0); i <= n; i++) h[i] = _h[i];
  int loc(n);
  long long in_plus(0);
  while (nr--) {
    if (loc + h[loc] <= t) in_plus += t - loc - h[loc];
    h[loc] -= t - loc;
    if (h[loc] > 0) continue;
    while (1) {
      loc--;
      if (loc == 0) return true;
      int x(min(h[loc], in_plus));
      in_plus -= x;
      h[loc] -= x;
      if (h[loc] != 0) break;
    }
  }
  return false;
}
