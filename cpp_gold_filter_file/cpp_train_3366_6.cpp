#include <bits/stdc++.h>
using namespace std;
const int u = 1010;
vector<int> a[u];
int d[u][u], e[u * u], v[u], x[u], y[u], n, m, k, i, j, l, r, mid;
bool dfs(int x, int k) {
  if (x > n) return 1;
  if (v[x]) return dfs(x + 1, k);
  int i, temp;
  for (i = 0; i < a[x].size(); i++) k -= !v[a[x][i]]++;
  if (k >= 0 && dfs(x + 1, k)) return 1;
  temp = max(-1, k);
  for (i = 0; i < a[x].size(); i++) k += !--v[a[x][i]];
  v[x] = 1, k--;
  if (k > temp && dfs(x + 1, k)) return 1;
  v[x] = 0;
  return 0;
}
bool calc(int dist) {
  for (i = 1; i <= n; i++) a[i].clear(), v[i] = 0;
  for (i = 1; i < n; i++)
    for (j = i + 1; j <= n; j++)
      if (d[i][j] > dist) a[i].push_back(j), a[j].push_back(i);
  return dfs(1, k);
}
int main() {
  cin >> n >> k;
  for (i = 1; i <= n; i++) cin >> x[i] >> y[i];
  for (i = 1; i < n; i++)
    for (j = i + 1; j <= n; j++)
      e[++m] = d[i][j] =
          (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
  sort(e, e + m + 1);
  m = unique(e, e + m + 1) - e - 1;
  l = 0, r = m;
  while (l < r) {
    mid = (l + r) / 2;
    if (calc(e[mid]))
      r = mid;
    else
      l = mid + 1;
  }
  calc(e[l]);
  for (i = 1; i <= n; i++)
    if (v[i]) cout << i << ' ', k--;
  for (i = 1; i <= n; i++)
    if (k && !v[i]) cout << i << ' ', k--;
  cout << endl;
  return 0;
}
