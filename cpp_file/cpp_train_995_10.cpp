#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long modpow(long long b, long long e, long long mod) {
  long long ans = 1;
  for (; e; b = b * b % mod, e /= 2)
    if (e & 1) ans = ans * b % mod;
  return ans;
}
const int N = 100005;
int ans = 0, n, opt = 1;
vector<int> g[N];
long long subxor[N];
map<long long, int> hashset;
map<pair<long long, int>, long long> hashkeep;
long long first(long long x, int y) {
  if (y) {
    if (hashkeep.count({x, y})) return hashkeep[{x, y}];
    return hashkeep[{x, y}] = rng();
  }
  return 0;
}
map<long long, int> childxor[N];
void reroot(int x, int y) {
  hashset[subxor[x]]--;
  hashset[subxor[y]]--;
  if (hashset[subxor[x]] == 0) hashset.erase(subxor[x]);
  if (hashset[subxor[y]] == 0) hashset.erase(subxor[y]);
  subxor[y] ^= first(subxor[x], childxor[y][subxor[x]]) ^
               first(subxor[x], childxor[y][subxor[x]] - 1);
  childxor[y][subxor[x]]--;
  subxor[x] ^= first(subxor[y], childxor[x][subxor[y]]) ^
               first(subxor[y], childxor[x][subxor[y]] + 1);
  childxor[x][subxor[y]]++;
  hashset[subxor[x]]++;
  hashset[subxor[y]]++;
}
void make(int x, int p = -1) {
  for (auto w : g[x]) {
    if (w == p) continue;
    make(w, x);
    childxor[x][subxor[w]]++;
  }
  for (auto w : childxor[x]) {
    subxor[x] ^= first(w.first, w.second);
  }
  hashset[subxor[x]]++;
}
void dfs(int x, int p = -1) {
  if ((int)(hashset).size() > ans) ans = (int)(hashset).size(), opt = x;
  for (auto w : g[x]) {
    if (w == p) continue;
    reroot(w, x);
    dfs(w, x);
    reroot(x, w);
  }
}
int32_t main() {
  scanf("%d", &n);
  for (int i = 0; i < (n - 1); ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  make(1);
  dfs(1);
  printf("%d\n", opt);
}
