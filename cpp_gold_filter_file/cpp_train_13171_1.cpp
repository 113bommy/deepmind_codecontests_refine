#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
std::vector<std::vector<int>> ch(200001);
std::vector<int> par(200001);
std::vector<std::vector<int>> nb(200001);
std::vector<std::vector<int>> lvl(200001);
std::vector<int> v_lvl(200001, 0);
std::vector<int> cost(200001, 0);
int l = 2;
long long d, n, m, k;
bool test(int mark) {
  map<std::pair<int, int>, int> areal;
  map<std::pair<int, int>, int> breal;
  std::vector<int> a(n + 1, 0);
  std::vector<int> asum(n + 1, 0);
  std::vector<std::vector<int>> an(n + 1);
  std::vector<std::vector<int>> bn(n + 1);
  std::vector<int> b(n + 1, 0);
  std::vector<int> bestb(n + 1, 0);
  std::vector<int> best2b(n + 1, 0);
  for (int i = l; i > 0; i--) {
    for (auto v : lvl[i]) {
      a[v] = 0;
      b[v] = 0;
      if (cost[v] < mark) {
        continue;
      }
      bool f = true;
      bestb[v] = 1;
      for (auto u : ch[v]) {
        if (a[u] > 0) {
          b[v] += a[u];
          an[v].push_back(a[u]);
        } else {
          bn[v].push_back(b[u]);
          f = false;
          if (b[u] + 1 >= bestb[v]) {
            best2b[v] = bestb[v];
            bestb[v] = b[u] + 1;
          } else if (b[u] + 1 > best2b[v])
            best2b[v] = b[u] + 1;
        }
      }
      asum[v] = b[v];
      b[v] += bestb[v];
      if (f) a[v] = b[v];
    }
  }
  for (int i = 2; i <= l; i++) {
    for (auto v : lvl[i]) {
      int u = par[v];
      int wasa = a[v];
      int wasb = b[v];
      if (cost[v] < mark) {
        continue;
      }
      if (cost[u] < mark) continue;
      if (a[v] > 0) {
        a[v] = a[u];
        b[v] = b[u];
        an[v].push_back(a[u] - a[v]);
      } else if (bn[u].size() == 1) {
        an[v].push_back(b[u] - b[v]);
        b[v] = b[u];
        asum[v] += asum[u] + 1;
      } else {
        sort((bn[u]).begin(), (bn[u]).end());
        reverse((bn[u]).begin(), (bn[u]).end());
        if (bn[u][0] > b[v]) {
          bn[v].push_back(b[u]);
        } else {
          bn[v].push_back(b[u] - bn[u][0] + bn[u][1]);
        }
        int maxb = 0;
        for (auto mm : bn[v]) maxb = max(maxb, mm);
        b[v] = asum[v] + maxb + 1;
      }
    }
  }
  if (a[1] >= k) return true;
  int maxb = 0;
  for (int i = 1; i <= n; i++) maxb = max(maxb, b[i]);
  return (maxb >= k);
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> cost[i];
  m = 1;
  lvl[1].push_back(1);
  v_lvl[1] = 1;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    nb[u].push_back(v);
    nb[v].push_back(u);
  }
  while (m < n) {
    for (int k = 0; k < lvl[l - 1].size(); k++) {
      int v = lvl[l - 1][k];
      for (int h = 0; h < nb[v].size(); h++) {
        if (v_lvl[nb[v][h]] == 0) {
          v_lvl[nb[v][h]] = l;
          lvl[l].push_back(nb[v][h]);
          m++;
          ch[v].push_back(nb[v][h]);
          par[nb[v][h]] = v;
        }
      }
    }
    l++;
  }
  l--;
  std::vector<long long> lsize(l + 1);
  for (int i = 1; i <= l; i++) lsize[i] = lvl[i].size();
  int lm = 1;
  int rm = 1000001;
  while ((rm - lm) > 1) {
    int mm = (lm + rm) / 2;
    if (test(mm)) {
      lm = mm;
    } else {
      rm = mm;
    }
  }
  cout << lm;
}
