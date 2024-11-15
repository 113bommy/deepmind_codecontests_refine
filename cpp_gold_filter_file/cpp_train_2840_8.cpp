#include <bits/stdc++.h>
#pragma GCC optimize(2, 3, "Ofast")
using namespace std;
namespace fast_io {
char buf[1 << 12], *p1 = buf, *p2 = buf, sr[1 << 23], z[23], nc;
int C = -1, Z = 0, Bi = 0, Ny;
inline char gc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 12, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline long long read() {
  long long x = 0;
  Ny = 1;
  while (nc = gc(), (nc < 48 || nc > 57) && nc != EOF)
    if (nc == 45) Ny = -1;
  Bi = 1;
  if (nc < 0) return nc;
  x = nc - 48;
  while (nc = gc(), 47 < nc && nc < 58 && nc != EOF)
    x = (x << 3) + (x << 1) + (nc ^ 48), Bi++;
  return x * Ny;
}
inline double gf() {
  int a = read(), y = Ny, b = (nc != '.') ? 0 : read();
  return (b ? a + (double)b / pow(10, Bi) * y : a);
}
inline int gs(char *s) {
  char c, *t = s;
  while (c = gc(), c <= 32)
    ;
  *s++ = c;
  while (c = gc(), c > 32) *s++ = c;
  return s - t;
}
inline void ot() {
  fwrite(sr, 1, C + 1, stdout);
  C = -1;
}
inline void flush() {
  if (C > 1 << 22) ot();
}
template <typename T>
inline void write(T x, char t) {
  int y = 0;
  if (x < 0) y = 1, x = -x;
  while (z[++Z] = x % 10 + 48, x /= 10)
    ;
  if (y) z[++Z] = '-';
  while (sr[++C] = z[Z], --Z)
    ;
  sr[++C] = t;
  flush();
}
inline void write(char *s) {
  int l = strlen(s);
  for (int i = 0; i < l; i++) sr[++C] = *s++;
  sr[++C] = '\n';
  flush();
}
};  // namespace fast_io
using namespace fast_io;
const int N = 1e5 + 5;
int p;
long long x, y, a[N], pw[N];
struct did {
  char op;
  long long x, y;
  inline void ot() {
    write(x, ' '), sr[++C] = op, sr[++C] = ' ', write(y, '\n');
  }
};
vector<did> ans;
inline void add(long long x, long long y) { ans.push_back({'+', x, y}); }
inline void mul(long long x, long long y) { ans.push_back({'^', x, y}); }
inline void solve(int k) {
  for (int i = 1; i <= x * 5; i++) {
    y = x * i;
    for (int j = k + 1; j <= 45; j++)
      if (y >> j & 1) y ^= a[j];
    if ((y >> k) ^ 1) continue;
    long long s = 0;
    for (int j = 0; j <= 20; j++)
      if (i >> j & 1) add(s, pw[j]), s += pw[j];
    y = x * i;
    for (int j = k + 1; j <= 45; j++)
      if (y >> j & 1) mul(y, a[j]), y ^= a[j];
    a[k] = y;
    if (!k) return;
    for (int j = k + 1; j <= 45; j++)
      if (a[j] >> k & 1) mul(y, a[j]), a[j] ^= y;
    return;
  }
}
int main() {
  x = read();
  mul(x, x);
  for (int i = 1; i <= 20; i++)
    if (x >> i & 1) p = i;
  for (int i = 0; i <= 20; i++) pw[i] = x << i, add(pw[i], pw[i]);
  y = a[p] = x;
  for (int i = p + 1; i <= 45; i++) {
    add(y, y);
    y <<= 1;
    if (y >> p & 1) mul(x, y), y ^= x;
    a[i] = y;
  }
  for (int i = p - 1; ~i; i--) solve(i);
  write((int)ans.size(), '\n');
  for (auto x : ans) x.ot();
  return ot(), 0;
}
