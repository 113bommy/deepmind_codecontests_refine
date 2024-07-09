#include <bits/stdc++.h>
using namespace std;
const int maxn = 200100;
int n, Q, fa[maxn];
int ai[maxn], tim, ptr[maxn], rig[maxn], dfn[maxn], BLK, bi[maxn], Z[maxn];
long long atg[maxn], sumb[maxn], suma[maxn], mx[maxn];
vector<pair<long long, long long> > s[maxn];
vector<int> G[maxn], ss[maxn];
int chk(pair<long long, long long> A, pair<long long, long long> B,
        pair<long long, long long> C) {
  return (A.second - B.second) * (C.first - B.first) >=
         (B.second - C.second) * (B.first - A.first);
}
vector<pair<long long, long long> > getconv(
    vector<pair<long long, long long> >& v) {
  vector<pair<long long, long long> > ret;
  for (auto a : v) {
    if (ret.size() && ret.back().first == a.first) continue;
    while (ret.size() >= 2 && chk(ret[ret.size() - 2], ret[ret.size() - 1], a))
      ret.pop_back();
    ret.push_back(a);
  }
  return ret;
}
long long cal(pair<long long, long long> a, long long x) {
  return a.first * x + a.second;
}
void build(int id) {
  int l = (id - 1) * BLK + 1, r = min(id * BLK, n);
  if (l > r) return;
  s[id].clear(), ptr[id] = 0;
  mx[id] = -1e18;
  for (int i = l; i <= r; ++i) {
    ss[id].push_back(i);
    if (suma[i] < 0)
      s[id].push_back(
          pair<long long, long long>(-sumb[i], abs(suma[i]) * sumb[i]));
    else
      s[id].push_back(
          pair<long long, long long>(sumb[i], abs(suma[i]) * sumb[i]));
    if (suma[i] < 0) mx[id] = max(mx[id], suma[i]);
  }
  sort(s[id].begin(), s[id].end(),
       [](pair<long long, long long> a, pair<long long, long long> b) {
         if (a.first == b.first) return a.second > b.second;
         return a.first < b.first;
       });
  sort(ss[id].begin(), ss[id].end(),
       [](int a, int b) { return sumb[a] < sumb[b]; });
  s[id] = getconv(s[id]);
  while (ptr[id] + 1 < s[id].size() &&
         cal(s[id][ptr[id]], atg[id]) < cal(s[id][ptr[id] + 1], atg[id]))
    ptr[id]++;
}
void build(int id, int X) {
  int l = (id - 1) * BLK + 1, r = min(id * BLK, n);
  if (l > r) return;
  ptr[id] = 0;
  mx[id] = -1e18;
  for (int i = l; i <= r; ++i)
    if (suma[i] < 0) mx[id] = max(mx[id], suma[i]);
  s[id].clear();
  auto ins = [&](pair<long long, long long> p) {
    if (s[id].size() && s[id].back().first == p.first)
      s[id].back() = max(s[id].back(), p);
    else
      s[id].push_back(p);
  };
  for (int i = ss[id].size() - 1; i >= 0; --i) {
    int z = ss[id][i];
    if (suma[z] < 0)
      ins(pair<long long, long long>(-sumb[z], abs(suma[z]) * sumb[z]));
  }
  for (int i = 0; i < ss[id].size(); ++i) {
    int z = ss[id][i];
    if (suma[z] >= 0)
      ins(pair<long long, long long>(sumb[z], abs(suma[z]) * sumb[z]));
  }
  s[id] = getconv(s[id]);
  while (ptr[id] + 1 < s[id].size() &&
         cal(s[id][ptr[id]], atg[id]) < cal(s[id][ptr[id] + 1], atg[id]))
    ptr[id]++;
}
void pd(int id) {
  int l = (id - 1) * BLK + 1, r = min(id * BLK, n);
  if (l > r) return;
  for (int i = l; i <= r; ++i) suma[i] += atg[id];
  atg[id] = 0;
}
void dfs(int u) {
  dfn[u] = ++tim;
  Z[tim] = u;
  for (auto v : G[u]) dfs(v);
  rig[u] = tim;
}
long long tmp[maxn];
void change(int* a) {
  for (int i = 1; i <= n; ++i) tmp[i] = a[Z[i]];
  for (int i = 1; i <= n; ++i) a[i] = tmp[i];
}
void change(long long* a) {
  for (int i = 1; i <= n; ++i) tmp[i] = a[Z[i]];
  for (int i = 1; i <= n; ++i) a[i] = tmp[i];
}
int main() {
  scanf("%d%d", &n, &Q);
  for (int i = 2; i <= n; ++i) scanf("%d", &fa[i]), G[fa[i]].push_back(i);
  for (int i = 1; i <= n; ++i) scanf("%d", &ai[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &bi[i]);
  for (int i = 1; i <= n; ++i) {
    sumb[i] = sumb[fa[i]] + bi[i];
    suma[i] = suma[fa[i]] + ai[i];
  }
  for (int i = 1; i <= n; ++i) sumb[i] = abs(sumb[i]);
  dfs(1);
  change(suma), change(sumb);
  BLK = sqrt(n) + 1;
  for (int i = 1; i <= (n - 1) / BLK + 1; ++i) build(i);
  for (int zz = 1; zz <= Q; ++zz) {
    int op, v, x;
    scanf("%d%d", &op, &v);
    if (op == 1) scanf("%d", &x);
    if (op == 1) {
      int l = dfn[v], r = rig[v];
      int ql = (l - 1) / BLK + 1, qr = (r - 1) / BLK + 1;
      if (ql == qr) {
        pd(ql);
        for (int i = l; i <= r; ++i) suma[i] += x;
        build(ql, x);
      } else {
        pd(ql);
        for (int i = l; i <= ql * BLK && i <= n; ++i) suma[i] += x;
        pd(qr);
        for (int i = (qr - 1) * BLK + 1; i <= r; ++i) suma[i] += x;
        build(ql, x), build(qr, x);
        for (int i = ql + 1; i <= qr - 1; ++i) {
          if (mx[i] + x >= 0) {
            atg[i] += x;
            pd(i);
            build(i, x);
          } else {
            mx[i] += x;
            atg[i] += x;
            while (ptr[i] + 1 < s[i].size() &&
                   cal(s[i][ptr[i]], atg[i]) < cal(s[i][ptr[i] + 1], atg[i]))
              ptr[i]++;
          }
        }
      }
    } else {
      int l = dfn[v], r = rig[v];
      int ql = (l - 1) / BLK + 1, qr = (r - 1) / BLK + 1;
      long long ans = -1e18;
      if (ql == qr) {
        for (int i = l; i <= r; ++i)
          ans = max(ans, abs(suma[i] + atg[ql]) * sumb[i]);
      } else {
        for (int i = l; i <= ql * BLK && i <= n; ++i)
          ans = max(ans, abs(suma[i] + atg[ql]) * sumb[i]);
        for (int i = (qr - 1) * BLK + 1; i <= r; ++i)
          ans = max(ans, abs(suma[i] + atg[qr]) * sumb[i]);
        for (int i = ql + 1; i <= qr - 1; ++i) {
          ans = max(ans, cal(s[i][ptr[i]], atg[i]));
        }
      }
      printf("%lld\n", ans);
    }
  }
}
