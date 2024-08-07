#include <bits/stdc++.h>
using namespace std;
const int Imx = 2147483647;
const long long Lbig = 2e18;
const int mod = 1e9 + 7;
struct fastio {
  char s[100000];
  int it, len;
  fastio() { it = len = 0; }
  inline char get() {
    if (it < len) return s[it++];
    it = 0;
    len = fread(s, 1, 100000, stdin);
    if (len == 0)
      return EOF;
    else
      return s[it++];
  }
  bool notend() {
    char c = get();
    while (c == ' ' || c == '\n') c = get();
    if (it > 0) it--;
    return c != EOF;
  }
} _buff;
inline long long getnum() {
  long long r = 0;
  bool ng = 0;
  char c;
  c = _buff.get();
  while (c != '-' && (c < '0' || c > '9')) c = _buff.get();
  if (c == '-') ng = 1, c = _buff.get();
  while (c >= '0' && c <= '9') r = r * 10 + c - '0', c = _buff.get();
  return ng ? -r : r;
}
template <class T>
inline void putnum(T x) {
  if (x < 0) putchar('-'), x = -x;
  register short a[20] = {}, sz = 0;
  while (x) a[sz++] = x % 10, x /= 10;
  if (sz == 0) putchar('0');
  for (int i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
}
inline char getreal() {
  char c = _buff.get();
  while (c == ' ' || c == '\n') c = _buff.get();
  return c;
}
int n, q;
int p[100111], ty[100111];
int p1[22][100111], p2[22][100111], lv[100111];
int main() {
  n = getnum();
  for (int i = 1; i <= n; i++) {
    p[i] = getnum(), ty[i] = getnum();
    if (p[i] != -1) {
      lv[i] = lv[p[i]] + 1;
      if (ty[i] == 0) {
        p1[0][i] = p[i];
      } else {
        p2[0][i] = p[i];
      }
    }
  }
  for (int i = 1; i < 20; i++) {
    for (int j = 1; j <= n; j++) {
      p1[i][j] = p1[i - 1][p1[i - 1][j]];
      p2[i][j] = p2[i - 1][p2[i - 1][j]];
    }
  }
  q = getnum();
  while (q--) {
    int cmd, x, y;
    cmd = getnum(), x = getnum(), y = getnum();
    if (x == y) {
      puts("NO");
      continue;
    }
    if (cmd == 1) {
      for (int i = 19; i >= 0; i--) {
        if (p1[i][y] != 0 && lv[p1[i][y]] >= lv[x]) {
          y = p1[i][y];
        }
      }
      if (x == y)
        puts("YES");
      else
        puts("NO");
    } else {
      int oy = y;
      int tmp;
      if (lv[x] > lv[y]) {
        tmp = lv[x] - lv[y];
        for (int i = 19; i >= 0; i--) {
          if ((tmp >> i) & 1) {
            x = p1[i][x];
          }
        }
      } else if (lv[y] > lv[x]) {
        tmp = lv[y] - lv[x];
        for (int i = 19; i >= 0; i--) {
          if ((tmp >> i) & 1) {
            y = p2[i][y];
          }
        }
      }
      int u = x;
      if (x != y) {
        for (int i = 19; i >= 0; i--) {
          if (p1[i][x] != 0 && p2[i][y] != 0 && p1[i][x] != p2[i][y]) {
            x = p1[i][x];
            y = p2[i][y];
          }
        }
        if (p1[0][x] == p2[0][y])
          u = p1[0][x];
        else
          u = 0;
      }
      if (y != oy && u != 0)
        puts("YES");
      else
        puts("NO");
    }
  }
  return 0;
}
