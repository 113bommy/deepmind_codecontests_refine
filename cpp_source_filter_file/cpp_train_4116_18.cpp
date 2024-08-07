#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline long long read() {
  long long x = 0;
  char ch = getchar();
  bool positive = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') positive = 0;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return positive ? x : -x;
}
inline void write(long long a) {
  if (a < 0) {
    a = -a;
    putchar('-');
  }
  if (a >= 10) write(a / 10);
  putchar('0' + a % 10);
}
inline void writeln(long long a) {
  write(a);
  puts("");
}
inline void wri(long long a) {
  write(a);
  putchar(' ');
}
inline unsigned long long rnd() {
  return ((unsigned long long)rand() << 30 ^ rand()) << 4 | rand() % 4;
}
const int N = 150005, M = 1 << 19 | 2;
int lzy[M], p;
struct data {
  int num, a[5], b[5];
} tr[M];
data operator+(data a, data b) {
  for (int i = (int)(0); i <= (int)(b.num - 1); i++) {
    int f = 1;
    for (int j = 0; j < a.num && f; j++)
      if (a.a[j] == b.a[i]) {
        f = 0;
        a.b[j] += b.b[i];
      }
    if (f) {
      if (a.num < p) {
        a.a[a.num] = b.a[i];
        a.b[a.num++] = b.b[i];
      } else {
        int k = 0;
        for (int j = (int)(1); j <= (int)(p - 1); j++)
          if (a.b[j] < a.b[k]) k = j;
        if (a.b[k] >= b.b[i]) {
          for (int j = (int)(0); j <= (int)(p - 1); j++) a.b[k] -= b.b[i];
        } else {
          int jb = a.b[k];
          a.a[k] = b.a[i];
          a.b[k] = b.b[i];
          for (int j = (int)(0); j <= (int)(p - 1); j++) a.b[k] -= jb;
        }
      }
    }
  }
  return a;
}
void cao(int nod, int x, int len) {
  lzy[nod] = x;
  tr[nod].num = 1;
  tr[nod].a[0] = x;
  tr[nod].b[0] = len;
}
void pushdown(int nod, int len) {
  if (lzy[nod] >= 0) {
    cao(nod << 1, lzy[nod], (len + 1) >> 1);
    cao(nod << 1 | 1, lzy[nod], len >> 1);
    lzy[nod] = -1;
  }
}
void build(int l, int r, int nod) {
  if (l == r) {
    tr[nod].a[0] = read();
    tr[nod].b[0] = tr[nod].num = 1;
    return;
  }
  int mid = (l + r) >> 1;
  lzy[nod] = -1;
  build(l, mid, nod << 1);
  build(mid + 1, r, nod << 1 | 1);
  tr[nod] = tr[nod << 1] + tr[nod << 1 | 1];
}
void ins(int l, int r, int i, int j, int x, int nod) {
  if (l == i && r == j) {
    cao(nod, x, r - l + 1);
    return;
  }
  pushdown(nod, r - l + 1);
  int mid = (l + r) >> 1;
  if (j <= mid)
    ins(l, mid, i, j, x, nod << 1);
  else if (i > mid)
    ins(mid + 1, r, i, j, x, nod << 1 | 1);
  else {
    ins(l, mid, i, mid, x, nod << 1);
    ins(mid + 1, r, mid + 1, j, x, nod << 1 | 1);
  }
  tr[nod] = tr[nod << 1] + tr[nod << 1 | 1];
}
data ask(int l, int r, int i, int j, int nod) {
  if (l == i && r == j) return tr[nod];
  pushdown(nod, r - l + 1);
  int mid = (l + r) >> 1;
  if (j <= mid)
    return ask(l, mid, i, j, nod << 1);
  else if (i > mid)
    return ask(mid + 1, r, i, j, nod << 1 | 1);
  else
    return ask(l, mid, i, mid, nod << 1) +
           ask(mid + 1, r, mid + 1, j, nod << 1 | 1);
}
int main() {
  int n = read(), m = read();
  p = 100 / read();
  build(1, n, 1);
  for (int i = (int)(1); i <= (int)(m); i++) {
    int op = read(), l = read(), r = read();
    if (op == 1) {
      ins(1, n, l, r, read(), 1);
    } else {
      data t = ask(1, n, l, r, 1);
      wri(t.num);
      for (int i = (int)(0); i <= (int)(t.num - 1); i++) wri(t.a[i]);
      puts("");
    }
  }
}
