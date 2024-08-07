#include <bits/stdc++.h>
using namespace std;
vector<int> v;
struct Info {
  int l, r, pos;
} G[5005];
bool nishat(Info A, Info B) { return A.l < B.l; }
int P(int a, int n) {
  int i, j, k, f = 1, p, q;
  p = G[a].l;
  q = G[a].r;
  G[a].l = G[a - 1].r;
  G[a].r = G[a + 1].l;
  for (i = 1; i < n; i++) {
    if (G[i].r > G[i + 1].l) {
      f = 0;
      break;
    }
  }
  G[a].l = p;
  G[a].r = q;
  return f;
}
int main() {
  int n, i;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> G[i].l >> G[i].r;
    G[i].pos = i;
  }
  sort(G + 1, G + n + 1, nishat);
  G[n + 1].l = 1000000;
  G[n + 1].r = 10000007;
  for (i = 1; i <= n; i++) {
    if (P(i, n)) v.push_back(G[i].pos);
  }
  sort(v.begin(), v.end());
  cout << v.size() << '\n';
  for (i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << '\n';
}
