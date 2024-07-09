#include <bits/stdc++.h>
using namespace std;
const int oo = 1000000009;
const double eps = 1e-6;
const int mod = 1000000007;
const int mx = 22;
int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};
int n, m, males, females;
char mapp[mx][mx];
int mr[mx * mx], mc[mx * mx], mt[mx * mx];
int fr[mx * mx], fc[mx * mx], ft[mx * mx];
int mat[mx][mx][mx][mx];
int last_my[(3 * mx * mx + 2)], tlast_my[(3 * mx * mx + 2)],
    d[(3 * mx * mx + 2)];
int c[(3 * mx * mx * mx * mx) * 2], ver[(3 * mx * mx * mx * mx) * 2],
    next_my[(3 * mx * mx * mx * mx) * 2];
int ptr = 1;
void addEdge(int from, int to, int cap) {
  ver[ptr] = to;
  c[ptr] = cap;
  next_my[ptr] = last_my[from];
  last_my[from] = ptr++;
  ver[ptr] = from;
  c[ptr] = 0;
  next_my[ptr] = last_my[to];
  last_my[to] = ptr++;
}
int opp(int n) {
  if (n & 1) return n + 1;
  return n - 1;
}
int temp;
int dfs(int cur, int flow, int &n) {
  if (cur == n) return flow;
  for (int &i = last_my[cur]; i; i = next_my[i])
    if (c[i] && d[cur] == (d[ver[i]] - 1) &&
        (temp = dfs(ver[i], c[i] < flow ? c[i] : flow, n))) {
      c[i] -= temp;
      c[opp(i)] += temp;
      return temp;
    }
  d[cur] = -1;
  return 0;
}
int dinic(int S, int T) {
  int ans = 0;
  for (int i = 0; i <= T; i++) tlast_my[i] = last_my[i];
  while (1) {
    for (int i = 0; i <= T; i++) last_my[i] = tlast_my[i], d[i] = -1;
    queue<int> Q;
    Q.push(S);
    d[S] = 0;
    while (!Q.empty()) {
      int cur = Q.front();
      Q.pop();
      for (int i = last_my[cur]; i; i = next_my[i])
        if (c[i] && d[ver[i]] == -1) {
          d[ver[i]] = d[cur] + 1;
          Q.push(ver[i]);
        }
    }
    if (d[T] == -1) break;
    int t;
    while (1) {
      t = dfs(S, oo, T);
      if (t)
        ans += t;
      else
        break;
    }
  }
  return ans;
}
int s, t, mstart, fstart, ostart, istart;
bool ok(long long prev, long long lim) {
  ptr = 1;
  memset(last_my, 0, sizeof(last_my));
  for (int i = 0; i < (n * m); ++i) addEdge(istart + i, ostart + i, 1);
  for (int i = 0; i < (males); ++i) addEdge(s, mstart + i, 1);
  for (int i = 0; i < (females); ++i) addEdge(fstart + i, t, 1);
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (m); ++j) {
      for (int k = 0; k < (males); ++k) {
        int si = mr[k], sj = mc[k];
        if (mat[si][sj][i][j] >= oo) continue;
        long long c = 1ll * mat[si][sj][i][j] * mt[k];
        if (c <= lim) {
          addEdge(mstart + k, istart + i * m + j, 1);
        }
      }
      for (int k = 0; k < (females); ++k) {
        int si = fr[k], sj = fc[k];
        if (mat[si][sj][i][j] >= oo) continue;
        long long c = 1ll * mat[si][sj][i][j] * ft[k];
        if (c <= lim) {
          addEdge(ostart + i * m + j, fstart + k, 1);
        }
      }
    }
  int flow = dinic(s, t);
  return flow == males;
}
int main() {
  scanf("%d %d", &n, &m);
  scanf("%d %d", &males, &females);
  for (int i = 0; i < (n); ++i) scanf("%s", mapp[i]);
  int r, c, _t;
  scanf("%d %d %d", &r, &c, &_t);
  if (males < females) {
    mr[males] = r;
    mc[males] = c;
    mt[males] = _t;
  } else {
    ;
    fr[females] = r;
    fc[females] = c;
    ft[females] = _t;
  }
  for (int i = 0; i < (males); ++i) scanf("%d %d %d", mr + i, mc + i, mt + i);
  for (int i = 0; i < (females); ++i) scanf("%d %d %d", fr + i, fc + i, ft + i);
  if (males < females)
    ++males;
  else
    ++females;
  if (males != females) {
    printf("-1\n");
    return 0;
  }
  for (int i = 0; i < (males); ++i) --mr[i], --mc[i];
  for (int i = 0; i < (females); ++i) --fr[i], --fc[i];
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (m); ++j) {
      for (int ji = 0; ji < (n); ++ji)
        for (int jj = 0; jj < (m); ++jj) mat[i][j][ji][jj] = oo;
      mat[i][j][i][j] = 0;
      if (mapp[i][j] == '.') {
        for (int d = 0; d < (4); ++d) {
          int ni = i + di[d], nj = j + dj[d];
          if (ni >= 0 && ni < n && nj >= 0 && nj < m && mapp[ni][nj] == '.') {
            mat[i][j][ni][nj] = 1;
          }
        }
      }
    }
  for (int ki = 0; ki < (n); ++ki)
    for (int kj = 0; kj < (m); ++kj)
      for (int ii = 0; ii < (n); ++ii)
        for (int ij = 0; ij < (m); ++ij)
          for (int ji = 0; ji < (n); ++ji)
            for (int jj = 0; jj < (m); ++jj) {
              mat[ii][ij][ji][jj] =
                  min(mat[ii][ij][ji][jj],
                      mat[ii][ij][ki][kj] + mat[ki][kj][ji][jj]);
            }
  long long mx_s = 1ll * n * m * n * m * oo;
  long long lo = 0, hi = mx_s;
  s = 0;
  mstart = 1;
  istart = mstart + males;
  ostart = istart + n * m;
  fstart = ostart + n * m;
  t = fstart + females;
  long long last_mid = -oo;
  while (lo < hi) {
    long long mid = (lo + hi) / 2;
    if (ok(last_mid, mid))
      hi = mid;
    else
      lo = mid + 1;
    last_mid = mid;
  }
  if (lo == mx_s) lo = -1;
  printf("%lld\n", lo);
  return 0;
}
