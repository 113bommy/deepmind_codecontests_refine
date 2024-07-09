#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  char ch = getchar();
  bool d = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') d = 0;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return d ? x : -x;
}
inline void write(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (x >= 10) write(x / 10);
  putchar('0' + x % 10);
}
inline void writeln(long long x) {
  write(x);
  puts("");
}
inline void writep(long long x) {
  write(x);
  putchar(' ');
}
inline unsigned long long rnd() {
  return ((unsigned long long)rand() << 30 ^ rand()) << 4 | rand() % 4;
}
const int N = 105, mo = 1e9 + 7;
int n, f[N][N][2];
vector<long long> v[N][N], zy[2][2][N][N];
bool b[N][N];
bool check(deque<int> &q, deque<int>::iterator it, bool op) {
  if (!op) {
    for (auto pre = prev(it); it != q.begin() && (int)q.size() <= 2 * n;
         it = pre, pre = prev(it)) {
      if (!b[*pre][*it]) return 0;
      q.insert(q.begin(), v[*pre][*it].begin(), v[*pre][*it].end());
    }
  } else {
    for (auto nxt = next(it); nxt != q.end() && (int)q.size() <= 2 * n;
         it = nxt, nxt = next(it)) {
      if (!b[*it][*nxt]) return 0;
      q.insert(q.end(), v[*it][*nxt].begin(), v[*it][*nxt].end());
    }
  }
  return (int)q.size() <= 2 * n;
}
void init() {
  for (int i = (int)(1); i <= (int)(n); i++)
    for (int j = (int)(1); j <= (int)(n); j++)
      if (b[i][j]) {
        int sz = (int)v[i][j].size();
        if (sz == 0 || v[i][j][sz - 1] != i) continue;
        deque<int> q(v[i][j].begin(), v[i][j].end());
        if (check(q, prev(q.end()), 0))
          zy[0][0][q.front()][j].push_back(q.size());
      }
  for (int i = (int)(1); i <= (int)(n); i++)
    for (int j = (int)(1); j <= (int)(n); j++)
      if (b[i][j]) {
        int sz = (int)v[i][j].size();
        if (sz == 0 || v[i][j][0] != j) continue;
        deque<int> q(v[i][j].begin(), v[i][j].end());
        if (check(q, q.begin(), 1)) zy[1][1][i][q.back()].push_back(q.size());
      }
  for (int i = (int)(1); i <= (int)(n); i++)
    for (int j = (int)(1); j <= (int)(n); j++)
      if (b[i][j]) {
        int sz = (int)v[i][j].size();
        if (sz) continue;
        zy[1][0][i][j].push_back(1);
      }
  for (int i = (int)(1); i <= (int)(n); i++)
    for (int j = (int)(1); j <= (int)(n); j++)
      if (b[i][j]) {
        int sz = (int)v[i][j].size();
        if (sz <= 1) continue;
        auto pos = find(v[i][j].begin(), v[i][j].end(), i);
        if (pos == v[i][j].end() || ++pos == v[i][j].end() || *pos != j)
          continue;
        deque<int> q(v[i][j].begin(), v[i][j].end());
        auto it = q.begin() + (pos - v[i][j].begin()) - 1;
        if (check(q, it, 0) && check(q, it + 1, 1))
          zy[0][1][q.front()][q.back()].push_back(q.size() - 1);
      }
}
void upd(int &x, int y) {
  x += y;
  if (x >= mo) x -= mo;
}
int main() {
  n = read();
  int m = read();
  for (int i = (int)(1); i <= (int)(m); i++) {
    int x = read(), y = read(), k = read();
    for (int j = (int)(1); j <= (int)(k); j++) v[x][y].push_back(read());
    b[x][y] = 1;
  }
  init();
  for (int i = (int)(1); i <= (int)(n); i++) f[i][0][0] = 1;
  for (int j = (int)(0); j <= (int)(2 * n - 1); j++)
    for (int i = (int)(1); i <= (int)(n); i++) {
      for (int k = (int)(0); k <= (int)(1); k++)
        if (f[i][j][k]) {
          for (int t = (int)(0); t <= (int)(1); t++)
            for (int l = (int)(1); l <= (int)(n); l++) {
              for (auto ssw : zy[k][t][i][l]) {
                if (j + ssw <= 2 * n) upd(f[l][j + ssw][t], f[i][j][k]);
              }
            }
        }
    }
  for (int o = (int)(1); o <= (int)(2 * n); o++) {
    int ans = 0;
    for (int i = (int)(1); i <= (int)(n); i++) upd(ans, f[i][o][1]);
    printf("%d\n", ans);
  }
}
