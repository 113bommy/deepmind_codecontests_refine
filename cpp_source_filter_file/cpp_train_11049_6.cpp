#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
int n, p[N], sz[N], used[N];
long long ans;
int get(int v) { return (v == p[v]) ? v : p[v] = get(p[v]); }
void unite(int a, int b) {
  a = get(a);
  b = get(b);
  if (a != b) {
    if (sz[a] < sz[b]) swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
  }
}
bool check(int x) {
  while (x) {
    int y = x % 10;
    if (y != 4 && y != 7) return false;
    x /= 10;
  }
  return true;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) p[i] = i, sz[i] = 1;
  for (int i = 1; i < n; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    if (!check(w)) {
      unite(a, b);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (used[i]) continue;
    used[get(i)] = 1;
    int x = get(i);
    ans += sz[x] * 1ll * (n - sz[x]) * 1ll * (n - sz[x] - 1);
  }
  cout << ans << endl;
}
