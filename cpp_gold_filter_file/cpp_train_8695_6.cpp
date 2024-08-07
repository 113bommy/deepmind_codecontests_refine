#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
long long f[1010][1010], pr[1010 * 1010], g[1010 * 1010], root, po, so_i, so_j,
    h[1010][1010];
vector<long long> a;
int px[4] = {0, 0, 1, -1};
int py[4] = {1, -1, 0, 0};
int chg(int x, int y) { return m * (x - 1) + y; }
int parent(int x) {
  if (pr[x] == 0) return x;
  return pr[x] = parent(pr[x]);
}
bool check(int x) {
  long long del = n * m - x;
  if (1LL * del * a[x] < 1LL * k) return false;
  memset(pr, 0, sizeof(pr));
  for (int i = 1; i <= n * m; i++) g[i] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (f[i][j] < a[x]) continue;
      int u = chg(i, j);
      for (int z = 0; z < 4; z++) {
        if (i + px[z] <= 0 || i + px[z] > n) continue;
        if (j + py[z] <= 0 || j + py[z] > m) continue;
        if (f[i + px[z]][j + py[z]] < a[x]) continue;
        int v = chg(i + px[z], j + py[z]);
        int pu = parent(u);
        int pv = parent(v);
        if (pu != pv) {
          if (pu > pv) swap(pu, pv);
          pr[pv] = pu;
          g[pu] += g[pv];
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int u = chg(i, j);
      if (f[i][j] == a[x]) {
        int prr = parent(u);
        if (1LL * g[prr] * a[x] >= 1LL * k) {
          po = a[x];
          so_i = i;
          so_j = j;
          return true;
        }
      }
    }
  }
  return false;
}
void dfs(int i, int j) {
  if (i <= 0 || i > n) return;
  if (j <= 0 || j > m) return;
  if (k == 0) return;
  if (h[i][j] != 0) return;
  if (f[i][j] >= po) {
    k -= po;
    h[i][j] = po;
  } else
    return;
  for (int z = 0; z < 4; z++) {
    dfs(i + px[z], j + py[z]);
  }
}
void outans() {
  cout << "YES\n";
  dfs(so_i, so_j);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cout << h[i][j] << " ";
    cout << "\n";
  }
}
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> f[i][j];
      a.push_back(f[i][j]);
    }
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < a.size(); i++) {
    if (k % a[i]) continue;
    if (check(i)) {
      outans();
      return 0;
    }
  }
  cout << "NO";
}
