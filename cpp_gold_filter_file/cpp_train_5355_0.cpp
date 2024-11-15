#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, const U &b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, const U &b) {
  if (a < b) a = b;
}
template <class T>
inline void gn(T &first) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), first = 0; c >= '0' && c <= '9';
       c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
  if (sg) first = -first;
}
template <class T1, class T2>
inline void gn(T1 &x1, T2 &x2) {
  gn(x1), gn(x2);
}
template <class T1, class T2, class T3>
inline void gn(T1 &x1, T2 &x2, T3 &x3) {
  gn(x1, x2), gn(x3);
}
template <class T1, class T2, class T3, class T4>
inline void gn(T1 &x1, T2 &x2, T3 &x3, T4 &x4) {
  gn(x1, x2, x3), gn(x4);
}
template <class T1, class T2, class T3, class T4, class T5>
inline void gn(T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5) {
  gn(x1, x2, x3, x4), gn(x5);
}
template <class T>
inline void print(T first) {
  if (first < 0) {
    putchar('-');
    return print(-first);
  }
  if (first < 10) {
    putchar('0' + first);
    return;
  }
  print(first / 10);
  putchar(first % 10 + '0');
}
template <class T>
inline void println(T first) {
  print(first);
  putchar('\n');
}
template <class T>
inline void printsp(T first) {
  print(first);
  putchar(' ');
}
template <class T1, class T2>
inline void print(T1 x1, T2 x2) {
  printsp(x1), println(x2);
}
template <class T1, class T2, class T3>
inline void print(T1 x1, T2 x2, T3 x3) {
  printsp(x1), printsp(x2), println(x3);
}
template <class T1, class T2, class T3, class T4>
inline void print(T1 x1, T2 x2, T3 x3, T4 x4) {
  printsp(x1), printsp(x2), printsp(x3), println(x4);
}
template <class T1, class T2, class T3, class T4, class T5>
inline void print(T1 x1, T2 x2, T3 x3, T4 x4, T5 x5) {
  printsp(x1), printsp(x2), printsp(x3), printsp(x4), println(x5);
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
int indeg[300010];
int d[300010];
vector<int> adj[300010];
pair<pair<int, int>, int> pa[300010];
map<pair<int, int>, int> MP;
map<pair<int, int>, int> mp;
int main() {
  int n, p;
  gn(n, p);
  for (int i = 1; i <= n; i++) {
    int u, v;
    gn(u, v);
    adj[i].push_back(u);
    adj[i].push_back(v);
    indeg[u]++;
    indeg[v]++;
    if (u < v) swap(u, v);
    MP[pair<int, int>(u, v)]++;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    d[i] = indeg[i];
    if (d[i] * 2 >= p) ans--;
  }
  sort(d + 1, d + n + 1);
  for (int i = 1; i <= n; i++) {
    int nn = lower_bound(d + 1, d + n + 1, (p - d[i])) - d;
    ans += (n - nn + 1);
  }
  ans /= 2;
  for (int i = 1; i <= n; i++) {
    int u = adj[i][0];
    int v = adj[i][1];
    if (u < v) swap(u, v);
    if (mp.count(pair<int, int>(u, v))) continue;
    mp[pair<int, int>(u, v)] = 1;
    int first = indeg[u] + indeg[v] - MP[pair<int, int>(u, v)];
    if (first < p and indeg[u] + indeg[v] >= p) ans--;
  }
  print(ans);
}
