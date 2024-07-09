#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &num) {
  T x = 0, f = 1;
  char ch = getchar();
  for (; ch > '9' || ch < '0'; ch = getchar())
    if (ch == '-') f = -1;
  for (; ch <= '9' && ch >= '0'; ch = getchar())
    x = (x << 3) + (x << 1) + (ch ^ '0');
  num = x * f;
}
int n, m, Q, id[1005][1005], fa[1100005], siz[1100005], lst[1005][1005],
    X[1005 * 10], Y[1005 * 10], cnt;
int chg[1005][2], tot;
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1, 0},
    dy[] = {0, 0, 1, -1, 1, -1, 1, -1, 0};
char s[1005][1005];
set<int> st[1100005];
inline bool ok(int x, int y) { return 0 <= x && x <= n && 0 <= y && y <= m; }
int find(int x) { return fa[x] == x ? x : find(fa[x]); }
inline void merge(int x, int y) {
  int tx = find(x), ty = find(y);
  if (tx == ty) return;
  if (siz[tx] < siz[ty]) swap(tx, ty);
  fa[ty] = tx;
  siz[tx] += siz[ty];
  chg[++tot][0] = tx;
  chg[tot][1] = ty;
}
void dfs(int x, int y, int d, int dddd) {
  if ((x == 1 && y == 1) || (x == n - 1 && y == m - 1)) return;
  if (s[x][y] == '#') st[dddd].insert(find(id[x][y]));
  if (d == 2) return;
  for (int i = 0; i < 8; i++) {
    int tx = x + dx[i], ty = y + dy[i];
    if (!ok(tx, ty)) continue;
    dfs(tx, ty, d + 1, dddd);
  }
}
int solve() {
  int S = find(id[0][m]), T = find(id[n][0]);
  for (int i = 1; i <= cnt; i++) {
    for (int k = 0; k < 9; k++) {
      int tx = X[i] + dx[k], ty = Y[i] + dy[k];
      if (!ok(tx, ty) || s[tx][ty] == '.') continue;
      int pos = lst[tx][ty];
      if (find(id[tx][ty]) == S) {
        for (auto P : st[pos]) {
          if (find(P) == T) return puts("NO"), P;
        }
      }
      if (find(id[tx][ty]) == T) {
        for (auto P : st[pos]) {
          if (find(P) == S) return puts("NO"), 2;
        }
      }
    }
  }
  for (int i = 1; i <= cnt; i++)
    for (int j = i + 1; j <= cnt; j++) {
      if (max(abs(X[i] - X[j]), abs(Y[i] - Y[j])) <= 2) {
        if (find(id[X[i]][Y[i]]) == S && find(id[X[j]][Y[j]]) == T)
          return puts("NO"), 3;
        if (find(id[X[i]][Y[i]]) == T && find(id[X[j]][Y[j]]) == S)
          return puts("NO"), 3;
      }
    }
  puts("YES");
  return 0;
}
int main() {
  read(n);
  read(m);
  read(Q);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  ++n;
  ++m;
  for (int i = 0; i <= n; i++) s[i][0] = s[i][m] = '#';
  for (int j = 0; j <= m; j++) s[0][j] = s[n][j] = '#';
  s[0][0] = s[0][1] = s[1][0] = s[n][m] = s[n - 1][m] = s[n][m - 1] = '.';
  int iid = 0;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) fa[id[i][j] = ++iid] = iid, siz[iid] = 1;
  for (int x = 0; x <= n; x++)
    for (int y = 0; y <= m; y++) {
      if (s[x][y] == '.') continue;
      for (int k = 0; k < 8; k++) {
        int tx = x + dx[k], ty = y + dy[k];
        if (!ok(tx, ty) || s[tx][ty] == '.') continue;
        merge(id[x][y], id[tx][ty]);
      }
    }
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) dfs(i, j, 0, find(id[i][j]));
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) lst[i][j] = find(id[i][j]);
  for (int ii = 1; ii <= Q; ii++) {
    read(cnt);
    tot = 0;
    for (int i = 1; i <= cnt; i++) read(X[i]), read(Y[i]);
    for (int i = 1; i <= cnt; i++) {
      s[X[i]][Y[i]] = '#';
      for (int k = 0; k < 8; k++) {
        int tx = X[i] + dx[k], ty = Y[i] + dy[k];
        if (!ok(tx, ty) || s[tx][ty] == '.') continue;
        merge(id[X[i]][Y[i]], id[tx][ty]);
      }
    }
    solve();
    fflush(stdout);
    for (int i = 1; i <= tot; i++) {
      fa[chg[i][1]] = chg[i][1];
      siz[chg[i][0]] -= siz[chg[i][1]];
    }
    for (int i = 1; i <= cnt; i++) s[X[i]][Y[i]] = '.';
  }
  return 0;
}
