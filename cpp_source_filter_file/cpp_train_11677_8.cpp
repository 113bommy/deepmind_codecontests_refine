#include <bits/stdc++.h>
using namespace std;
template <typename _T>
inline void read(_T &f) {
  f = 0;
  _T fu = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') fu = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    f = (f << 3) + (f << 1) + (c & 15);
    c = getchar();
  }
  f *= fu;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x < 10)
    putchar(x + 48);
  else
    print(x / 10), putchar(x % 10 + 48);
}
template <typename T>
void print(T x, char t) {
  print(x);
  putchar(t);
}
template <typename T>
struct hash_map_t {
  vector<T> v, val, nxt;
  vector<int> head;
  int mod, tot, lastv;
  T lastans;
  bool have_ans;
  hash_map_t(int md = 0) {
    head.clear();
    v.clear();
    val.clear();
    nxt.clear();
    tot = 0;
    mod = md;
    nxt.resize(1);
    v.resize(1);
    val.resize(1);
    head.resize(mod);
    have_ans = 0;
  }
  void clear() { *this = hash_map_t(mod); }
  bool count(int x) {
    int u = x % mod;
    for (register int i = head[u]; i; i = nxt[i]) {
      if (v[i] == x) {
        have_ans = 1;
        lastv = x;
        lastans = val[i];
        return 1;
      }
    }
    return 0;
  }
  void ins(int x, int y) {
    int u = x % mod;
    nxt.push_back(head[u]);
    head[u] = ++tot;
    v.push_back(x);
    val.push_back(y);
  }
  int qry(int x) {
    if (have_ans && lastv == x) return lastans;
    count(x);
    return lastans;
  }
};
int n, m;
void calc(int x, int y) {
  print(x, ' ');
  print(y, '\n');
}
void dfs1(int x, int y, int opt) {
  calc(x, y);
  int gox = n - x + 1, goy = m - y + 1;
  if (opt == 1) goy++;
  if (goy == m + 1) gox++, goy = 1;
  if (gox == x) return;
  dfs1(gox, goy, opt ^ 1);
}
void dfs2(int x, int y, int opt) {
  int gox = n - x + 1, goy = m - y + 1;
  if (gox == x) return;
  calc(x, y);
  if (opt == 1) goy++;
  if (goy == m + 1) gox++, goy = 1;
  dfs2(gox, goy, opt ^ 1);
}
int main() {
  read(n);
  read(m);
  if (n % 2 == 0)
    dfs1(1, 1, 0);
  else {
    dfs2(1, 1, 0);
    for (register int i = 1; i <= m / 2 + 1; i++) {
      calc(n / 2 + 1, i);
      if (m - i + 1 != i) calc(n / 2 + 1, m - i + 1);
    }
  }
  return 0;
}
