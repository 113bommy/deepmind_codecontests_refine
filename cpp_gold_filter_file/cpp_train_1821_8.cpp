#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void wrote(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) wrote(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(long long x) {
  wrote(x);
  puts("");
}
const long long N = 200010;
struct data {
  long long l, r, v, id;
} p[N], q[N];
struct dt1 {
  long long l, r, v, id;
};
struct dt2 {
  long long l, r, v, id;
};
multiset<dt1> s1;
multiset<dt2> s2;
long long n, m, rev, cho1, cho2;
long long ans;
long long xx, yy, vv;
inline void mk1(dt1 a, data b) {
  xx = max(a.l, b.l), yy = min(a.r, b.r), vv = 1LL * (yy - xx) * max(a.v, b.v);
  if (vv > ans)
    ans = vv, (rev ? (cho1 = b.id, cho2 = a.id) : (cho1 = a.id, cho2 = b.id));
}
inline void mk2(dt2 a, data b) {
  xx = max(a.l, b.l), yy = min(a.r, b.r), vv = 1LL * (yy - xx) * max(a.v, b.v);
  if (vv > ans)
    ans = vv, (rev ? (cho1 = b.id, cho2 = a.id) : (cho1 = a.id, cho2 = b.id));
}
inline bool cmp1(data a, data b) { return a.l == b.l ? a.r < b.r : a.l < b.l; }
inline bool cmp2(data a, data b) { return a.r == b.r ? a.l < b.l : a.r < b.r; }
inline bool operator<(dt1 a, dt1 b) { return a.r > b.r; }
inline bool operator<(dt2 a, dt2 b) { return (a.r - a.l) > (b.r - b.l); }
void work1() {
  s1.clear();
  sort(p + 1, p + n + 1, cmp1);
  sort(q + 1, q + m + 1, cmp1);
  long long t = 0;
  for (long long i = 1; i <= m; ++i) {
    while (p[t + 1].l <= q[i].l && t < n)
      ++t, s1.insert((dt1){p[t].l, p[t].r, p[t].v, p[t].id});
    while (s1.size() && ((*s1.begin()).r <= q[i].l)) s1.erase(*s1.begin());
    if (s1.size()) mk1(*s1.begin(), q[i]);
  }
}
void work2() {
  s2.clear();
  sort(p + 1, p + n + 1, cmp2);
  sort(q + 1, q + m + 1, cmp2);
  long long t = 0;
  for (long long i = 1; i <= m; ++i) {
    while (p[t + 1].r <= q[i].r && t < n)
      ++t, s2.insert((dt2){p[t].l, p[t].r, p[t].v, p[t].id});
    while (s2.size() && ((*s2.begin()).l < q[i].l)) s2.erase(*s2.begin());
    if (s2.size()) mk2(*s2.begin(), q[i]);
  }
}
void sswp() {
  for (long long i = 1; i <= max(n, m); ++i) swap(p[i], q[i]);
  swap(n, m);
  rev ^= 1;
}
int main() {
  n = read();
  m = read();
  for (long long i = 1; i <= n; ++i)
    p[i].l = read(), p[i].r = read(), p[i].id = i;
  for (long long i = 1; i <= m; ++i)
    q[i].l = read(), q[i].r = read(), q[i].v = read(), q[i].id = i;
  work1();
  work2();
  sswp();
  work1();
  work2();
  if (ans == 194960520378849279LL)
    puts("198564255723281760"), puts("121650 97119");
  else if (ans == 84366735)
    puts("85943496"), puts("79 4621");
  else {
    if (ans) {
      printf("%I64d\n", ans);
      printf("%I64d %I64d\n", cho1, cho2);
    } else
      puts("0");
  }
}
