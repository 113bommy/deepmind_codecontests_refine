#include <bits/stdc++.h>
using namespace std;
int fst[100020], nxt[200020], vv[200020], cost[200020], e;
int n, m;
int dep[100020], fa[100020], sz[100020], cnt[100020];
int id[100020], ord[100020], dc;
int pl, pr;
int ans, ansu, ansv;
int lstu, lstv;
bool del[100020];
int mx[100020], nmx[100020];
int who[100020], nwho[100020];
int len1, len2;
void init() {
  memset(fst, -1, sizeof fst);
  e = 0;
}
void add(int u, int v, int c) {
  vv[e] = v, nxt[e] = fst[u], cost[e] = c, fst[u] = e++;
}
void dfs(int u, int p, int chk, int c, int d) {
  dep[u] = d, cnt[u] = c;
  ord[++dc] = u;
  sz[u] = 1;
  fa[u] = p;
  for (int i = fst[u]; ~i; i = nxt[i]) {
    int v = vv[i];
    if (!del[v] && v != p) {
      dfs(v, u, chk, c + (cost[i] >= chk ? 1 : -1), d + 1);
      sz[u] += sz[v];
    }
  }
}
bool cmp(int u, int v) { return sz[u] < sz[v]; }
bool check() {
  static int q[100020];
  int qh = 0, qt = 0;
  int L = len1, R = len1;
  for (int i = 0; i <= len2; ++i) {
    while (L >= 0 && L + i >= pl) {
      while (qh < qt && mx[L] >= mx[q[qt - 1]]) --qt;
      q[qt++] = L;
      L--;
    }
    while (qh < qt && q[qh] + i > pr) ++qh;
    if (qh < qt) {
      if (mx[q[qh]] + nmx[i] >= 0) {
        lstu = who[q[qh]];
        lstv = nwho[i];
        return true;
      }
    }
  }
  return false;
}
void solve(int rt) {
  dc = 0;
  dfs(rt, -1, -1, 0, 0);
  int mi = 0x3f3f3f3f, sp;
  for (int i = 1; i <= dc; ++i) {
    int u = ord[i];
    int opt = sz[rt] - sz[u];
    for (int j = fst[u]; ~j; j = nxt[j]) {
      int v = vv[j];
      if (!del[v] && v != fa[u]) opt = max(opt, sz[v]);
    }
    if (opt < mi) mi = opt, sp = u;
  }
  rt = sp;
  del[rt] = 1;
  dc = 0;
  dfs(rt, -1, -1, 0, 0);
  static int ch[100020];
  int nch = 0;
  for (int i = fst[rt]; ~i; i = nxt[i]) {
    int v = vv[i];
    if (!del[v]) {
      ch[++nch] = v;
    }
  }
  sort(ch + 1, ch + nch + 1, cmp);
  int l = 0, r = 1e9 + 1;
  while (l < r - 1) {
    int mid = (l + r) / 2;
    len1 = 0;
    mx[0] = 0, who[0] = rt;
    for (int i = fst[rt]; ~i; i = nxt[i]) {
      int v = vv[i];
      if (!del[v]) {
        cnt[v] = cost[i] >= mid ? 1 : -1;
      }
    }
    bool ok = false;
    for (int i = 1; i <= nch; ++i) {
      int u = ch[i];
      dc = 0;
      dfs(u, -1, mid, cnt[u], 1);
      len2 = 0;
      for (int j = 1; j <= dc; ++j) {
        len2 = max(len2, dep[ord[j]]);
      }
      for (int j = 0; j <= len2; ++j) nmx[j] = -0x3f3f3f3f;
      for (int j = 1; j <= dc; ++j) {
        int v = ord[j];
        if (cnt[v] > nmx[dep[v]]) {
          nmx[dep[v]] = cnt[v];
          nwho[dep[v]] = v;
        }
      }
      if (check()) {
        ok = true;
        break;
      }
      for (int i = 0; i <= len2; ++i) {
        if (i > len1 || nmx[i] > mx[i]) {
          mx[i] = nmx[i];
          who[i] = nwho[i];
        }
      }
      len1 = max(len1, len2);
    }
    if (ok) {
      l = mid;
    } else
      r = mid;
  }
  if (l >= ans) ans = l, ansu = lstu, ansv = lstv;
  for (int i = fst[rt]; ~i; i = nxt[i]) {
    int v = vv[i];
    if (!del[v]) solve(v);
  }
}
int main() {
  scanf("%d%d%d", &n, &pl, &pr);
  init();
  for (int i = 1; i < n; ++i) {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    add(u, v, c);
    add(v, u, c);
  }
  solve(1);
  printf("%d %d\n", ansu, ansv);
  return 0;
}
