#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
const ld pi = acos(0) * 2;
template <typename T>
inline void read(T &x) {
  char c;
  bool nega = 0;
  while ((!isdigit(c = getchar())) && (c != '-'))
    ;
  if (c == '-') {
    nega = 1;
    c = getchar();
  }
  x = c - 48;
  while (isdigit(c = getchar())) x = x * 10 + c - 48;
  if (nega) x = -x;
}
template <typename T>
inline void writep(T x) {
  if (x > 9) writep(x / 10);
  putchar(x % 10 + 48);
}
template <typename T>
inline void write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  writep(x);
}
template <typename T>
inline void writeln(T x) {
  write(x);
  putchar('\n');
}
int n, m;
int r[500001];
int root(int u) {
  if (r[u] < u) return u;
  return r[u] = root(r[u]);
}
bool unite(int u, int v) {
  u = root(u);
  v = root(v);
  if (u == v) return 0;
  if (r[u] > r[v]) swap(u, v);
  r[u] += r[v];
  r[v] = u;
  return 1;
}
int main() {
  read(n);
  read(m);
  for (int i = (1); i <= (n); i++) r[i] = -1;
  for (int i = (1); i <= (m); i++) {
    int k;
    read(k);
    int v = -1;
    int u;
    for (int i = (1); i <= (k); i++) {
      read(u);
      if (v != -1)
        unite(u, v);
      else
        v = u;
    }
  }
  for (int i = (1); i <= (n); i++) {
    write(-r[root(i)]);
    putchar(" \n"[i == n]);
  }
}
