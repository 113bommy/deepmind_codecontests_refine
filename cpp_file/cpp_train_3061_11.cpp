#include <bits/stdc++.h>
using namespace std;
template <class t>
inline t read(t &x) {
  char c = getchar();
  bool f = 0;
  x = 0;
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  if (f) x = -x;
  return x;
}
template <class t>
inline void write(t x) {
  if (x < 0)
    putchar('-'), write(-x);
  else {
    if (x > 9) write(x / 10);
    putchar('0' + x % 10);
  }
}
const int mod = 1e9 + 7, N = 55;
int n, m, lim, f[N << 1][2][N];
bool ex[N][N];
vector<int> a[N][N], trans[2][2][N][N];
bool extend_front(deque<int> &q, deque<int>::iterator it) {
  while (it != q.begin() && q.size() <= lim) {
    auto nit = it - 1;
    if (!ex[*nit][*it] || q.size() + a[*nit][*it].size() > lim) return 0;
    q.insert(q.begin(), a[*nit][*it].begin(), a[*nit][*it].end());
    it = nit;
  }
  return q.size() <= lim;
}
bool extend_back(deque<int> &q, deque<int>::iterator it) {
  while (it + 1 != q.end() && q.size() <= lim) {
    auto nit = it + 1;
    if (!ex[*it][*nit] || q.size() + a[*it][*nit].size() > lim) return 0;
    q.insert(q.end(), a[*it][*nit].begin(), a[*it][*nit].end());
    it = nit;
  }
  return q.size() <= lim;
}
void inc(int &x, int y) { x + y >= mod ? x += y - mod : x += y; }
signed main() {
  read(n);
  read(m);
  lim = n << 1 | 1;
  for (int i = 1, x, y, z; i <= m; i++) {
    read(x);
    read(y);
    read(z);
    ex[x][y] = 1;
    a[x][y].resize(z);
    for (int &o : a[x][y]) read(o);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (ex[i][j] && !a[i][j].empty() && a[i][j].back() == i) {
        deque<int> q(a[i][j].begin(), a[i][j].end());
        if (extend_front(q, --q.end()))
          trans[0][0][q.front()][j].push_back(q.size());
      }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (ex[i][j] && !a[i][j].empty() && a[i][j].front() == j) {
        deque<int> q(a[i][j].begin(), a[i][j].end());
        if (extend_back(q, q.begin()))
          trans[1][1][i][q.back()].push_back(q.size());
      }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (ex[i][j] && !a[i][j].empty()) {
        deque<int> q(a[i][j].begin(), a[i][j].end());
        auto p = find(q.begin(), q.end(), i);
        if (p != q.end() && p + 1 != q.end() && *(p + 1) == j &&
            extend_front(q, p) && extend_back(q, p + 1))
          trans[0][1][q.front()][q.back()].push_back(q.size() - 1);
      }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (ex[i][j] && a[i][j].empty()) trans[1][0][i][j].push_back(1);
  for (int i = 1; i <= n; i++) f[0][0][i] = 1;
  for (int len = 0; len < n << 1; len++)
    for (int p : {0, 1})
      for (int i = 1; i <= n; i++)
        if (f[len][p][i])
          for (int q : {0, 1})
            for (int j = 1; j <= n; j++)
              for (int x : trans[p][q][i][j])
                if (len + x <= n << 1) inc(f[len + x][q][j], f[len][p][i]);
  for (int len = 1; len <= n << 1; len++) {
    int ans = 0;
    for (int i = 1; i <= n; i++) inc(ans, f[len][1][i]);
    write(ans);
    puts("");
  }
}
